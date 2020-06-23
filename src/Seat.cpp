//
// Created by Dhruv Rawat on 2020-06-17.
//

#import "Classes.h"

Seat::Seat() { //sets default values
    flight = 0;
    seatNumber = 0;
    person = new Customer();
    reserved = false;
    confirmationNum = 1;
}

Seat::Seat(int num, int seatnum) {
    flight = num;
    seatNumber = seatnum;
    person = new Customer();
    reserved = false;
}

bool Seat::getReservationStatus() {
    return reserved;
}

int Seat::getConfirmationNum() {
    return confirmationNum;
}

void Seat::setBooking(string n, string b, string e, string p, string a, int fNum) {
    srand (time(0));
    confirmationNum = rand()%8999999+1000000;
    cout << confirmationNum << endl;
    person = new Customer(n, b, e, p, a, seatNumber, confirmationNum, fNum);
    reserved = true;
}

void Seat::setCustomerEmail(string e) {
    person->setEmail(e);
}

void Seat::setCustomerPhone(string p) {
    person->setPhone(p);
}

void Seat::setCustomerAdd(string add) {
    person->setAdd(add);
}

void Seat::setSeatNumber(int num) {
    seatNumber = num;
}

string Seat::displayTicketSummary() {
    cout << "Name: " << person->getName() << "; Email: " << person->getEmail() << "; Phone: " << person->getPhoneNumber() << "; Seat: " << seatNumber;
    return "";
}

string Seat::toString() {
    cout << "Seat number " << seatNumber << ":" << endl;
    cout << "Ticket Holder: (Confirmation number: " << confirmationNum << ")" << endl;
    person->toString();
    return "";
}
