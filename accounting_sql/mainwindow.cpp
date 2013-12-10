#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ColumnNames.push_back(QString("id"));
	ColumnNames.push_back(QString("Время заказа"));
	ColumnNames.push_back(QString("ФИО"));
	ColumnNames.push_back(QString("Телефон"));
	ColumnNames.push_back(QString("Город"));
	ColumnNames.push_back(QString("№НП"));
	ColumnNames.push_back(QString("Ч.1"));
	ColumnNames.push_back(QString("Ч.2"));
	ColumnNames.push_back(QString(""));			// paid
	ColumnNames.push_back(QString("вр. опл."));	// payment time
	ColumnNames.push_back(QString(""));			// sent
	ColumnNames.push_back(QString("вр. отпр."));	// send time
	ColumnNames.push_back(QString("Примечания"));

	ui->tableWidget->setColumnCount(13);

	QTableWidgetItem* user_item = new QTableWidgetItem();
	QTableWidgetItem* phone_item = new QTableWidgetItem();
	QTableWidgetItem* paid_item = new QTableWidgetItem();
	QTableWidgetItem* paid_t_item = new QTableWidgetItem();
	QTableWidgetItem* sent_item = new QTableWidgetItem();
	QTableWidgetItem* sent_t_item = new QTableWidgetItem();
	QTableWidgetItem* notes_item = new QTableWidgetItem();

	user_item->setIcon(*(new QIcon(QString(":/images/user-female.png"))));
	phone_item->setIcon(*(new QIcon(QString(":/images/mobile-phone.png"))));
	paid_item->setIcon(*(new QIcon(QString(":/images/coins.png"))));
	paid_t_item->setIcon(*(new QIcon(QString(":/images/clock-coin.png"))));
	sent_item->setIcon(*(new QIcon(QString(":/images/box--arrow.png"))));
	notes_item->setIcon(*(new QIcon(QString(":/images/document--pencil.png"))));
	notes_item->setTextAlignment(Qt::AlignLeft);

	ui->tableWidget->setHorizontalHeaderItem(2, user_item);
	ui->tableWidget->setHorizontalHeaderItem(3, phone_item);
	ui->tableWidget->setHorizontalHeaderItem(8, paid_item);
	ui->tableWidget->setHorizontalHeaderItem(9, paid_t_item);
	ui->tableWidget->setHorizontalHeaderItem(10, sent_item);
	ui->tableWidget->setHorizontalHeaderItem(11, sent_t_item);
	ui->tableWidget->setHorizontalHeaderItem(12, notes_item);

	ui->tableWidget->setHorizontalHeaderLabels(ColumnNames);
	ui->tableWidget->setColumnWidth(0,30);
	ui->tableWidget->setColumnWidth(1,130);
	ui->tableWidget->setColumnWidth(3,120);
	ui->tableWidget->setColumnWidth(4,100);
	ui->tableWidget->setColumnWidth(5,40);
	ui->tableWidget->setColumnWidth(6,40);
	ui->tableWidget->setColumnWidth(7,40);
	ui->tableWidget->setColumnWidth(8,24);
	ui->tableWidget->setColumnWidth(9,130);
	ui->tableWidget->setColumnWidth(10,24);
	ui->tableWidget->setColumnWidth(11,130);
	ui->tableWidget->setColumnWidth(12,500);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_ExitButton_clicked()
{
	/// TODO: Add confirmation
	if(mp_db != 0){
		mp_db->close();
	}
	close();
	qApp->quit();
}

void MainWindow::bindSettings(Settings *inc_settings){
	if(inc_settings != 0)
		p_settings = inc_settings;
}

void MainWindow::show_me(bool flag){
	if(flag){
		pushDB2table();
		show();
	}
}

void MainWindow::bindDatabase(QSqlDatabase *p_db){
	if(p_db != 0)
		mp_db = p_db;
}

void MainWindow::pushDB2table(){
	if(!mp_db->isOpen()){
		QMessageBox::critical(0, QObject::tr("Database Not Opened"),
				  mp_db->lastError().text());
	}
	QSqlQuery query("SELECT * FROM books;");
	ui->tableWidget->setRowCount(query.size());
	ui->label_records_num->setText(query.size() ? QString::number(query.size()) : "N/A");
	int index=0;

	Qt::CheckState paid_state =  Qt::Unchecked, sent_state = Qt::Unchecked;
	QTableWidgetItem *p_tmp_item;
	while (query.next())
	{
		ui->tableWidget->setItem(index,0,new QTableWidgetItem(query.value(0).toString()));
		ui->tableWidget->setItem(index,1,new QTableWidgetItem(query.value(1).toString()));
		ui->tableWidget->setItem(index,2,new QTableWidgetItem(query.value(2).toString()));
		ui->tableWidget->setItem(index,3,new QTableWidgetItem(query.value(3).toString()));
		ui->tableWidget->setItem(index,4,new QTableWidgetItem(query.value(4).toString()));
		ui->tableWidget->setItem(index,5,new QTableWidgetItem(query.value(5).toString()));
		ui->tableWidget->setItem(index,6,new QTableWidgetItem(query.value(6).toString()));
		ui->tableWidget->setItem(index,7,new QTableWidgetItem(query.value(7).toString()));
//		ui->tableWidget->setItem(index,8,new QTableWidgetItem(query.value(8).toString()));

		//Paid Flag
		paid_state = query.value(8).toBool() ? Qt::Checked : Qt::Unchecked;
		p_tmp_item = new QTableWidgetItem("");
		p_tmp_item->setCheckState(paid_state);

		ui->tableWidget->setItem(index,8,p_tmp_item);

		//Sent flag
		sent_state = query.value(10).toBool() ? Qt::Checked : Qt::Unchecked;
		p_tmp_item = new QTableWidgetItem("");
		p_tmp_item->setCheckState(sent_state);
		if(paid_state == Qt::Unchecked){
			p_tmp_item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

		}
		ui->tableWidget->setItem(index,10,p_tmp_item);

		ui->tableWidget->setItem(index,9,new QTableWidgetItem(query.value(9).toString()));

		ui->tableWidget->setItem(index,11,new QTableWidgetItem(query.value(11).toString()));
		ui->tableWidget->setItem(index,12,new QTableWidgetItem(query.value(12).toString()));
//		for(int i = 0; i < 13; ++i){
//			ui->tableWidget->setItem(index,i,new QTableWidgetItem(query.value(i).toString()));
//		}
		index++;
	}
}

void MainWindow::on_pushButton_2_clicked()
{
	m_dialog_edit.show();
}
