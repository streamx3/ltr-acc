#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMutex>
#include <QMutexLocker>
#include <QtGlobal>
#include <QSettings>
#include <QFile>

#include <unistd.h> // to use config in user's home folder
#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>
#include <string>

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

	bool setDB_DBname( QString dbname );
	QString getDB_DBname();

	bool setDB_Filename( QString filename );
	QString getDB_Filename();

	bool setRememberPassword( bool condition );
	bool getRememberPassword();

	void readConfigFile();
	void writeConfigFile();

private:
	// For internal logic
	QMutex			m_qmutex;
	DB_Type			m_db_type;
	bool			m_db_connected;
	bool			m_remember_password;
	QFile			m_conf_file;
	QSettings		*mp_qsettings;
	QVariant		m_default_qvariant;

	/// SQL variables
	QString			m_db_address;
	QString			m_db_username;
	QString			m_db_password;
	QString			m_db_dbname;
	QString			m_db_tablename;
	//QString		m_db_table_prefix;

	/// SQLite variables
	QString			m_db_filename;
};

#endif // SETTINGS_H
