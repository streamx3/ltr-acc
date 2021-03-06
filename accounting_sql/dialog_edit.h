#ifndef DIALOG_EDIT_H
#define DIALOG_EDIT_H

#include "settings.h"
#include "accounting_record_struct.h"

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
	void bindRecStr(accounting_record *inc_str);
	~Dialog_Edit();
	void show_me(bool flag);

private slots:
	void on_buttonBox_accepted();

	void on_checkBox_paid_clicked();

signals:
	void request_recort_push(bool flag);

protected:
	void pullInput2sh_rec();

private:
	Ui::Dialog_Edit *ui;
	Settings *p_settings;
	accounting_record *mp_acc_rec_inoming;
	bool m_enable_sending;
};

#endif // DIALOG_EDIT_H
