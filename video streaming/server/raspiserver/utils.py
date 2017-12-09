#!/usr/bin/env python
# coding:utf-8
# author TL

""" utils for RaspiCam """

from os.path import exists, isfile
import netifaces
from ConfigParser import Error as ConfigError
from ConfigParser import ConfigParser
from threading import Lock
from raspiserver.logger import APPLOGGER
from json import dumps

def get_local_ip():
    """ get local ip address """
    #ipaddr = netifaces.ifaddresses('eth0')[netifaces.AF_INET][0]['addr']
    ipaddr = netifaces.ifaddresses('wlan0')[netifaces.AF_INET][0]['addr']
    if ipaddr is '':
        raise AppException('ip address is null')
    return ipaddr

class AppException(Exception):
    """ AppException """
    def __init__(self, value):
        self.value = value
        Exception.__init__(self)

    def __str__(self):
        return repr(self.value)

class Singleton(type):
    """ Singleton """
    _instances = {}
    def __call__(cls, *args, **kwargs):
        if cls not in cls._instances:
            cls._instances[cls] = \
                    super(Singleton, cls).__call__(*args, **kwargs)
        return cls._instances[cls]

class SingletonMixin(object):
    """ Singleton thread safe """
    __singleton_lock = Lock()
    __singleton_instance = None

    @classmethod
    def instance(cls):
        """ get instance """
        if not cls.__singleton_instance:
            with cls.__singleton_lock:
                if not cls.__singleton_instance:
                    cls.__singleton_instance = cls()
        return cls.__singleton_instance

class VideoCfg(object):
    """ video cfg """
    __metaclass__ = Singleton
    def __init__(self):
        self.width = -1
        self.height = -1
        self.fps = -1
        self.bitrate = -1
        self.brightness = -1
        self.rtsp_port = 0    #eh... not very well

class RecordCfg(object):
    """ record cfg """
    def __init__(self):
        self.base = ''
        self.cycle = None
        self.fsp_limit = -1

class ServeCfg(object):
    """ server config """
    def __init__(self):
        self.tcp_port = 0
        self.http_port = 0
        self.vod_port = 0
        self.address = ''    # not read from cfg file

class ConfigObject(object):
    """ config object """
    __metaclass__ = Singleton
    def __init__(self):
        # video paramters
        self.video = VideoCfg()
        # record parameters
        self.record = RecordCfg()
        self.comm_port = ServeCfg()

class ConfigReader(object):
    """ config file reader """
    def __init__(self, path):
        self.__config = ConfigObject()
        self.__path = path
    def parser(self):
        """ parser func """
        try:
            if exists(self.__path) and isfile(self.__path):
                with open(self.__path) as fhandler:
                    try:
                        config_parser = ConfigParser()
                        config_parser.readfp(fhandler)
                        if config_parser.has_option('video', 'width'):
                            self.__config.video.width = \
                                    config_parser.getint('video', 'width')
                        if config_parser.has_option('video', 'height'):
                            self.__config.video.height = \
                                    config_parser.getint('video', 'height')
                        if config_parser.has_option('video', 'fps'):
                            self.__config.video.fps = \
                                    config_parser.getint('video', 'fps')
                        if config_parser.has_option('video', 'bitrate'):
                            self.__config.video.bitrate = \
                                    config_parser.getint('video', 'bitrate')
                        if config_parser.has_option('video', 'brightness'):
                            self.__config.video.brightness = \
                                    config_parser.getint('video', 'brightness')
                        if config_parser.has_option('video', 'rtsp_port'):
                            self.__config.video.rtsp_port = \
                                    config_parser.getint('video', 'rtsp_port')
                        if config_parser.has_option('record', 'base'):
                            self.__config.record.base = \
                                    config_parser.get('record', 'base')
                        if config_parser.has_option('record', 'cycle'):
                            self.__config.record.cycle = \
                                    config_parser.getboolean('record', 'cycle')
                        if config_parser.has_option('record', 'limit'):
                            self.__config.record.fsp_limit = \
                                    config_parser.getint('record', 'limit')
                        if config_parser.has_option('common', 'tcp_port'):
                            self.__config.comm_port.tcp_port = \
                                    config_parser.getint('common', 'tcp_port')
                        if config_parser.has_option('common', 'http_port'):
                            self.__config.comm_port.http_port = \
                                    config_parser.getint('common', 'http_port')
                        if config_parser.has_option('common', 'vod_port'):
                            self.__config.comm_port.vod_port = \
                                    config_parser.getint('common', 'vod_port')

                        # assign default values if value is invalid
                        if not self.__config.comm_port.http_port:
                            self.__config.comm_port.http_port = 8080
                        if not self.__config.comm_port.tcp_port:
                            self.__config.comm_port.tcp_port = 9999
                        if not self.__config.comm_port.vod_port:
                            self.__config.comm_port.vod_port = 9001
                        self.__config.comm_port.address = get_local_ip()

                    except (AppException, ConfigError) as ex:
                        APPLOGGER.error(ex)
            else:
                raise AppException('config file error')
        except OSError as ex:
            APPLOGGER.error(ex)
        return self.__config

    @property
    def config(self):
        """ config object """
        return self.__config
    def __get_path(self):
        """ get path """
        return self.__path
    def __set_path(self, value):
        """ set path """
        self.__path = value
    path = property(__get_path, __set_path)

def any2json_fstr(flist):
    """ file list to json for http response """
    return dumps(flist)

