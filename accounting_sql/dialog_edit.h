#ifndef DIALOG_EDIT_H
#define DIALOG_EDIT_H

#include <QDialog>

namespace Ui {
class Dialog_Edit;
}

class Dialog_Edit : public QDialog
{
	Q_OBJECT

public:
	explicit Dialog_Edit(QWidget *parent = 0);
	~Dialog_Edit();

private:
	Ui::Dialog_Edit *ui;
};

#endif // DIALOG_EDIT_H
