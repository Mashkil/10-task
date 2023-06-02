#include "select_time.h"
#include "ui_select_time.h"
#include "mainwindow.h"
#include"QString"
#include <iostream>
#include <string>
#include <fstream>
#include <output_info.h>
#include <QDateTime>
#include "selectdataandtimeforexpress.h"
using namespace std;

int cost;
QString station;
int costOfExpress;

Select_time::Select_time(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Select_time)
{
    ui->setupUi(this);

    ui->table_station->verticalHeader()->hide(); //скрытие заголовков
    ui->table_station->horizontalHeader()->hide();
    ui->table_station->setSelectionMode(QAbstractItemView::SingleSelection); // выравнивание
    ui->table_station->setEditTriggers(0);  //запрет на редактирование
    ui->datetime_line->setText(QDateTime::currentDateTime().toString("dd.MM.yyyy"));

    string s;
    string path;

    if(direction == 2 && type_of_train ==2){
        ui->table_station->setColumnCount(4);
        ui->table_station->setRowCount(4);
        path="C:\\klg.txt";
    }
    if(direction ==1 && type_of_train ==2){

        ui->table_station->setColumnCount(4);
        ui->table_station->setRowCount(6);
        path="C:\\msk.txt";
    }
    if(direction == 2 && type_of_train ==1){ //klg exp
        ui->table_station->setColumnCount(2);
        ui->table_station->setRowCount(2);
        path= "C:\\ekspress_klg.txt";

    }
    if(direction == 1 && type_of_train ==1){  //msk exp
        ui->table_station->setColumnCount(3);
        ui->table_station->setRowCount(4);
        path= "C:\\ekspress_msk.txt";
    }

    ifstream file(path);

    for (int i=0; i< ui->table_station->rowCount();i++)
        for(int j=0; j<ui->table_station->columnCount();j++){

            if(getline(file, s))
            {
                QTableWidgetItem *t = new QTableWidgetItem(QString::fromStdString(s));
                t->setTextAlignment(5);

                ui->table_station->setItem(i,j,t);
            }
        }

    ui->table_station->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    file.close();
}

Select_time::~Select_time()
{
    delete ui;
}

void Select_time::on_print_ticket_clicked()
{

    station = ui->table_station->selectedItems().takeFirst()->text();

    if(type_of_train==2){
        cost=stations_and_prices.find((ui->table_station->selectedItems().takeFirst()->text()).toStdString())-> second;
        if(ui->there_and_back->checkState())
            cost*=2;
    }
    else{
        costOfExpress = stations_and_prices_forExpress.find((ui->table_station->selectedItems().takeFirst()->text().toStdString()))-> second;
        if(ui->there_and_back->checkState())
            costOfExpress*=2;
    }

    if(type_of_train == 2){
        Output_info out;
        out.setWindowTitle("Output");
        out.setModal(true);
        out.exec();
    }
    else{
        SelectDataAndTimeForExpress express;
        express.setWindowTitle("Select date and time");
        express.setModal(true);
        express.exec();
    }


}
