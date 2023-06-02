#include "printticket.h"
#include "ui_printticket.h"
using namespace std;
#include <iostream>
#include "QLabel"
#include "QMovie"
#include "windows.h"

PrintTicket::PrintTicket(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrintTicket)
{
    ui->setupUi(this);

    /*label = new QLabel(this);
    movie = new QMovie("C:\\244.gif");
    label->setMovie(movie);
    this->resize(300,500);
    label->resize(100,300);
    label->show();
    movie->start();*/
    QMovie *movie = new QMovie("C:\\244.gif");
    ui->animation->setMovie(movie);
    movie->start();
    close();

}

PrintTicket::~PrintTicket()
{
    delete ui;
}
