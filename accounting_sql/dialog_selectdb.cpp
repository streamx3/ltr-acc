#include "dialog_selectdb.h"
#include "ui_dialog_selectdb.h"

Dialog_SelectDB::Dialog_SelectDB(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog_SelectDB)
{
	ui->setupUi(this);
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
	call_main_window(true);
}
