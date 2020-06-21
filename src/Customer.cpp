//
// Created by Dhruv Rawat on 2020-06-17.
//

#import "Classes.h"

Customer::Customer() { // Sets default values for Customer object
    name = "Default Name";
    birthDate = "Default Dirthdate";
    email = "Default Email";
    phoneNumber = "Default Phone Number";
    address = "Defaut Address";
    confirmationNumber = 0;
    seatNumber = 0;
    flightNumber = 0;
}

Customer::Customer(string n, string b, string e, string p, string a, int s, int confirmation, int fNum) {
    name = n;
    birthDate = b;
    email = e;
    phoneNumber = p;
    address = a;
    seatNumber = s;
    flightNumber = fNum;
    confirmationNumber = confirmation;
    cout << confirmationNumber << endl;
}

string Customer::getName() {
    return name;
}

string Customer::toString() {
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Phone number: " << phoneNumber << endl;
    cout << "Address: " << address << endl;
    return "";
}
