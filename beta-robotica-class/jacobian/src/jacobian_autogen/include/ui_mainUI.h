/********************************************************************************
** Form generated from reading UI file 'mainUI.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINUI_H
#define UI_MAINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_guiDlg
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_left;
    QPushButton *pushButton_right;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_up;
    QPushButton *pushButton_down;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_front;
    QPushButton *pushButton_back;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_rot_left;
    QPushButton *pushButton_rot_right;
    QPushButton *pushButton_home;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label;

    void setupUi(QWidget *guiDlg)
    {
        if (guiDlg->objectName().isEmpty())
            guiDlg->setObjectName(QStringLiteral("guiDlg"));
        guiDlg->resize(314, 311);
        verticalLayout_3 = new QVBoxLayout(guiDlg);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_left = new QPushButton(guiDlg);
        pushButton_left->setObjectName(QStringLiteral("pushButton_left"));

        horizontalLayout->addWidget(pushButton_left);

        pushButton_right = new QPushButton(guiDlg);
        pushButton_right->setObjectName(QStringLiteral("pushButton_right"));

        horizontalLayout->addWidget(pushButton_right);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_up = new QPushButton(guiDlg);
        pushButton_up->setObjectName(QStringLiteral("pushButton_up"));

        horizontalLayout_2->addWidget(pushButton_up);

        pushButton_down = new QPushButton(guiDlg);
        pushButton_down->setObjectName(QStringLiteral("pushButton_down"));

        horizontalLayout_2->addWidget(pushButton_down);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_front = new QPushButton(guiDlg);
        pushButton_front->setObjectName(QStringLiteral("pushButton_front"));

        horizontalLayout_3->addWidget(pushButton_front);

        pushButton_back = new QPushButton(guiDlg);
        pushButton_back->setObjectName(QStringLiteral("pushButton_back"));

        horizontalLayout_3->addWidget(pushButton_back);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_rot_left = new QPushButton(guiDlg);
        pushButton_rot_left->setObjectName(QStringLiteral("pushButton_rot_left"));

        horizontalLayout_5->addWidget(pushButton_rot_left);

        pushButton_rot_right = new QPushButton(guiDlg);
        pushButton_rot_right->setObjectName(QStringLiteral("pushButton_rot_right"));

        horizontalLayout_5->addWidget(pushButton_rot_right);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton_home = new QPushButton(guiDlg);
        pushButton_home->setObjectName(QStringLiteral("pushButton_home"));

        verticalLayout_2->addWidget(pushButton_home);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        doubleSpinBox = new QDoubleSpinBox(guiDlg);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));

        horizontalLayout_4->addWidget(doubleSpinBox);

        label = new QLabel(guiDlg);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(guiDlg);

        QMetaObject::connectSlotsByName(guiDlg);
    } // setupUi

    void retranslateUi(QWidget *guiDlg)
    {
        guiDlg->setWindowTitle(QApplication::translate("guiDlg", "Arm Inverse Controller", Q_NULLPTR));
        pushButton_left->setText(QApplication::translate("guiDlg", "left", Q_NULLPTR));
        pushButton_right->setText(QApplication::translate("guiDlg", "right", Q_NULLPTR));
        pushButton_up->setText(QApplication::translate("guiDlg", "up", Q_NULLPTR));
        pushButton_down->setText(QApplication::translate("guiDlg", "down", Q_NULLPTR));
        pushButton_front->setText(QApplication::translate("guiDlg", "front", Q_NULLPTR));
        pushButton_back->setText(QApplication::translate("guiDlg", "back", Q_NULLPTR));
        pushButton_rot_left->setText(QApplication::translate("guiDlg", "rot left", Q_NULLPTR));
        pushButton_rot_right->setText(QApplication::translate("guiDlg", "rot right", Q_NULLPTR));
        pushButton_home->setText(QApplication::translate("guiDlg", "home", Q_NULLPTR));
        label->setText(QApplication::translate("guiDlg", "  speed", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class guiDlg: public Ui_guiDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINUI_H
