#ifndef OUTPUT_INFO_H
#define OUTPUT_INFO_H

#include <QDialog>
#include <QString>

namespace Ui {
class Output_info;
}

class Output_info : public QDialog
{
    Q_OBJECT

public:
    explicit Output_info(QWidget *parent = 0);
    ~Output_info();


private slots:
    void on_pay_card_clicked();

    void on_pay_cash_clicked();

private:
    Ui::Output_info *ui;
};

#endif // OUTPUT_INFO_H
