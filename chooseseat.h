#ifndef CHOOSESEAT_H
#define CHOOSESEAT_H

#include <QDialog>
#include <string>
#include <iostream>
#include <QString>

extern QString choosedSeat;
namespace Ui {
class chooseSeat;
}

class chooseSeat : public QDialog
{
    Q_OBJECT

public:
    explicit chooseSeat(QWidget *parent = 0);
    ~chooseSeat();

private slots:
    void on_pushButton_clicked();

    void on_printTicketButton_clicked();

private:
    Ui::chooseSeat *ui;
};

#endif // CHOOSESEAT_H
