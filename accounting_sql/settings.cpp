#include "settings.h"

Settings::Settings(){
	m_db_type = e_db_Unknown;
	m_db_connected	= false;
	m_db_filename	= "";
	m_db_address	= "127.0.0.1";
	m_db_username	= "user";
	m_db_password	= "";
	m_db_dbname		= "qt_sql";
	m_db_tablename	= "books";
	m_db_type		= e_db_SQL;
	mp_qsettings	= 0;

	m_remember_password = false;

	m_conf_file.setFileName("config.ini");
	mp_qsettings = new QSettings( m_conf_file.fileName(), QSettings::NativeFormat );
	readConfigFile();
}

Settings::~Settings(){
	if( mp_qsettings != 0 )
		delete mp_qsettings;
}

bool Settings::setDB_Type( DB_Type type ){
	QMutexLocker locker( &m_qmutex );
	return ( m_db_type = type );
}

bool Settings::getDB_Type(){
	QMutexLocker locker( &m_qmutex );
	return m_db_type;
}

void Settings::lock(){
	return m_qmutex.lock();
}

void Settings::unlock(){
	return m_qmutex.unlock();
}

bool Settings::setDB_Address( QString str_address ){
	QMutexLocker locker( &m_qmutex );
	return m_db_address = str_address, 1;
}

QString Settings::getDB_Address(){
	QMutexLocker locker( &m_qmutex );
	return m_db_address;
}

bool Settings::setDB_Username( QString username ){
	QMutexLocker locker( &m_qmutex );
	return m_db_username = username, 1;
}

QString Settings::getDB_Username(){
	QMutexLocker locker( &m_qmutex );
	return m_db_username;
}

bool Settings::setDB_Password( QString password ){
	QMutexLocker locker( &m_qmutex );
	return m_db_password = password, 1;
}

QString Settings::getDB_Password(){
	QMutexLocker locker( &m_qmutex );
	return m_db_password;
}

bool Settings::setDB_Tablename( QString tablename ){
	QMutexLocker locker( &m_qmutex );
	return m_db_tablename = tablename, 1;
}

QString Settings::getDB_Tablename(){
	QMutexLocker locker( &m_qmutex );
	return m_db_tablename;
}

bool Settings::setDB_DBname( QString dbname ){
	QMutexLocker locker( &m_qmutex );
	return m_db_dbname = dbname, 1;
}

QString Settings::getDB_DBname(){
	QMutexLocker locker( &m_qmutex );
	return m_db_dbname;
}

bool Settings::setDB_Filename( QString filename ){
	QMutexLocker locker( &m_qmutex );
	return m_db_filename = filename, 1;
}

QString Settings::getDB_Filename(){
	QMutexLocker locker( &m_qmutex );
	return m_db_filename;
}

void  Settings::readConfigFile(){
	QMutexLocker locker( &m_qmutex );
	if( m_conf_file.exists() ){
		if( mp_qsettings->value( "user" ) != m_default_qvariant ){
			m_db_username = mp_qsettings->value( "user" ).toString();
		}
		if( mp_qsettings->value( "password" ) != m_default_qvariant ){
			m_db_password = mp_qsettings->value( "password" ).toString();
		}
		if( mp_qsettings->value( "database" ) != m_default_qvariant ){
			m_db_dbname = mp_qsettings->value( "database" ).toString();
		}
		if( mp_qsettings->value( "hostname" ) != m_default_qvariant ){
			m_db_address = mp_qsettings->value( "hostname" ).toString();
		}
		if( mp_qsettings->value( "remember_password" ) != m_default_qvariant ){
			m_remember_password = mp_qsettings->value( "remember_password" ).toBool();
		}
	}
}

void Settings::writeConfigFile(){
	QMutexLocker locker( &m_qmutex );
	mp_qsettings->setValue( "user", m_db_username );
	mp_qsettings->setValue( "password" , m_remember_password ? m_db_password : "" );
	mp_qsettings->setValue( "database", m_db_dbname );
	mp_qsettings->setValue( "hostname", m_db_address );
	mp_qsettings->setValue( "remember_password", m_remember_password );
	mp_qsettings->sync();
}


bool Settings::setRememberPassword( bool condition ){
	QMutexLocker locker( &m_qmutex );
	m_remember_password = condition;
	return true;
}

bool Settings::getRememberPassword(){
	QMutexLocker locker( &m_qmutex );
	return m_remember_password;
}
