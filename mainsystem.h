#ifndef MAINSYSTEM_H
#define MAINSYSTEM_H

#include <string>
using namespace std;

#include "user.h"

class MainSystem {
private:
    User *users[5];
    string chickenOptionsName[5];
    double chickenPrices[5] = {0};
    string meatOptionsName[5];
    double meatPrices[5] = {0};

public:
    MainSystem();
    void addUser(User *user);
    void addChicken(string chickenOptionName, double chickenPrice);
    void addMeat(string meatOptionName, double meatPrice);
    bool isExist(string name);
    bool isValidPass(string name, string password);
    User *getUser(string name);
    string getChickenOptionNameAtIndex(int index);
    double getChickenPriceAtIndex(int index);
    string getMeatOptionNameAtIndex(int index);
    double getMeatPriceAtIndex(int index);
};

#endif // MAINSYSTEM_H
