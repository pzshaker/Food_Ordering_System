#include "mainsystem.h"
#include "signinwindow.h"
#include "user.h"

#include <QApplication>

void fillMainSystem(MainSystem &ms);

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainSystem ms;
    fillMainSystem(ms);

    SigninWindow w(&ms);
    w.show();
    return a.exec();
}

void fillMainSystem(MainSystem &ms) {
    User *user1 = new User("philo", "123", 50);
    User *user2 = new User("youssef", "321", 70);
    User *user3 = new User("Omar", "213", 100);

    ms.addUser(user1);
    ms.addUser(user2);
    ms.addUser(user3);

    ms.addChicken("Grilled Chicken", 5.99);
    ms.addChicken("Fried Chicken", 6.99);
    ms.addChicken("Roasted Chicken", 7.99);
    ms.addChicken("BBQ Chicken", 8.99);
    ms.addChicken("Honey Chicken", 7.49);

    ms.addMeat("Beef Steak", 12.99);
    ms.addMeat("Beef Burger", 9.99);
    ms.addMeat("Lamb Rack", 15.99);
    ms.addMeat("Turkey Cutlet", 8.49);
    ms.addMeat("Venison Steak", 20.49);
}
