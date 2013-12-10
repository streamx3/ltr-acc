/********************************************************************************
** Form generated from reading UI file 'dialog_edit.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_EDIT_H
#define UI_DIALOG_EDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Edit
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_phone;
    QTextEdit *textEdit_Remarks;
    QLineEdit *lineEdit_tracking_number;
    QDateTimeEdit *dateTimeEdit_paid;
    QDateTimeEdit *dateTimeEdit_order_date;
    QLabel *label_6;
    QDateTimeEdit *dateTimeEdit_sent;
    QLabel *label_10;
    QLabel *label_8;
    QCheckBox *checkBox_paid;
    QLabel *label;
    QSpinBox *spinBox_part1;
    QSpinBox *spinBox_NP_Dept_No;
    QLabel *label_7;
    QLineEdit *lineEdit_city;
    QLabel *label_4;
    QLineEdit *lineEdit_name;
    QLabel *label_5;
    QLabel *label_2;
    QSpinBox *spinBox_part2;
    QCheckBox *checkBox_sent;
    QLabel *label_3;
    QDialogButtonBox *buttonBox;
    QLabel *label_id;

    void setupUi(QDialog *Dialog_Edit)
    {
        if (Dialog_Edit->objectName().isEmpty())
            Dialog_Edit->setObjectName(QStringLiteral("Dialog_Edit"));
        Dialog_Edit->resize(404, 474);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog_Edit->sizePolicy().hasHeightForWidth());
        Dialog_Edit->setSizePolicy(sizePolicy);
        Dialog_Edit->setMaximumSize(QSize(410, 474));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/book-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog_Edit->setWindowIcon(icon);
        gridLayout = new QGridLayout(Dialog_Edit);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_phone = new QLineEdit(Dialog_Edit);
        lineEdit_phone->setObjectName(QStringLiteral("lineEdit_phone"));

        gridLayout->addWidget(lineEdit_phone, 0, 8, 1, 2);

        textEdit_Remarks = new QTextEdit(Dialog_Edit);
        textEdit_Remarks->setObjectName(QStringLiteral("textEdit_Remarks"));

        gridLayout->addWidget(textEdit_Remarks, 7, 2, 1, 8);

        lineEdit_tracking_number = new QLineEdit(Dialog_Edit);
        lineEdit_tracking_number->setObjectName(QStringLiteral("lineEdit_tracking_number"));

        gridLayout->addWidget(lineEdit_tracking_number, 6, 2, 1, 8);

        dateTimeEdit_paid = new QDateTimeEdit(Dialog_Edit);
        dateTimeEdit_paid->setObjectName(QStringLiteral("dateTimeEdit_paid"));

        gridLayout->addWidget(dateTimeEdit_paid, 4, 3, 1, 4);

        dateTimeEdit_order_date = new QDateTimeEdit(Dialog_Edit);
        dateTimeEdit_order_date->setObjectName(QStringLiteral("dateTimeEdit_order_date"));

        gridLayout->addWidget(dateTimeEdit_order_date, 0, 1, 1, 5);

        label_6 = new QLabel(Dialog_Edit);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        dateTimeEdit_sent = new QDateTimeEdit(Dialog_Edit);
        dateTimeEdit_sent->setObjectName(QStringLiteral("dateTimeEdit_sent"));

        gridLayout->addWidget(dateTimeEdit_sent, 5, 3, 1, 4);

        label_10 = new QLabel(Dialog_Edit);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 7, 0, 1, 1);

        label_8 = new QLabel(Dialog_Edit);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 6, 0, 1, 2);

        checkBox_paid = new QCheckBox(Dialog_Edit);
        checkBox_paid->setObjectName(QStringLiteral("checkBox_paid"));

        gridLayout->addWidget(checkBox_paid, 4, 0, 1, 3);

        label = new QLabel(Dialog_Edit);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        spinBox_part1 = new QSpinBox(Dialog_Edit);
        spinBox_part1->setObjectName(QStringLiteral("spinBox_part1"));

        gridLayout->addWidget(spinBox_part1, 3, 1, 1, 3);

        spinBox_NP_Dept_No = new QSpinBox(Dialog_Edit);
        spinBox_NP_Dept_No->setObjectName(QStringLiteral("spinBox_NP_Dept_No"));

        gridLayout->addWidget(spinBox_NP_Dept_No, 2, 9, 1, 1);

        label_7 = new QLabel(Dialog_Edit);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 3, 4, 1, 1);

        lineEdit_city = new QLineEdit(Dialog_Edit);
        lineEdit_city->setObjectName(QStringLiteral("lineEdit_city"));

        gridLayout->addWidget(lineEdit_city, 2, 1, 1, 6);

        label_4 = new QLabel(Dialog_Edit);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        lineEdit_name = new QLineEdit(Dialog_Edit);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));

        gridLayout->addWidget(lineEdit_name, 1, 1, 1, 9);

        label_5 = new QLabel(Dialog_Edit);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 2, 7, 1, 2);

        label_2 = new QLabel(Dialog_Edit);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spinBox_part2 = new QSpinBox(Dialog_Edit);
        spinBox_part2->setObjectName(QStringLiteral("spinBox_part2"));

        gridLayout->addWidget(spinBox_part2, 3, 5, 1, 3);

        checkBox_sent = new QCheckBox(Dialog_Edit);
        checkBox_sent->setObjectName(QStringLiteral("checkBox_sent"));

        gridLayout->addWidget(checkBox_sent, 5, 0, 1, 3);

        label_3 = new QLabel(Dialog_Edit);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 6, 1, 2);

        buttonBox = new QDialogButtonBox(Dialog_Edit);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 8, 2, 1, 8);

        label_id = new QLabel(Dialog_Edit);
        label_id->setObjectName(QStringLiteral("label_id"));
        QPalette palette;
        QBrush brush(QColor(128, 128, 128, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush1(QColor(190, 190, 190, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        label_id->setPalette(palette);

        gridLayout->addWidget(label_id, 8, 0, 1, 1);


        retranslateUi(Dialog_Edit);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_Edit, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_Edit, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_Edit);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Edit)
    {
        Dialog_Edit->setWindowTitle(QApplication::translate("Dialog_Edit", "Record edit", 0));
        dateTimeEdit_paid->setDisplayFormat(QApplication::translate("Dialog_Edit", "M/d/yy HH:mm", 0));
        dateTimeEdit_order_date->setDisplayFormat(QApplication::translate("Dialog_Edit", "M/d/yy HH:mm", 0));
        label_6->setText(QApplication::translate("Dialog_Edit", "Part 1", 0));
        dateTimeEdit_sent->setDisplayFormat(QApplication::translate("Dialog_Edit", "M/d/yy HH:mm", 0));
        label_10->setText(QApplication::translate("Dialog_Edit", "Remarks", 0));
        label_8->setText(QApplication::translate("Dialog_Edit", "Waybill N.", 0));
        checkBox_paid->setText(QApplication::translate("Dialog_Edit", "Paid", 0));
        label->setText(QApplication::translate("Dialog_Edit", "Date", 0));
        label_7->setText(QApplication::translate("Dialog_Edit", "Part 2", 0));
        label_4->setText(QApplication::translate("Dialog_Edit", "City", 0));
        label_5->setText(QApplication::translate("Dialog_Edit", "Department \342\204\226", 0));
        label_2->setText(QApplication::translate("Dialog_Edit", "Nane", 0));
        checkBox_sent->setText(QApplication::translate("Dialog_Edit", "Sent", 0));
        label_3->setText(QApplication::translate("Dialog_Edit", "Phone", 0));
        label_id->setText(QApplication::translate("Dialog_Edit", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Edit: public Ui_Dialog_Edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_EDIT_H
