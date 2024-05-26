#include "signinwindow.h"
#include "mainsystem.h"
#include "secondwindow.h"
#include "ui_signinwindow.h"
#include <string>

using namespace std;

void openSecondWindow(MainSystem *ms, User *user);

SigninWindow::SigninWindow(MainSystem *mainSystem, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::SigninWindow), ms(mainSystem) {
    ui->setupUi(this);

    this->setWindowTitle("Sign in");
}

SigninWindow::~SigninWindow() { delete ui; }

void SigninWindow::on_signinButton_clicked() {
    string inputName = ui->nameLineEdit->text().toStdString();
    string inputPass = ui->passLineEdit->text().toStdString();

    if (inputName == "" || inputPass == "") {
        ui->infoLabel->setText("Please fill both name and password fields.");
    } else if (!ms->isExist(inputName)) {
        ui->infoLabel->setText("Name Does not Exist");
    } else if (ms->isValidPass(inputName, inputPass)) {
        ui->infoLabel->setText("Signed in successfully");
        User *user = ms->getUser(inputName);
        ui->balanceLabel->setText("Balance: " + QString::number(user->getBalance()) + " LE");
        openSecondWindow(ms, user);
    } else {
        ui->infoLabel->setText("Name is correct but password is wrong");
    }
}

void openSecondWindow(MainSystem *ms, User *user) {
    SecondWindow secondWindow(ms, user);
    secondWindow.exec();
}
