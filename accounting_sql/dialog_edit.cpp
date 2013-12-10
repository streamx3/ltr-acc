#include "dialog_edit.h"
#include "ui_dialog_edit.h"

Dialog_Edit::Dialog_Edit(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog_Edit)
{
	ui->setupUi(this);
	p_settings = 0;
	mp_acc_rec_inoming = 0;
}

Dialog_Edit::~Dialog_Edit()
{
	delete ui;
}

void Dialog_Edit::bindSettings(Settings *inc_settings){
	if(inc_settings != 0)
		p_settings = inc_settings;
}

void Dialog_Edit::bindRecStr(accounting_record *inc_str){
	if(inc_str != 0){
		mp_acc_rec_inoming = inc_str;
	}
}

void Dialog_Edit::show_me(bool flag){
	if(flag){
		ui->dateTimeEdit_order_date->setDateTime(mp_acc_rec_inoming->order_date);
		ui->dateTimeEdit_paid->setDateTime(mp_acc_rec_inoming->paid_time);
		ui->dateTimeEdit_sent->setDateTime(mp_acc_rec_inoming->sent_time);

		ui->checkBox_sent->setCheckState(mp_acc_rec_inoming->sent);
		ui->checkBox_paid->setCheckState(mp_acc_rec_inoming->paid);

		ui->lineEdit_phone->setText(mp_acc_rec_inoming->phone);
		ui->lineEdit_city->setText(mp_acc_rec_inoming->city);
		ui->lineEdit_name->setText(mp_acc_rec_inoming->name);
		show();
	}
}
