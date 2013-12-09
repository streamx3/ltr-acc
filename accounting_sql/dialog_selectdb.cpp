#include "dialog_selectdb.h"
#include "ui_dialog_selectdb.h"

Dialog_SelectDB::Dialog_SelectDB(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog_SelectDB)
{
	ui->setupUi(this);
	mp_db = 0;
}

Dialog_SelectDB::~Dialog_SelectDB()
{
	delete ui;
}

void Dialog_SelectDB::bindSettings(Settings *inc_settings){
	if(inc_settings != 0)
		p_settings = inc_settings;
}

void Dialog_SelectDB::on_buttonBox_rejected()
{
	close();
	qApp->exit();
}


void Dialog_SelectDB::on_buttonBox_accepted()
{
	if(mp_db != 0){
		mp_db->setHostName(ui->lineEdit_ip->text());
		mp_db->setDatabaseName(ui->lineEdit_db->text());
		mp_db->setUserName(ui->lineEdit_user->text());
		mp_db->setPassword(ui->lineEdit_password->text());
		if(mp_db->open() == true){
			call_main_window(true);
		}else{
			QMessageBox Msgbox;
			Msgbox.setIcon(QMessageBox::Critical);
			Msgbox.setWindowIcon(QIcon(QString(":/images/eye-16.png")));
			Msgbox.setWindowTitle(QString("ERROR"));
			Msgbox.setText("Error: Failed to access database!\nCheck settings.");
			Msgbox.exec();
		}
	}
}

void Dialog_SelectDB::bindDatabase(QSqlDatabase *p_db){
	if(p_db != 0)
		mp_db = p_db;
}
