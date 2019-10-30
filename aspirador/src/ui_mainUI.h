/********************************************************************************
** Form generated from reading UI file 'mainUI.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINUI_H
#define UI_MAINUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_guiDlg
{
public:
    QPushButton *pushButton;
    QLCDNumber *lcdNumber;
    QLabel *label;

    void setupUi(QWidget *guiDlg)
    {
        if (guiDlg->objectName().isEmpty())
            guiDlg->setObjectName(QString::fromUtf8("guiDlg"));
        guiDlg->resize(312, 298);
        pushButton = new QPushButton(guiDlg);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 250, 191, 41));
        lcdNumber = new QLCDNumber(guiDlg);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(40, 30, 231, 171));
        lcdNumber->setSmallDecimalPoint(true);
        label = new QLabel(guiDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 210, 66, 17));

        retranslateUi(guiDlg);

        QMetaObject::connectSlotsByName(guiDlg);
    } // setupUi

    void retranslateUi(QWidget *guiDlg)
    {
        guiDlg->setWindowTitle(QApplication::translate("guiDlg", "aspirador", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("guiDlg", "Reset", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("guiDlg", "% SWEPT", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class guiDlg: public Ui_guiDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINUI_H
