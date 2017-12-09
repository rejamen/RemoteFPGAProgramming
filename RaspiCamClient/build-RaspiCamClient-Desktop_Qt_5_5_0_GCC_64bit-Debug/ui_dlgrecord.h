/********************************************************************************
** Form generated from reading UI file 'dlgrecord.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGRECORD_H
#define UI_DLGRECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgRecord
{
public:
    QDialogButtonBox *btn_acc_reject;
    QTableWidget *tbl_records;
    QPushButton *btn_refresh;
    QWidget *videow;
    QSlider *video_silder;

    void setupUi(QDialog *DlgRecord)
    {
        if (DlgRecord->objectName().isEmpty())
            DlgRecord->setObjectName(QStringLiteral("DlgRecord"));
        DlgRecord->resize(798, 603);
        btn_acc_reject = new QDialogButtonBox(DlgRecord);
        btn_acc_reject->setObjectName(QStringLiteral("btn_acc_reject"));
        btn_acc_reject->setGeometry(QRect(430, 560, 341, 32));
        btn_acc_reject->setOrientation(Qt::Horizontal);
        btn_acc_reject->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tbl_records = new QTableWidget(DlgRecord);
        tbl_records->setObjectName(QStringLiteral("tbl_records"));
        tbl_records->setGeometry(QRect(10, 420, 651, 141));
        btn_refresh = new QPushButton(DlgRecord);
        btn_refresh->setObjectName(QStringLiteral("btn_refresh"));
        btn_refresh->setGeometry(QRect(690, 20, 101, 27));
        videow = new QWidget(DlgRecord);
        videow->setObjectName(QStringLiteral("videow"));
        videow->setGeometry(QRect(10, 20, 651, 371));
        video_silder = new QSlider(DlgRecord);
        video_silder->setObjectName(QStringLiteral("video_silder"));
        video_silder->setGeometry(QRect(10, 390, 651, 29));
        video_silder->setOrientation(Qt::Horizontal);

        retranslateUi(DlgRecord);
        QObject::connect(btn_acc_reject, SIGNAL(accepted()), DlgRecord, SLOT(accept()));
        QObject::connect(btn_acc_reject, SIGNAL(rejected()), DlgRecord, SLOT(reject()));

        QMetaObject::connectSlotsByName(DlgRecord);
    } // setupUi

    void retranslateUi(QDialog *DlgRecord)
    {
        DlgRecord->setWindowTitle(QApplication::translate("DlgRecord", "Dialog", 0));
        btn_refresh->setText(QApplication::translate("DlgRecord", "Refresh", 0));
    } // retranslateUi

};

namespace Ui {
    class DlgRecord: public Ui_DlgRecord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGRECORD_H
