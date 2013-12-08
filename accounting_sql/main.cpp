#include "mainwindow.h"
#include "dialog_selectdb.h"
#include <QApplication>
#include <QStateMachine>

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QStateMachine StateMachine1;

	QState *state_unconnected;
	QState *state_connected;
	try{
		state_unconnected	= new QState();
		state_connected		= new QState();
	}catch(std::bad_alloc&){
		cout<<"Failed to allocate memmory. Probably, try closing some programs."<<endl;
		return 0;
	}

//	state_unconnected->addTransition();
//	state_unconnected->addTransition();

	StateMachine1.addState(state_unconnected);
	StateMachine1.addState(state_connected);




	MainWindow main_window;
	Dialog_SelectDB dialog_select_db1;
	dialog_select_db1.show();
	main_window.show();

	return a.exec();
}
