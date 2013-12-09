#-------------------------------------------------
#
# Project created by QtCreator 2013-12-06T13:50:57
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = accounting_sql
TEMPLATE = app


SOURCES += main.cpp\
		mainwindow.cpp \
	dialog_selectdb.cpp \
	dialog_edit.cpp \
	settings.cpp

HEADERS  += mainwindow.h \
	dialog_selectdb.h \
	dialog_edit.h \
	settings.h

FORMS    += mainwindow.ui \
	dialog_selectdb.ui \
	dialog_edit.ui

RESOURCES += \
    config_res.qrc
