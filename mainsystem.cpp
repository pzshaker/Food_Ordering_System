#include "mainsystem.h"
using namespace std;

MainSystem::MainSystem() {
    for (int i = 0; i < 5; i++) {
        users[i] = nullptr;
    }
}

void MainSystem::addUser(User *user) {
    for (int i = 0; i < 5; i++) {
        if (users[i] == nullptr) {
            users[i] = user;
            break;
        }
    }
}

void MainSystem::addChicken(string chickenOptionName, double chickenPrice) {
    for (int i = 0; i < 5; i++) {
        if (chickenOptionsName[i] == "") {
            chickenOptionsName[i] = chickenOptionName;
            break;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (chickenPrices[i] == 0) {
            chickenPrices[i] = chickenPrice;
            break;
        }
    }
}

void MainSystem::addMeat(string meatOptionName, double meatPrice) {
    for (int i = 0; i < 5; i++) {
        if (meatOptionsName[i] == "") {
            meatOptionsName[i] = meatOptionName;
            break;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (meatPrices[i] == 0) {
            meatPrices[i] = meatPrice;
            break;
        }
    }
}

bool MainSystem::isExist(string name) {
    for (int i = 0; i < 5; i++) {
        if (users[i] != nullptr && users[i]->getName() == name) {
            return true;
        }
    }
    return false;
}

bool MainSystem::isValidPass(string name, string password) {
    for (int i = 0; i < 5; i++) {
        if (users[i] != nullptr && users[i]->getName() == name) {
            if (users[i] != nullptr && users[i]->getPassword() == password) {
                return true;
            }
        }
    }
    return false;
}

User *MainSystem::getUser(string name) {
    for (int i = 0; i < 5; i++) {
        if (users[i] != nullptr && users[i]->getName() == name) {
            return users[i];
        }
    }
    return nullptr;
}

string MainSystem::getChickenOptionNameAtIndex(int index) {
    return chickenOptionsName[index];
}

double MainSystem::getChickenPriceAtIndex(int index) {
    return chickenPrices[index];
}

string MainSystem::getMeatOptionNameAtIndex(int index) {
    return meatOptionsName[index];
}

double MainSystem::getMeatPriceAtIndex(int index) {
    return meatPrices[index];
}
