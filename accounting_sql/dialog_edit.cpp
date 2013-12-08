#include "dialog_edit.h"
#include "ui_dialog_edit.h"

Dialog_Edit::Dialog_Edit(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog_Edit)
{
	ui->setupUi(this);
}

Dialog_Edit::~Dialog_Edit()
{
	delete ui;
}
