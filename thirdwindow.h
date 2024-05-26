#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include "mainsystem.h"
#include <QDialog>

namespace Ui {
class ThirdWindow;
}

class ThirdWindow : public QDialog {
    Q_OBJECT

public:
    explicit ThirdWindow(MainSystem *mainSystem, User *user,
                         vector<string> selectedItems,
                         vector<double> selectedItemsPrices,
                         QWidget *parent = nullptr);
    ~ThirdWindow();

private slots:
    void on_pushButton_buy_clicked();
    void on_button_recharge_clicked();

private:
    Ui::ThirdWindow *ui;
    MainSystem *ms;
    User *user;
    double total;
};

#endif // THIRDWINDOW_H
