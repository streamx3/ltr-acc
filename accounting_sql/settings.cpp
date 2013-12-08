#include "settings.h"

Settings::Settings(){
	m_db_type = e_db_Unknown;
}

Settings::~Settings(){

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
	return m_db_address.setAddress( str_address );
}

QString Settings::getDB_Address(){
	QMutexLocker locker( &m_qmutex );
	return m_db_address.toString();
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


bool Settings::setDB_Filename( QString filename ){
	QMutexLocker locker( &m_qmutex );
	return m_db_filename = filename, 1;
}

QString Settings::getDB_Filename(){
	QMutexLocker locker( &m_qmutex );
	return m_db_filename;
}
