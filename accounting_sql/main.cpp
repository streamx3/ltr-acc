#include "mainwindow.h"
#include "dialog_selectdb.h"
#include "settings.h"

#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtGui/QtGui>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
#if QT_VERSION < 0x050000
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
#endif

	Settings settings1;
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

	MainWindow main_window;
	Dialog_SelectDB dialog_select_db1;
	QObject::connect(&dialog_select_db1, SIGNAL(call_main_window(bool)), &main_window, SLOT(show_me(bool)));
	main_window.bindDatabase(&db);
	dialog_select_db1.bindDatabase(&db);


	dialog_select_db1.show();

	return a.exec();
}
