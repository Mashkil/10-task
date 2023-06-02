#include "select_type.h"
#include "ui_select_type.h"
#include "select_time.h"
#include "selectdataandtimeforexpress.h"

int type_of_train;            //1 - экспресс, 2-стандарт плюс

Select_type::Select_type(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Select_type)
{
    ui->setupUi(this);
    type_of_train=0;
    setFixedSize(400,300);
    setlocale(LC_ALL,"rus");
}

Select_type::~Select_type()
{
    delete ui;
}

void Select_type::on_express_but_clicked()
{
    type_of_train = 1;
    Select_time select_time;
    select_time.setWindowTitle("Select station");
    select_time.setModal(true);
    select_time.exec();
}

void Select_type::on_standart_but_clicked()
{
    type_of_train=2;
    Select_time select_time;
    select_time.setWindowTitle("Select station");
    select_time.setModal(true);
    select_time.exec();
}
