#ifndef SELECT_TIME_H
#define SELECT_TIME_H

#include <QDialog>

extern int type_of_train;
extern QString station;
extern int cost;
extern int costOfExpress;

namespace Ui {
class Select_time;
}

class Select_time : public QDialog
{
    Q_OBJECT

public:
    explicit Select_time(QWidget *parent = 0);
    ~Select_time();

private slots:
    void on_print_ticket_clicked();

private:
    Ui::Select_time *ui;
};

#endif // SELECT_TIME_H
