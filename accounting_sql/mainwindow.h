#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "settings.h"
#include "dialog_edit.h"
#include "accounting_record_struct.h"

#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QMainWindow>
#include <QCloseEvent>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow( QWidget *parent = 0 );
	void bindSettings( Settings *inc_settings );
	void bindDatabase( QSqlDatabase *p_db );
	~MainWindow();

private slots:
	void show_me( bool flag );
	void pushShared2Container();
	void on_pushButton_edit_clicked();

	void on_pushButton_add_clicked();

	void on_pushButton_save_clicked();

	void on_pushButton_delete_clicked();

protected:
	void pushDB2Container();
	void pushContainer2UI();
	void pushContainer2DB();
	void closeEvent( QCloseEvent *event );

private:
	Ui::MainWindow *ui;
	Settings *p_settings;
	QSqlDatabase *mp_db;
	QStringList ColumnNames;
	QVector< quint32 > m_delete_requests;
	Dialog_Edit m_dialog_edit;
	accounting_record m_acc_rec_shared;
	quint32 m_num_of_records;
	QList< accounting_record > m_records;
	QBrush m_brush_default;
	QBrush m_brush_delete;
	QBrush m_brush_not_sent;
	//QBrush m_brush_not_saved;

	Qt::ItemFlags m_ro_item_flags;
	bool m_changes_not_saved;

};

#endif // MAINWINDOW_H
