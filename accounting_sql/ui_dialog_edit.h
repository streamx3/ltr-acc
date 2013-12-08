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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Edit
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_10;
    QTextEdit *textEdit;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QLabel *label_7;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QSpinBox *spinBox_3;
    QDateTimeEdit *dateTimeEdit;
    QLineEdit *lineEdit_3;

    void setupUi(QDialog *Dialog_Edit)
    {
        if (Dialog_Edit->objectName().isEmpty())
            Dialog_Edit->setObjectName(QStringLiteral("Dialog_Edit"));
        Dialog_Edit->resize(400, 362);
        buttonBox = new QDialogButtonBox(Dialog_Edit);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 330, 381, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Discard|QDialogButtonBox::Save);
        label = new QLabel(Dialog_Edit);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 14, 41, 20));
        label_2 = new QLabel(Dialog_Edit);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 44, 41, 20));
        label_3 = new QLabel(Dialog_Edit);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(210, 15, 41, 20));
        label_4 = new QLabel(Dialog_Edit);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 74, 41, 20));
        label_5 = new QLabel(Dialog_Edit);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(240, 73, 91, 20));
        label_6 = new QLabel(Dialog_Edit);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 104, 41, 20));
        label_10 = new QLabel(Dialog_Edit);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 170, 51, 20));
        textEdit = new QTextEdit(Dialog_Edit);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(70, 170, 321, 151));
        spinBox = new QSpinBox(Dialog_Edit);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(60, 100, 52, 27));
        spinBox_2 = new QSpinBox(Dialog_Edit);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(180, 100, 52, 27));
        label_7 = new QLabel(Dialog_Edit);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(130, 104, 41, 20));
        checkBox = new QCheckBox(Dialog_Edit);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(10, 140, 101, 22));
        checkBox_2 = new QCheckBox(Dialog_Edit);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(130, 140, 101, 22));
        lineEdit = new QLineEdit(Dialog_Edit);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(60, 40, 331, 27));
        lineEdit_2 = new QLineEdit(Dialog_Edit);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(60, 70, 171, 27));
        spinBox_3 = new QSpinBox(Dialog_Edit);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setGeometry(QRect(340, 70, 52, 27));
        dateTimeEdit = new QDateTimeEdit(Dialog_Edit);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(60, 10, 141, 27));
        lineEdit_3 = new QLineEdit(Dialog_Edit);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(250, 10, 141, 27));

        retranslateUi(Dialog_Edit);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_Edit, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_Edit, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_Edit);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Edit)
    {
        Dialog_Edit->setWindowTitle(QApplication::translate("Dialog_Edit", "Dialog", 0));
        label->setText(QApplication::translate("Dialog_Edit", "Date", 0));
        label_2->setText(QApplication::translate("Dialog_Edit", "Nane", 0));
        label_3->setText(QApplication::translate("Dialog_Edit", "Phone", 0));
        label_4->setText(QApplication::translate("Dialog_Edit", "City", 0));
        label_5->setText(QApplication::translate("Dialog_Edit", "Department \342\204\226", 0));
        label_6->setText(QApplication::translate("Dialog_Edit", "Part 1", 0));
        label_10->setText(QApplication::translate("Dialog_Edit", "Remarks", 0));
        label_7->setText(QApplication::translate("Dialog_Edit", "Part 2", 0));
        checkBox->setText(QApplication::translate("Dialog_Edit", "Paid", 0));
        checkBox_2->setText(QApplication::translate("Dialog_Edit", "Sent", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Edit: public Ui_Dialog_Edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_EDIT_H
