#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "select_type.h"
#include <string>
#include <fstream>
#include <map>
#include <utility>
#include <stdlib.h>
#include "printticket.h"
using namespace std;

int direction;
map<string,int> stations_and_prices;
map<std::string,int> stations_and_prices_forExpress;
void price() {
    string s;
    int pr;
    string pr_buf;

    ifstream file1("C:\\obsh_stations.txt");
    ifstream file2("C:\\obsh_price.txt");

    while(getline(file1,s) && getline(file2,pr_buf))
    {
        pr= atoi(pr_buf.c_str());
        stations_and_prices.insert(make_pair(s,pr));
    }

    file1.close();
    file2.close();
}
void priceForExpress(){
    string s;
    int pr;
    string pr_buf;

    ifstream file1("C:\\obshExpress.txt");
    ifstream file2("C:\\obshPriceExpress.txt");

    while(getline(file1,s) && getline(file2,pr_buf)){
        pr= atoi(pr_buf.c_str());
        stations_and_prices_forExpress.insert(make_pair(s,pr));
    }
    file1.close();
    file2.close();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    direction = 0;
    price();
    priceForExpress();
    setFixedSize(275,285);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_to_msk_but_clicked()
{
    /*Select_type sel;
    direction =1;
    sel.setWindowTitle("Select type");
    sel.setModal(true);
    sel.exec();*/
    PrintTicket sel;
    sel.setWindowTitle("Select type");
    sel.setModal(true);
    sel.exec();

}

void MainWindow::on_to_klg_but_clicked()
{
    direction = 2;
    Select_type sel;
    sel.setWindowTitle("Select type");
    sel.setModal(true);
    sel.exec();

}
