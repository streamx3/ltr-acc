#include "dialog_edit.h"
#include "ui_dialog_edit.h"

Dialog_Edit::Dialog_Edit(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog_Edit)
{
	ui->setupUi(this);
	p_settings = 0;
}

Dialog_Edit::~Dialog_Edit()
{
	delete ui;
}

void Dialog_Edit::bindSettings(Settings *inc_settings){
	if(inc_settings != 0)
		p_settings = inc_settings;
}
