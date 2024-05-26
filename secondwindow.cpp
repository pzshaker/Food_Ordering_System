#include "secondwindow.h"
#include "mainsystem.h"
#include "thirdwindow.h"
#include "ui_secondwindow.h"
#include <vector>

void SecondWindow::fillBoxes() {
    ui->chickenBox->addItem(QString::fromStdString(ms->getChickenOptionNameAtIndex(0)));
    ui->chickenBox->addItem(QString::fromStdString(ms->getChickenOptionNameAtIndex(1)));
    ui->chickenBox->addItem(QString::fromStdString(ms->getChickenOptionNameAtIndex(2)));
    ui->chickenBox->addItem(QString::fromStdString(ms->getChickenOptionNameAtIndex(3)));
    ui->chickenBox->addItem(QString::fromStdString(ms->getChickenOptionNameAtIndex(4)));

    ui->meatBox->addItem(QString::fromStdString(ms->getMeatOptionNameAtIndex(0)));
    ui->meatBox->addItem(QString::fromStdString(ms->getMeatOptionNameAtIndex(1)));
    ui->meatBox->addItem(QString::fromStdString(ms->getMeatOptionNameAtIndex(2)));
    ui->meatBox->addItem(QString::fromStdString(ms->getMeatOptionNameAtIndex(3)));
    ui->meatBox->addItem(QString::fromStdString(ms->getMeatOptionNameAtIndex(4)));
}

SecondWindow::SecondWindow(MainSystem *mainSystem, User *user, QWidget *parent)
    : QDialog(parent), ui(new Ui::SecondWindow), ms(mainSystem) {
    ui->setupUi(this);
    fillBoxes();
    this->user = user;
    this->setWindowTitle("Food Selection");

    // comboboxs start with no selected item.
    ui->chickenBox->setCurrentIndex(-1);
    ui->meatBox->setCurrentIndex(-1);

    ui->accountBalanceLabel->setText("Account Balance: " + QString::number(user->getBalance()) + " LE");

    itemCount = 0;
}

SecondWindow::~SecondWindow() { delete ui; }

void SecondWindow::on_chickenBox_activated(int index) {
    ui->itemPriceLabel->setText("Item Price: " + QString::number(ms->getChickenPriceAtIndex(index)));
    ui->meatBox->setCurrentIndex(-1);
}

void SecondWindow::on_meatBox_activated(int index) {
    ui->itemPriceLabel->setText("Item Price: " + QString::number(ms->getMeatPriceAtIndex(index)));
    ui->chickenBox->setCurrentIndex(-1);
}

void SecondWindow::on_addToCartButton_clicked() {
    if (ui->chickenBox->currentIndex() == -1 && ui->meatBox->currentIndex() == -1) {
        ui->itemPriceLabel->setText("Choose an item first");
        return;
    }

    itemCount++;
    ui->addedItemsCountLabel->setText("Number of added items: " + QString::number(itemCount));
    ui->itemPriceLabel->setText("Item Price: ");

    int selectedChickenIndex = ui->chickenBox->currentIndex();
    int selectedMeatIndex = ui->meatBox->currentIndex();

    if (selectedChickenIndex != -1) {
        selectedItems.push_back(ms->getChickenOptionNameAtIndex(selectedChickenIndex));
        selectedItemsPrices.push_back(ms->getChickenPriceAtIndex(selectedChickenIndex));
    } else if (selectedMeatIndex != -1) {
        selectedItems.push_back(ms->getMeatOptionNameAtIndex(selectedMeatIndex));
        selectedItemsPrices.push_back(ms->getMeatPriceAtIndex(selectedMeatIndex));
    }

    ui->chickenBox->setCurrentIndex(-1);
    ui->meatBox->setCurrentIndex(-1);
}

void openThirdWindow(MainSystem *ms, User *user, vector<string> selectedItems, vector<double> selectedItemsPrices) {
    ThirdWindow thirdWindow(ms, user, selectedItems, selectedItemsPrices);
    thirdWindow.exec();
}

void SecondWindow::on_viewCartButton_clicked() { openThirdWindow(ms, user, selectedItems, selectedItemsPrices); }
