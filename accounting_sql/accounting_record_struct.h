#ifndef ACCOUNTING_RECORD_STRUCT_H
#define ACCOUNTING_RECORD_STRUCT_H
#pragma once

#include <QString>
#include <QState>
#include <QDateTime>

struct accounting_record{
	unsigned int	id;
	QDateTime		order_date;
	QString			name;
	QString			phone;
	QString			city;
	unsigned int	np_dept;
	unsigned short	order_1;
	unsigned short	order_2;
	Qt::CheckState	paid;
	QDateTime		paid_time;
	Qt::CheckState	sent;
	QDateTime		sent_time;
	QString			tracking_number;
	QString			remarks;
};

#endif // ACCOUNTING_RECORD_STRUCT_H
