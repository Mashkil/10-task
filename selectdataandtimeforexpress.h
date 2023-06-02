#ifndef SELECTDATAANDTIMEFOREXPRESS_H
#define SELECTDATAANDTIMEFOREXPRESS_H

#include <QDialog>
#include <string>
#include <iostream>
#include <QString>
extern std::string fullPath;
extern QString dateOfExpress;
extern QString timeOfExpress;

namespace Ui {
class SelectDataAndTimeForExpress;
}

class SelectDataAndTimeForExpress : public QDialog
{
    Q_OBJECT

public:
    explicit SelectDataAndTimeForExpress(QWidget *parent = 0);
    ~SelectDataAndTimeForExpress();

private slots:
    void on_selectSeatButton_clicked();

private:
    Ui::SelectDataAndTimeForExpress *ui;
};

#endif // SELECTDATAANDTIMEFOREXPRESS_H
