#ifndef DIALOG_SELECTDB_H
#define DIALOG_SELECTDB_H

#include "settings.h"
#include "mainwindow.h"

#include <QDialog>

namespace Ui {
class Dialog_SelectDB;
}

class Dialog_SelectDB : public QDialog
{
	Q_OBJECT

public:
	explicit Dialog_SelectDB(QWidget *parent = 0);
	void bindSettings(Settings *inc_settings);
	~Dialog_SelectDB();

private slots:
	void on_buttonBox_rejected();

	void on_buttonBox_accepted();
signals:
	void call_main_window(bool flag);


private:
	Ui::Dialog_SelectDB *ui;
	Settings *p_settings;
};

#endif // DIALOG_SELECTDB_H
