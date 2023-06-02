#include "chooseseat.h"
#include "ui_chooseseat.h"
#include "selectdataandtimeforexpress.h"
#include <iostream>
#include "fstream"
#include <vector>
#include <algorithm>
#include <QString>
#include "output_info.h"
using namespace std;
QString choosedSeat;

chooseSeat::chooseSeat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chooseSeat)
{
    ui->setupUi(this);
    vector<string> allSeats;

    for(int i=1; i<120; i++)
        allSeats.push_back(to_string(i));

    string buf;
    ifstream file(fullPath);
    while(getline(file,buf)){
        for(int i =0; i<allSeats.size();i++)
            if(allSeats[i]==buf)
                allSeats.erase(allSeats.begin()+i);
    }

    for(string i : allSeats)
        ui->selectSeatComboBox->addItem(QString::fromStdString(i));

    file.close();
}

chooseSeat::~chooseSeat()
{
    delete ui;
}
void chooseSeat::on_printTicketButton_clicked()
{
    ofstream file(fullPath, std::ios::app);
    file<<ui->selectSeatComboBox->currentText().toStdString()<<endl;
    file.close();
    choosedSeat = ui->selectSeatComboBox->currentText();

    Output_info output;
    output.setWindowTitle("Output");
    output.setModal(true);
    output.exec();
}
