#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "settings.h"
#include "dialog_edit.h"

#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
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
	void bindDatabase(QSqlDatabase *p_db);
	~MainWindow();

private slots:
	void on_ExitButton_clicked();
	void show_me(bool flag);

	void on_pushButton_2_clicked();

protected:
	void pushDB2table();

private:
	Ui::MainWindow *ui;
	Settings *p_settings;
	QSqlDatabase *mp_db;
	QStringList ColumnNames;
	Dialog_Edit m_dialog_edit;
};

#endif // MAINWINDOW_H
