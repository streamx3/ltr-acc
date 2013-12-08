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
