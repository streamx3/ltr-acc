#include "dialog_selectdb.h"
#include "ui_dialog_selectdb.h"

Dialog_SelectDB::Dialog_SelectDB( QWidget *parent ) :
	QDialog( parent ),
	ui( new Ui::Dialog_SelectDB )
{
	ui->setupUi( this );
	mp_db = 0;
}

Dialog_SelectDB::~Dialog_SelectDB()
{
	delete ui;
}

void Dialog_SelectDB::bindSettings( Settings *inc_settings ){
	if( inc_settings != 0 )
		mp_settings = inc_settings;
}

void Dialog_SelectDB::on_buttonBox_rejected()
{
	close();
	qApp->exit();
}

void Dialog_SelectDB::on_buttonBox_accepted()
{
	if( mp_db != 0 && mp_settings != 0 ){
		mp_settings->setDB_Address(			ui->lineEdit_ip->text() );
		mp_settings->setDB_DBname(			ui->lineEdit_db->text() );
		mp_settings->setDB_Username(		ui->lineEdit_user->text() );
		mp_settings->setDB_Password(		ui->lineEdit_password->text() );
		mp_settings->setRememberPassword(	ui->checkBox_remember_password->checkState() == Qt::Checked );
		mp_db->setHostName(		mp_settings->getDB_Address() );
		mp_db->setDatabaseName(	mp_settings->getDB_DBname() );
		mp_db->setUserName(		mp_settings->getDB_Username() );
		mp_db->setPassword(		mp_settings->getDB_Password() );
		if( mp_db->open() == true ){
			mp_settings->writeConfigFile();
			call_main_window( true );
		}else{
			QMessageBox Msgbox;
			Msgbox.setIcon( QMessageBox::Critical );
			Msgbox.setWindowIcon( QIcon( QString( ":/images/eye-16.png" ) ) );
			Msgbox.setWindowTitle( QString( "ERROR" ) );
			Msgbox.setText( "Error: Failed to access database!\nCheck settings." );
			Msgbox.exec();
		}
	}
}

void Dialog_SelectDB::bindDatabase( QSqlDatabase *p_db ){
	if( p_db != 0 )
		mp_db = p_db;
}

void Dialog_SelectDB::show(){
	ui->lineEdit_db->setText(		mp_settings->getDB_DBname() );
	ui->lineEdit_ip->setText(		mp_settings->getDB_Address() );
	ui->lineEdit_password->setText(	mp_settings->getDB_Password() );
	ui->lineEdit_user->setText(		mp_settings->getDB_Username() );
	ui->checkBox_remember_password->setChecked(		mp_settings->getRememberPassword() );
	QDialog::show();
}
