#ifndef SELECT_TYPE_H
#define SELECT_TYPE_H

#include <QDialog>

namespace Ui {
class Select_type;
}

class Select_type : public QDialog
{
    Q_OBJECT

public:
    explicit Select_type(QWidget *parent = 0);
    ~Select_type();

private slots:
    void on_express_but_clicked();

    void on_standart_but_clicked();

private:
    Ui::Select_type *ui;
};

#endif // SELECT_TYPE_H
