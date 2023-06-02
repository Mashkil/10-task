#include "output_info.h"
#include "ui_output_info.h"
#include"QString"
#include <iostream>
#include <select_time.h>
#include <QDateTime>
#include <QTextCodec>
#include "selectdataandtimeforexpress.h"
#include "mainwindow.h"
#include "chooseseat.h"
using namespace std;

Output_info::Output_info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Output_info)
{

    ui->setupUi(this);


    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));
    QString cyrillicName = QString::fromLocal8Bit("Обнинск");

    ui->to_there->setText(station);
    ui->obn->setText(cyrillicName);
    if(type_of_train==2){
         ui->price->setText(QString::number(cost)+QString::fromLocal8Bit(" руб."));
         ui->choosedSeat->setText("-------");
         ui->choosedTime->setText("-------");
         ui->data->setText(QDateTime::currentDateTime().toString("dd.MM.yyyy"));
         ui->typeOfTrain->setText(QString::fromLocal8Bit("Стандарт Плюс"));
    }
    if(type_of_train==1){
        ui->price->setText(QString::number(costOfExpress)+QString::fromLocal8Bit(" руб."));
        ui->choosedSeat->setText(choosedSeat);
        ui->choosedTime->setText(timeOfExpress);
        ui->data->setText(dateOfExpress);
        ui->typeOfTrain->setText(QString::fromLocal8Bit("Экспресс"));
    }

    setFixedSize(409,273);

}


Output_info::~Output_info()
{
    delete ui;
}

void Output_info::on_pay_card_clicked()
{

}

void Output_info::on_pay_cash_clicked()
{

}
