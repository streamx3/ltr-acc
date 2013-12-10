#ifndef DIALOG_SELECTDB_H
#define DIALOG_SELECTDB_H

#include "settings.h"
#include "mainwindow.h"

#include <QtSql/QSqlDatabase>
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Dialog_SelectDB;
}

class Dialog_SelectDB : public QDialog
{
	Q_OBJECT

public:
	explicit Dialog_SelectDB(QWidget *parent = 0);
	void bindSettings(Settings *inc_settings);
	void bindDatabase(QSqlDatabase *p_db);
	~Dialog_SelectDB();

private slots:
	void on_buttonBox_rejected();
	void on_buttonBox_accepted();

signals:
	void call_main_window(bool flag);

private:
	Ui::Dialog_SelectDB *ui;
	Settings *p_settings;
	QSqlDatabase *mp_db;
};

#endif // DIALOG_SELECTDB_H
