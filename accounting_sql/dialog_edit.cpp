#include "dialog_edit.h"
#include "ui_dialog_edit.h"

Dialog_Edit::Dialog_Edit(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog_Edit)
{
	ui->setupUi(this);
	p_settings = 0;
	mp_acc_rec_inoming = 0;
	m_enable_sending = false;
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
		ui->lineEdit_tracking_number->setText("N/A");
		ui->label_id->setText(mp_acc_rec_inoming->id > 0 ? QString::number(mp_acc_rec_inoming->id) : "New record");

		ui->spinBox_part1->setValue(mp_acc_rec_inoming->order_1);
		ui->spinBox_part2->setValue(mp_acc_rec_inoming->order_2);
		ui->spinBox_NP_Dept_No->setValue(mp_acc_rec_inoming->np_dept);

		m_enable_sending = mp_acc_rec_inoming->sent == Qt::Checked;
		ui->checkBox_sent->setEnabled(m_enable_sending);
		ui->dateTimeEdit_sent->setEnabled(m_enable_sending);
		show();
	}
}

void Dialog_Edit::on_buttonBox_accepted()
{
	pullInput2sh_rec();
	request_recort_push(true);
}

void Dialog_Edit::pullInput2sh_rec(){
	if(mp_acc_rec_inoming != 0){
		//id
		//Assuming id can not be changed by user
		//order_date
		mp_acc_rec_inoming->order_date  = ui->dateTimeEdit_order_date->dateTime();
		//name
		mp_acc_rec_inoming->name        = ui->lineEdit_name->text();
		//phone
		mp_acc_rec_inoming->phone       = ui->lineEdit_phone->text();
		//city
		mp_acc_rec_inoming->city        = ui->lineEdit_city->text();
		//NP DeptNumber
		mp_acc_rec_inoming->np_dept     = ui->spinBox_NP_Dept_No->value();
		//order_1
		mp_acc_rec_inoming->order_1     = ui->spinBox_part1->value();
		//order_2
		mp_acc_rec_inoming->order_2     = ui->spinBox_part2->value();
		//paid
		mp_acc_rec_inoming->paid        = ui->checkBox_paid->checkState();
		//paid time
		mp_acc_rec_inoming->paid_time   = ui->dateTimeEdit_paid->dateTime();
		//sent
		mp_acc_rec_inoming->sent        = ui->checkBox_sent->checkState();
		//sent time
		mp_acc_rec_inoming->sent_time   = ui->dateTimeEdit_sent->dateTime();
		//remarks
		mp_acc_rec_inoming->remarks     = ui->textEdit_Remarks->toPlainText();
	}
};

void Dialog_Edit::on_checkBox_paid_clicked()
{
	bool enable_sending = ui->checkBox_paid->checkState() == Qt::Checked;
	ui->checkBox_sent->setEnabled(enable_sending);
	ui->dateTimeEdit_sent->setEnabled(enable_sending);
}
