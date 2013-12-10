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

	m_dialog_edit.bindRecStr(&m_acc_rec_shared);
	m_num_of_records = 0;
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
		pushDB2Container();
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
	m_num_of_records = query.size();
	ui->tableWidget->setRowCount(m_num_of_records);
	ui->label_records_num->setText(m_num_of_records ? QString::number(m_num_of_records) : "N/A");
	int index=0;

	Qt::CheckState paid_state =  Qt::Unchecked, sent_state = Qt::Unchecked;
	QTableWidgetItem *p_tmp_item;
	QString date;
	while (query.next())
	{
		ui->tableWidget->setItem(index,0,new QTableWidgetItem(query.value(0).toString()));
		date = query.value(1).toString();
		date.replace(10,1," ");
		ui->tableWidget->setItem(index,1,new QTableWidgetItem(date));
		ui->tableWidget->setItem(index,2,new QTableWidgetItem(query.value(2).toString()));
		ui->tableWidget->setItem(index,3,new QTableWidgetItem(query.value(3).toString()));
		ui->tableWidget->setItem(index,4,new QTableWidgetItem(query.value(4).toString()));
		ui->tableWidget->setItem(index,5,new QTableWidgetItem(query.value(5).toString()));
		ui->tableWidget->setItem(index,6,new QTableWidgetItem(query.value(6).toString()));
		ui->tableWidget->setItem(index,7,new QTableWidgetItem(query.value(7).toString()));

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

		date = query.value(9).toString();
		date.replace(10,1," ");
		ui->tableWidget->setItem(index,9,new QTableWidgetItem(date));
		date = query.value(11).toString();
		date.replace(10,1," ");
		ui->tableWidget->setItem(index,11,new QTableWidgetItem(date));
		ui->tableWidget->setItem(index,12,new QTableWidgetItem(query.value(12).toString()));
//		for(int i = 0; i < 13; ++i){
//			ui->tableWidget->setItem(index,i,new QTableWidgetItem(query.value(i).toString()));
//		}
		index++;
	}
}

void MainWindow::on_pushButton_edit_clicked()
{
	int selected_row = -1;
	QTableWidgetItem *pItem = 0;
	QList<QTableWidgetItem *> selecteditems = ui->tableWidget->selectedItems();
	if(selecteditems.size()){
		pItem = *(selecteditems.begin());
		selected_row = pItem->row();
	}
	if(selected_row > -1 && selected_row < m_num_of_records){
		//id
		pItem = ui->tableWidget->itemAt(selected_row, 0);
		m_acc_rec_shared.id = pItem->text().toInt();
		//order_date
		pItem = ui->tableWidget->itemAt(selected_row, 1);
		m_acc_rec_shared.order_date = QDateTime::fromString(pItem->text(),"yyyy-MM-dd HH:mm:ss");
		//name
		pItem = ui->tableWidget->itemAt(selected_row, 2);
		m_acc_rec_shared.name = pItem->text();
		//phone
		pItem = ui->tableWidget->itemAt(selected_row, 3);
		m_acc_rec_shared.phone = pItem->text();
		//city
		pItem = ui->tableWidget->itemAt(selected_row, 4);
		m_acc_rec_shared.city = pItem->text();
		//NP DeptNumber
		pItem = ui->tableWidget->itemAt(selected_row, 5);
		m_acc_rec_shared.np_dept = pItem->text().toInt();
		//order_1
		pItem = ui->tableWidget->itemAt(selected_row, 6);
		m_acc_rec_shared.order_1 = pItem->text().toInt();
		//order_2
		pItem = ui->tableWidget->itemAt(selected_row, 7);
		m_acc_rec_shared.order_2 = pItem->text().toInt();
		//paid
		pItem = ui->tableWidget->itemAt(selected_row, 8);
		m_acc_rec_shared.paid = pItem->checkState();
		//paid time
		pItem = ui->tableWidget->itemAt(selected_row, 9);
		m_acc_rec_shared.paid_time = QDateTime::fromString(pItem->text(),"yyyy-MM-dd HH:mm:ss");
		//sent
		pItem = ui->tableWidget->itemAt(selected_row, 10);
		m_acc_rec_shared.sent = pItem->checkState();
		//sent time
		pItem = ui->tableWidget->itemAt(selected_row, 11);
		m_acc_rec_shared.sent_time = QDateTime::fromString(pItem->text(),"yyyy-MM-dd HH:mm:ss");
		//remarks
		pItem = ui->tableWidget->itemAt(selected_row, 12);
		m_acc_rec_shared.remarks = pItem->text();
		m_dialog_edit.show_me(true);
	}
}

void MainWindow::pushDB2Container(){
	accounting_record local_record;
	int index=0;

	if(!mp_db->isOpen()){
		QMessageBox::critical(0, QObject::tr("Database Not Opened"),
				  mp_db->lastError().text());
	}
	QSqlQuery query("SELECT * FROM books;");
	while (query.next())
	{
		//id
		local_record.id = query.value(0).toInt();
		//order_date
		local_record.order_date = query.value(1).toDateTime();
		//name
		local_record.name = query.value(2).toString();
		//phone
		local_record.phone = query.value(3).toString();
		//city
		local_record.city = query.value(4).toString();
		//NP DeptNumber
		local_record.np_dept = query.value(5).toInt();
		//order_1
		local_record.order_1 = query.value(6).toInt();
		//order_2
		local_record.order_2 = query.value(7).toInt();
		//paid
		local_record.paid = query.value(8).toInt() ? Qt::Checked : Qt::Unchecked;
		//paid time
		local_record.paid_time = query.value(9).toDateTime();
		//sent
		local_record.sent = query.value(10).toInt() ? Qt::Checked : Qt::Unchecked;
		//sent time
		local_record.sent_time = query.value(11).toDateTime();
		//remarks
		local_record.remarks = query.value(12).toString();

		m_records.push_back(local_record);
		index++;
	}
}
