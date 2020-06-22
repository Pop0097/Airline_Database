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
    cout << "Here" << endl;
    srand (time(0));
    confirmationNum = rand()%10+1;
    cout << confirmationNum << endl;
    person = new Customer(n, b, e, p, a, seatNumber, confirmationNum, fNum);
    reserved = true;
}

string Seat::displayTicketSummary() {
    cout << "Name: " << person->getName() << "; Email: " << person->getEmail() << "; Phone: " << person->getPhoneNumber();
    return "";
}

string Seat::toString() {
    cout << "Seat number " << seatNumber << " on flight " << flight << ":" << endl;
    cout << "Ticket Holder: (Confirmation number: " << confirmationNum << ")" << endl;
    person->toString();
    return "";
}
