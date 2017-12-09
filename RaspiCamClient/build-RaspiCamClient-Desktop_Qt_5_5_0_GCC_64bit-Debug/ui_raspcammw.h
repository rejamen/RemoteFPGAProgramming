/********************************************************************************
** Form generated from reading UI file 'raspcammw.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RASPCAMMW_H
#define UI_RASPCAMMW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RaspCamMW
{
public:
    QWidget *centralWidget;
    QWidget *videow;
    QLabel *lbl_address;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *gp_Controls;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QPushButton *btnSnap;
    QPushButton *btnStop;
    QPushButton *btnRecord;
    QPushButton *btnStart;
    QPushButton *btnScan;
    QLabel *lblprocess;
    QProgressBar *progressBar;
    QWidget *tab_2;
    QPushButton *btnConect;
    QPushButton *btnProgram;
    QPushButton *btnBitFile;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RaspCamMW)
    {
        if (RaspCamMW->objectName().isEmpty())
            RaspCamMW->setObjectName(QStringLiteral("RaspCamMW"));
        RaspCamMW->setWindowModality(Qt::ApplicationModal);
        RaspCamMW->resize(921, 454);
        centralWidget = new QWidget(RaspCamMW);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        videow = new QWidget(centralWidget);
        videow->setObjectName(QStringLiteral("videow"));
        videow->setGeometry(QRect(10, 20, 640, 360));
        lbl_address = new QLabel(centralWidget);
        lbl_address->setObjectName(QStringLiteral("lbl_address"));
        lbl_address->setGeometry(QRect(20, 0, 301, 21));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(670, 20, 231, 361));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gp_Controls = new QGroupBox(tab);
        gp_Controls->setObjectName(QStringLiteral("gp_Controls"));
        gp_Controls->setGeometry(QRect(8, 70, 220, 151));
        layoutWidget = new QWidget(gp_Controls);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 199, 95));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        btnSnap = new QPushButton(layoutWidget);
        btnSnap->setObjectName(QStringLiteral("btnSnap"));
        QIcon icon;
        icon.addFile(QStringLiteral("pics/snapshot.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSnap->setIcon(icon);

        gridLayout_2->addWidget(btnSnap, 1, 1, 1, 1);

        btnStop = new QPushButton(layoutWidget);
        btnStop->setObjectName(QStringLiteral("btnStop"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("pics/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnStop->setIcon(icon1);

        gridLayout_2->addWidget(btnStop, 0, 1, 1, 1);

        btnRecord = new QPushButton(layoutWidget);
        btnRecord->setObjectName(QStringLiteral("btnRecord"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("pics/record.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRecord->setIcon(icon2);

        gridLayout_2->addWidget(btnRecord, 1, 0, 1, 1);

        btnStart = new QPushButton(layoutWidget);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("pics/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QStringLiteral("pics/play.png"), QSize(), QIcon::Normal, QIcon::On);
        icon3.addFile(QStringLiteral("pics/play.png"), QSize(), QIcon::Disabled, QIcon::Off);
        icon3.addFile(QStringLiteral("pics/play.png"), QSize(), QIcon::Disabled, QIcon::On);
        icon3.addFile(QStringLiteral("pics/play.png"), QSize(), QIcon::Active, QIcon::Off);
        icon3.addFile(QStringLiteral("pics/play.png"), QSize(), QIcon::Active, QIcon::On);
        icon3.addFile(QStringLiteral("pics/play.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon3.addFile(QStringLiteral("pics/play.png"), QSize(), QIcon::Selected, QIcon::On);
        btnStart->setIcon(icon3);

        gridLayout_2->addWidget(btnStart, 0, 0, 1, 1);

        btnScan = new QPushButton(tab);
        btnScan->setObjectName(QStringLiteral("btnScan"));
        btnScan->setGeometry(QRect(20, 20, 191, 40));
        lblprocess = new QLabel(tab);
        lblprocess->setObjectName(QStringLiteral("lblprocess"));
        lblprocess->setGeometry(QRect(20, 300, 191, 17));
        progressBar = new QProgressBar(tab);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(20, 220, 191, 23));
        progressBar->setValue(24);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        btnConect = new QPushButton(tab_2);
        btnConect->setObjectName(QStringLiteral("btnConect"));
        btnConect->setGeometry(QRect(20, 50, 100, 30));
        btnProgram = new QPushButton(tab_2);
        btnProgram->setObjectName(QStringLiteral("btnProgram"));
        btnProgram->setGeometry(QRect(20, 90, 190, 50));
        btnBitFile = new QPushButton(tab_2);
        btnBitFile->setObjectName(QStringLiteral("btnBitFile"));
        btnBitFile->setGeometry(QRect(130, 50, 80, 30));
        tabWidget->addTab(tab_2, QString());
        RaspCamMW->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RaspCamMW);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 921, 25));
        RaspCamMW->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RaspCamMW);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RaspCamMW->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RaspCamMW);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RaspCamMW->setStatusBar(statusBar);

        retranslateUi(RaspCamMW);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RaspCamMW);
    } // setupUi

    void retranslateUi(QMainWindow *RaspCamMW)
    {
        RaspCamMW->setWindowTitle(QApplication::translate("RaspCamMW", "Programacion Remota Kit Nexys 2 Digilent", 0));
        lbl_address->setText(QApplication::translate("RaspCamMW", "Servidor:", 0));
        gp_Controls->setTitle(QApplication::translate("RaspCamMW", "Controles", 0));
        btnSnap->setText(QApplication::translate("RaspCamMW", "Capturar", 0));
        btnStop->setText(QApplication::translate("RaspCamMW", "Stop", 0));
        btnRecord->setText(QApplication::translate("RaspCamMW", "REC", 0));
        btnStart->setText(QApplication::translate("RaspCamMW", "Play", 0));
        btnScan->setText(QApplication::translate("RaspCamMW", "Video streaming", 0));
        lblprocess->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("RaspCamMW", "Video", 0));
        btnConect->setText(QApplication::translate("RaspCamMW", "Conectar", 0));
        btnProgram->setText(QApplication::translate("RaspCamMW", "Programar", 0));
        btnBitFile->setText(QApplication::translate("RaspCamMW", ".bit", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("RaspCamMW", "Kit Nexys2", 0));
    } // retranslateUi

};

namespace Ui {
    class RaspCamMW: public Ui_RaspCamMW {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RASPCAMMW_H
