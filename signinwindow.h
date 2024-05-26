#ifndef SIGNINWINDOW_H
#define SIGNINWINDOW_H

#include "mainsystem.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class SigninWindow;
}
QT_END_NAMESPACE

class SigninWindow : public QMainWindow {
    Q_OBJECT

public:
    SigninWindow(MainSystem *mainSystem, QWidget *parent = nullptr);
    ~SigninWindow();

private slots:
    void on_signinButton_clicked();

private:
    Ui::SigninWindow *ui;
    MainSystem *ms;
};
#endif // SIGNINWINDOW_H
