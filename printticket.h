#ifndef PRINTTICKET_H
#define PRINTTICKET_H

#include <QDialog>
#include <QMovie>
#include <QLabel>
namespace Ui {
class PrintTicket;
}

class PrintTicket : public QDialog
{
    Q_OBJECT

public:
    explicit PrintTicket(QWidget *parent = 0);
    ~PrintTicket();


private:
    Ui::PrintTicket *ui;
};

#endif // PRINTTICKET_H
