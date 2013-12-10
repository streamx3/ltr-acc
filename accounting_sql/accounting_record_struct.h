#ifndef ACCOUNTING_RECORD_STRUCT_H
#define ACCOUNTING_RECORD_STRUCT_H
#pragma once

#include <QString>
#include <QState>
#include <QDateTime>

/// Structure

//id
//order_date
//name
//phone
//city
//NP DeptNumber
//order_1
//order_2
//paid
//paid time
//sent
//sent time
//remarks

struct accounting_record{
    quint32     	id;
	QDateTime		order_date;
	QString			name;
	QString			phone;
	QString			city;
    quint32     	np_dept;
    quint16         order_1;
    quint16     	order_2;
	Qt::CheckState	paid;
	QDateTime		paid_time;
	Qt::CheckState	sent;
	QDateTime		sent_time;
	QString			tracking_number;
	QString			remarks;
};

#endif // ACCOUNTING_RECORD_STRUCT_H
