#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ColumnNames.push_back(QString("id"));
	ColumnNames.push_back(QString("Время заказа"));
	ColumnNames.push_back(QString("Имя"));
	ColumnNames.push_back(QString("Телефон"));
	ColumnNames.push_back(QString("Город"));
	ColumnNames.push_back(QString("№ отделения"));
	ColumnNames.push_back(QString("ч.1"));
	ColumnNames.push_back(QString("ч.2"));
	ColumnNames.push_back(QString("уплочено"));
	ColumnNames.push_back(QString("когда уплочено"));
	ColumnNames.push_back(QString("выслано"));
	ColumnNames.push_back(QString("когда выслано"));
	ColumnNames.push_back(QString("Примечания"));
	ui->tableWidget->setColumnCount(13);
//	ui->tableWidget->setRowCount(7);
	ui->tableWidget->setHorizontalHeaderLabels(ColumnNames);
	ui->tableWidget->setColumnWidth(0,30);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_ExitButton_clicked()
{
	/// TODO: Add confirmation
	close();
	qApp->quit();
}

void MainWindow::bindSettings(Settings *inc_settings){
	if(inc_settings != 0)
		p_settings = inc_settings;
}

void MainWindow::show_me(bool flag){
	if(flag){
		show();
	}
}

void MainWindow::bindDatabase(QSqlDatabase *p_db){
	if(p_db != 0)
		mp_db = p_db;
}

void MainWindow::pushDB2table(){

}
