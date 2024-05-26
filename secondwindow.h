#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include "mainsystem.h"
#include <QDialog>
#include <vector>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog {
    Q_OBJECT

public:
    explicit SecondWindow(MainSystem *mainSystem, User *user, QWidget *parent = nullptr);
    ~SecondWindow();
    void fillBoxes();

private slots:
    void on_chickenBox_activated(int index);

    void on_meatBox_activated(int index);

    void on_addToCartButton_clicked();

    void on_viewCartButton_clicked();

private:
    Ui::SecondWindow *ui;
    MainSystem *ms;
    User* user;
    int itemCount;
    vector<string> selectedItems;
    vector<double> selectedItemsPrices;
};

#endif // SECONDWINDOW_H
