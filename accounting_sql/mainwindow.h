#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "settings.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	void bindSettings(Settings *inc_settings);
	~MainWindow();

private slots:
	void on_ExitButton_clicked();
	void show_me(bool flag);

private:
	Ui::MainWindow *ui;
	Settings *p_settings;
};

#endif // MAINWINDOW_H
