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
}

string Customer::getName() {
    return name;
}

string Customer::getEmail() {
    return email;
}

string Customer::getPhoneNumber() {
    return phoneNumber;
}

void Customer::setEmail(string e) {
    email = e;
}

void Customer::setPhone(string p) {
    phoneNumber = p;
}

void Customer::setAdd(string add) {
    address = add;
}

string Customer::toString() {
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Phone number: " << phoneNumber << endl;
    cout << "Address: " << address << endl;
    return "";
}
