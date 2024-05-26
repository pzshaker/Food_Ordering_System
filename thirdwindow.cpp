#include "thirdwindow.h"
#include "mainsystem.h"
#include "ui_thirdwindow.h"
#include "QMessageBox"

ThirdWindow::ThirdWindow(MainSystem *mainSystem, User *user,
                         vector<string> selectedItems,
                         vector<double> selectedItemsPrices, QWidget *parent)
    : QDialog(parent), ui(new Ui::ThirdWindow), ms(mainSystem) {

    this->user = user;
    ui->setupUi(this);

    this->setWindowTitle("Cart Review");

    for (int i = 0; i < selectedItems.size(); i++) {
        QString name = QString::fromStdString(selectedItems[i]);
        QString price = QString::number(selectedItemsPrices[i]);
        ui->itemsListWidgets->addItem(name + ", Price: " + price);
    }
    total = 0 ;
    for(int i = 0 ; i < selectedItemsPrices.size() ; i++){
        total = total+selectedItemsPrices[i] ;

    }
    ui->label_Total_Price->setText("Total Price: "  + QString::number(total) )  ;
    ui->label_Balance ->setText("Your current balance: " + QString::number(user->getBalance()) + " LE") ;
}


ThirdWindow::~ThirdWindow() { delete ui; }

void ThirdWindow::on_pushButton_buy_clicked()
{
    if(ui->itemsListWidgets->count() == 0){
        ui->alertLabel->setText("Your cart is empty!");
        return;
    }

    double balance = user->getBalance();

    if (balance < total) {
        ui->alertLabel->setText("Sorry, your balance is not enough. Please recharge.");
    } else {
        balance -= total;
        user->setBalance(balance);
        ui->alertLabel->setText("Purchase successful. Enjoy your meal!");
        ui->label_Balance->setText("Your current balance: " + QString::number(balance) + " LE");
        ui->itemsListWidgets->clear();
        ui->label_Total_Price->setText("Total Price: ");

        QMessageBox msgBox;
        msgBox.setWindowTitle("Thank You");
        msgBox.setText("Thank you for your purchase!");
        msgBox.exec();
        qApp->quit();
    }
}

void ThirdWindow::on_button_recharge_clicked()
{
    double amount  = ui->lineEdit_balance->text().toDouble();
    if(amount < 0 ) {
        ui->lineEdit_balance->setText("Can't take a negative value");
    } else {
        user->setBalance(user->getBalance()+amount);
        ui->label_Balance ->setText("Your current balance: " + QString::number(user->getBalance()) + " LE");
        ui->lineEdit_balance->setText("");
    }
}

