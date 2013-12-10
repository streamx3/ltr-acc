#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "settings.h"
#include "dialog_edit.h"
#include "accounting_record_struct.h"

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
    void pushUI2Container();
	void on_pushButton_edit_clicked();

protected:
	void pushDB2Container();
    void pushContainer2UI();
    void pushContainer2DB();

private:
	Ui::MainWindow *ui;
	Settings *p_settings;
	QSqlDatabase *mp_db;
	QStringList ColumnNames;
	Dialog_Edit m_dialog_edit;
	accounting_record m_acc_rec_shared;
	int m_num_of_records;
	QList<accounting_record> m_records;

};

#endif // MAINWINDOW_H
