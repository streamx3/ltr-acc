#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
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
	if(flag)
		show();
}
