#ifndef DIALOG_SELECTDB_H
#define DIALOG_SELECTDB_H

#include <QDialog>

namespace Ui {
class Dialog_SelectDB;
}

class Dialog_SelectDB : public QDialog
{
	Q_OBJECT
	
public:
	explicit Dialog_SelectDB(QWidget *parent = 0);
	~Dialog_SelectDB();
	
private:
	Ui::Dialog_SelectDB *ui;
};

#endif // DIALOG_SELECTDB_H
