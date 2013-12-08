#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMutex>
#include <QMutexLocker>
#include <QtGlobal>

#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
#include <qt5/QtNetwork/QHostAddress>
#else
#include <qt4/QtNetwork/QHostAddress>

#endif

enum DB_Type{
	e_db_Unknown = 0,
	e_db_SQL,
	e_db_Sqlite
};

class Settings{
public:
	Settings();
	~Settings();

	void lock();
	void unlock();

	bool setDB_Type( DB_Type type );
	bool getDB_Type();

	bool setDB_Address( QString str_address );
	QString getDB_Address();

	bool setDB_Username( QString username );
	QString getDB_Username();

	bool setDB_Password( QString password );
	QString getDB_Password();

	bool setDB_Tablename( QString tablename );
	QString getDB_Tablename();

	bool setDB_Filename( QString filename );
	QString getDB_Filename();

private:
	QMutex			m_qmutex;
	DB_Type			m_db_type;

	/// SQL variables
	QHostAddress	m_db_address;
	QString			m_db_username;
	QString			m_db_password;
	QString			m_db_tablename;
	//QString		m_db_table_prefix;

	/// SQLite variables
	QString			m_db_filename;


};

#endif // SETTINGS_H
