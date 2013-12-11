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
	QObject::connect(&m_dialog_edit, SIGNAL(request_recort_push(bool)), SLOT(pushShared2Container()));
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
//        pushDB2table();
		pushDB2Container();
		pushContainer2UI();
		show();
	}
}

void MainWindow::bindDatabase(QSqlDatabase *p_db){
	if(p_db != 0)
		mp_db = p_db;
}

void MainWindow::on_pushButton_edit_clicked()
{
	qint32 selected_row = -1;
	QTableWidgetItem *pItem = 0;
	QList<QTableWidgetItem *> selecteditems = ui->tableWidget->selectedItems();
	if(selecteditems.size()){
		pItem = *(selecteditems.begin());
		selected_row = pItem->row();
	}
	if(selected_row > -1 && selected_row < m_records.size()){
		QList<accounting_record>::iterator it = m_records.begin();
		for(qint32 i = 0; i < selected_row; ++i){
			it++;
		}
		m_acc_rec_shared = *it;
		m_dialog_edit.show_me(true);
	}
}

void MainWindow::pushDB2Container(){
	accounting_record local_record;
	int index=0;

	m_records.clear();
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

void MainWindow::pushContainer2UI(){
	QList<accounting_record>::iterator it = m_records.begin();
	quint32 i = 0;
	ui->tableWidget->clearContents();
	ui->tableWidget->setRowCount(m_records.size());
	accounting_record *p_record;
	QTableWidgetItem *p_tmp_item = 0;
	ui->label_records_num->setText(QString::number(m_records.size()));

	while (it != m_records.end()){
		p_record = &(*it);
		ui->tableWidget->setItem(i, 2,new QTableWidgetItem(p_record->name));
		ui->tableWidget->setItem(i, 3,new QTableWidgetItem(p_record->phone));
		ui->tableWidget->setItem(i, 4,new QTableWidgetItem(p_record->city));
		ui->tableWidget->setItem(i,12,new QTableWidgetItem(p_record->remarks));

		ui->tableWidget->setItem(i, 0,new QTableWidgetItem(QString::number(p_record->id)));
		ui->tableWidget->setItem(i, 5,new QTableWidgetItem(QString::number(p_record->np_dept)));
		ui->tableWidget->setItem(i, 6,new QTableWidgetItem(QString::number(p_record->order_1)));
		ui->tableWidget->setItem(i, 7,new QTableWidgetItem(QString::number(p_record->order_2)));

		ui->tableWidget->setItem(i, 1,new QTableWidgetItem(p_record->order_date.toString()));
		ui->tableWidget->setItem(i, 9,new QTableWidgetItem(p_record->paid_time.toString()));
		ui->tableWidget->setItem(i,11,new QTableWidgetItem(p_record->sent_time.toString()));

		p_tmp_item = new QTableWidgetItem("");
		p_tmp_item->setCheckState(p_record->paid);
		ui->tableWidget->setItem(i,8,p_tmp_item);

		p_tmp_item = new QTableWidgetItem("");
		p_tmp_item->setCheckState(p_record->sent);
		ui->tableWidget->setItem(i,10,p_tmp_item);
		++i;
		++it;
	}
}

void MainWindow::pushShared2Container(){
	quint32 i = 0;
	// Editing Logic
	if(m_acc_rec_shared.id > 0){
		QList<accounting_record>::iterator it = m_records.begin();
		while((*it).id != m_acc_rec_shared.id && it != m_records.end()){
			++it;
			++i;
		}
		m_records[i] = m_acc_rec_shared;
	}
	// Adding Logic
	else{
		m_records.push_back(m_acc_rec_shared);
	}
	pushContainer2UI();
}

void MainWindow::pushContainer2DB(){
	QSqlQuery query;
	accounting_record *p_rec;
	QString db_name("books");

	for(QList<accounting_record>::iterator it = m_records.begin(); it != m_records.end(); ++it){
		query.clear();
		p_rec = &(*it);
		// Update
		if(p_rec->id > 0){
			query.prepare(QString("UPDATE ") + db_name +
						  QString(" SET "
								  "order_time = :order_time, "
								  "name       = :name, "
								  "phone      = :phone, "
								  "city       = :city, "
								  "np_dept    = :np_dept, "
								  "order_1    = :order_1, "
								  "order_2    = :order_2, "
								  "paid       = :paid, "
								  "paid_time  = :paid_time, "
								  "sent       = :sent, "
								  "sent_time  = :sent_time, "
								  "remarks    = :remarks "
								  "WHERE id = ")
						  + QString::number(p_rec->id));
		}
		// Add
		else{
			query.prepare(QString("INSERT INTO ") + db_name +
										   (" ( order_time,  name,  phone,  city,  np_dept,  order_1,  order_2,  paid,  paid_time,  sent,  sent_time,  remarks)"
							  "VALUES (       :order_time, :name, :phone, :city, :np_dept, :order_1, :order_2, :paid, :paid_time, :sent, :sent_time, :remarks)"));
		}
		query.bindValue( ":order_time",	p_rec->order_date );
		query.bindValue( ":name",		p_rec->name );
		query.bindValue( ":phone",		p_rec->phone );
		query.bindValue( ":city",		p_rec->city );
		query.bindValue( ":np_dept",	p_rec->np_dept );
		query.bindValue( ":order_1",	p_rec->order_1 );
		query.bindValue( ":order_2",	p_rec->order_2 );
		query.bindValue( ":paid",		p_rec->paid == Qt::Checked ? 1 : 0 );
		query.bindValue( ":sent",		p_rec->sent == Qt::Checked ? 1 : 0 );
		query.bindValue( ":paid_time",	p_rec->paid_time );
		query.bindValue( ":sent_time",	p_rec->sent_time );
		query.bindValue( ":remarks",	p_rec->remarks );
		if(!query.exec()){
			QMessageBox::critical(0, QObject::tr("Database Error"),
					  query.lastError().text());
		}
	}
}

void MainWindow::on_pushButton_add_clicked()
{
	//id
	m_acc_rec_shared.id = 0;
	//order_date
	m_acc_rec_shared.order_date = QDateTime::currentDateTime();
	//name
	m_acc_rec_shared.name.clear();
	//phone
	m_acc_rec_shared.phone.clear();
	//city
	m_acc_rec_shared.city.clear();
	//NP DeptNumber
	m_acc_rec_shared.np_dept = 0;
	//order_1
	m_acc_rec_shared.order_1 = 0;
	//order_2
	m_acc_rec_shared.order_2 = 0;
	//paid
	m_acc_rec_shared.paid = Qt::Unchecked;
	//paid time
	m_acc_rec_shared.paid_time = QDateTime::currentDateTime();
	//sent
	m_acc_rec_shared.sent = Qt::Unchecked;
	//sent time
	m_acc_rec_shared.sent_time = QDateTime::currentDateTime();
	//remarks
	m_acc_rec_shared.remarks.clear();
	//waybill
	m_acc_rec_shared.tracking_number.clear();

	m_dialog_edit.show_me(true);
}

void MainWindow::on_pushButton_save_clicked()
{
	pushContainer2DB();
	pushDB2Container();
	pushContainer2UI();
}
