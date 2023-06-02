#include "selectdataandtimeforexpress.h"
#include "ui_selectdataandtimeforexpress.h"
#include <sys/types.h>
#include <dirent.h>
#include <iostream>
#include <direct.h>
#include <sys/stat.h>
#include "mainwindow.h"
#include "fstream"
#include <QDate>
#include <QDateTime>
#include "chooseseat.h"
using namespace std;

string fullPath;
QString dateOfExpress;
QString timeOfExpress;


SelectDataAndTimeForExpress::SelectDataAndTimeForExpress(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectDataAndTimeForExpress)
{
    ui->setupUi(this);
    ui->chooseTimeComboBox->clear();
    timeOfExpress = "";
    dateOfExpress = "";

    ui->chooseDate->setDate(QDate::currentDate());

    if(direction == 1){
        ui->chooseTimeComboBox->addItem("7:07"); //1
        ui->chooseTimeComboBox->addItem("9:36"); //2
        ui->chooseTimeComboBox->addItem("15:07"); //3
        ui->chooseTimeComboBox->addItem("18:42"); //4
        ui->chooseTimeComboBox->addItem("20:22"); //5
        ui->chooseTimeComboBox->addItem("21:58"); //6
    }
    else{

        ui->chooseTimeComboBox->addItem("10:29"); //7
        ui->chooseTimeComboBox->addItem("12:19"); //8
        ui->chooseTimeComboBox->addItem("15:22"); //9
        ui->chooseTimeComboBox->addItem("18:46"); //10
        ui->chooseTimeComboBox->addItem("20:55"); //11
        ui->chooseTimeComboBox->addItem("21:55"); //12
    }
}

SelectDataAndTimeForExpress::~SelectDataAndTimeForExpress()
{
    delete ui;
}

void SelectDataAndTimeForExpress::on_selectSeatButton_clicked()
{    
    string numberOfTime;
    QString path ="M:\\"+ ui->chooseDate->date().toString("dd.MM.yyyy");
    QByteArray ba = path.toLocal8Bit();
    QString choosedTime = ui->chooseTimeComboBox->currentText();

    if(choosedTime == "7:07")
        numberOfTime = "\\1.txt";
    if(choosedTime == "9:36")
        numberOfTime = "\\2.txt";
    if(choosedTime == "15:07")
        numberOfTime = "\\3.txt";
    if(choosedTime == "18:42")
        numberOfTime = "\\4.txt";
    if(choosedTime == "20:22")
        numberOfTime = "\\5.txt";
    if(choosedTime == "21:58")
        numberOfTime = "\\6.txt";
    if(choosedTime == "10:29")
        numberOfTime = "\\7.txt";
    if(choosedTime == "12:19")
        numberOfTime = "\\8.txt";
    if(choosedTime == "15:22")
        numberOfTime = "\\9.txt";
    if(choosedTime == "18:46")
        numberOfTime = "\\10.txt";
    if(choosedTime == "20:55")
        numberOfTime = "\\11.txt";
    if(choosedTime == "21:55")
        numberOfTime = "\\12.txt";

    timeOfExpress= choosedTime;
    dateOfExpress = ui->chooseDate->date().toString("dd.MM.yyyy");

    const char *pathInChar = ba.data();

    struct stat checkDirectory;
    fullPath = path.toStdString() + numberOfTime;

    if(stat(pathInChar, &checkDirectory) == 0){ // папка существует

        ofstream file(path.toStdString() + numberOfTime, std::ios::app);        
        file.close();
    }
    else{ // папка отсутствует

        mkdir(pathInChar);
        ofstream file(path.toStdString() + numberOfTime, std::ios::app);
        file.close();
    }
    chooseSeat seat;
    seat.setWindowTitle("Choose seat");
    seat.setModal(true);
    seat.exec();
}
