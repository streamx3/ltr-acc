#ifndef DIALOG_EDIT_H
#define DIALOG_EDIT_H

#include "settings.h"

#include <QDialog>

namespace Ui {
class Dialog_Edit;
}

class Dialog_Edit : public QDialog
{
	Q_OBJECT

public:
	explicit Dialog_Edit(QWidget *parent = 0);
	void bindSettings(Settings *inc_settings);
	~Dialog_Edit();

private:
	Ui::Dialog_Edit *ui;
	Settings *p_settings;
};

#endif // DIALOG_EDIT_H
