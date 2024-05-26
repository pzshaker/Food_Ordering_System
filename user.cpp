#include "user.h"
#include <string>
using namespace std;

User::User() {}

User::User(string name, string password, double balance) {
    this->name = name;
    this->password = password;
    this->balance = balance;
}

string User::getName() { return name; }

string User::getPassword() { return password; }

vector<string> User::getPurchasedItems() { return purchasedItems; }

double User::getBalance() { return balance; }

void User::setBalance (double balance1 ) { this->balance=balance1 ;}
