#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
using namespace std;

class User {
private:
    string name;
    string password;
    vector<string> purchasedItems;
    double balance;

public:
    User();
    User(string name, string password, double balance);
    string getName();
    string getPassword();
    vector<string> getPurchasedItems();
    double getBalance();
    void setBalance (double balance ) ;
};

#endif // USER_H
