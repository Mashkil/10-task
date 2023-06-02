#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <map>

extern int direction;
extern std::map<std::string,int> stations_and_prices;
extern std::map<std::string,int> stations_and_prices_forExpress;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_to_msk_but_clicked();

    void on_to_klg_but_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
