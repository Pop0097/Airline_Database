//
// Created by Dhruv Rawat on 2020-06-17.
//

#import "Classes.h"

Flight::Flight() {
    flightId = 1;
    departureDate = "Default Departure Date";
    arrivalDate = "Default Arrival Date";
    departureTime = "Default Departure Time";
    arrivalTime = "Default Arrival Time";
    departureLocation = "Default Departure Time";
    arrivalLocation = "Default Arrival Time";
    airplaneType = "Default Airplane Type";
    durationMinutes = 0;
    totalSeats = 10;
    seatsSold = 0;
    seats = new Seat*[totalSeats];
    for(int i = 0; i < 10; i++) {
        seats[i] = new Seat(flightId, (i+1));
    }
    rows = 4;
    columns = 3;
}

Flight::Flight(int num, int duration, int seatsNum, string depDate, string depTime, string depLoc, string arrDate, string arrTime, string arrLocation, string planeType) {
    flightId = num;
    durationMinutes = duration;
    if(seatsNum > 700){ //maximum plane size for this airline will be set to 700
        totalSeats = 700;
    } else {
        totalSeats = seatsNum;
    }
    departureDate = depDate;
    departureTime = depTime;
    departureLocation = depLoc;
    arrivalDate = arrDate;
    arrivalLocation = arrLocation;
    arrivalTime = arrTime;
    airplaneType = planeType;
    seatsSold = 0;
    seats = new Seat*[totalSeats];
    for(int i = 0; i < totalSeats; i++) {
        seats[i] = new Seat();
    }
    //Sets rows and columns according to the number of seats in the plane
    if(totalSeats <= 40){
        columns = 3;
    } else if(totalSeats > 40 && totalSeats <= 100) {
        columns = 4;
    } else if (totalSeats > 100 && totalSeats <= 250) {
        columns = 6;
    } else if (totalSeats > 250 && totalSeats <= 350) {
        columns = 9;
    } else {
        columns = 10;
    }
    int remaining = totalSeats%columns;
    rows = floor(totalSeats/columns);
    rows += remaining;
    cout << "Columns: " << columns << "; Rows: " << rows << endl;
}

Flight::~Flight(){}

int Flight::getFlightNumber() {
    return flightId;
}

string Flight::getDepartureLocation() {
    return departureLocation;
}

string Flight::getDepartureDate() {
    return departureDate;
}

string Flight::getDepartureTime() {
    return departureTime;
}

string Flight::getArrivalLocation() {
    return arrivalLocation;
}

string Flight::getArrivalDate() {
    return arrivalDate;
}

string Flight::getArrivalTime() {
    return arrivalTime;
}

int Flight::getSeatsSold() {
    return seatsSold;
}

void Flight::setFlightNumber(int num) {
    flightId = num;
}

void Flight::setFlightDuration(int dur) {
    durationMinutes = dur;
}

void Flight::setTotalSeats(int seatsNum) {
    if(seatsNum > 700){ //maximum plane size for this airline will be set to 700
        seatsNum = 700;
    }
    //Updates rows and columns according to the number of seats in the plane
    if(seatsNum <= 40){
        columns = 3;
    } else if(seatsNum > 40 && seatsNum <= 100) {
        columns = 4;
    } else if (seatsNum > 100 && seatsNum <= 250) {
        columns = 6;
    } else if (seatsNum > 250 && seatsNum <= 350) {
        columns = 9;
    } else {
        columns = 10;
    }
    int remaining = seatsNum%columns;
    rows = floor(seatsNum/columns);
    rows += remaining;
    cout << "Columns: " << columns << "; Rows: " << rows << endl;
    //adjusts passenger seats to smaller planes by changing rows and columns
    //sets value
    int tempLength = seatsNum; //stores input
    seatsNum = totalSeats; //stores original total seat value
    totalSeats = tempLength;
    Seat ** tempArray = seats;
    seats = new Seat * [totalSeats];
    if(tempLength < seatsNum) {
        this->adjustPassengerSeats();
    } else {
        for(int i = 0; i < totalSeats; i++) {
            if(i < seatsNum) {
                seats[i] = tempArray[i];
            } else {
                seats[i] = new Seat(flightId, (i+1));
            }
        }
    }
}

void Flight::adjustPassengerSeats() {
    /* Do later */
}

void Flight::setAirplaneType(string airplane) {
    airplaneType = airplane;
}

void Flight::setDepartureLocation(string loc) {
    departureLocation = loc;
}

void Flight::setDepartureDate(string date) {
    departureDate = date;
}

void Flight::setDepartureTime(string time) {
    departureTime = time;
}

void Flight::setArrivalLocation(string loc) {
    arrivalLocation = loc;
}

void Flight::setArrivalDate(string date) {
    arrivalDate = date;
}

void Flight::setArrivalTime(string time) {
    arrivalTime = time;
}

void Flight::setTicketReservation(string n, string b, string e, string p, string a, int s){
    cout << "Here0 " << endl;
    seats[s]->setBooking(n, b, e, p, a, this->getFlightNumber());
}

void Flight::findTicket(int confirmation, int operation) { //operation = 1 means view ticket. operation = 2 means cancel ticket
    cout << endl;
    for(int i = 0; i < totalSeats; i++) {
        if(confirmation == seats[i]->getConfirmationNum()) {
            if(operation == 1) {
                seats[i]->toString();
                cout << endl;
                cout << "Flight Information:" << endl;
                this->toString();
            } else if(operation == 2) {
                //gets confirmation from user
                string confirmation = "";
                cout << "Are you sure? (Enter \"y\" or \"n\"): ";
                cin.ignore();
                getline(cin, confirmation);
                if(confirmation == "y") { //if user confirms
                    seats[i] = new Seat(flightId, (i+1)); //resets Seat object
                } else {
                    cout << endl;
                    cout << "Process canceled." << endl;
                    cout << endl;
                }
            }
        }
    }
}

string Flight::displayPassengerList() {
    cout << "All passengers on flight " << flightId << ":" << endl;
    int counter = 0;
    for(int i = 0; i < totalSeats; i++ && counter <= seatsSold) {
        if(seats[i]->getReservationStatus()) {
            counter++;
            cout << counter << ": " << seats[i]->displayTicketSummary() << endl;
        }
    }
    if(counter == 0) {
        cout << endl;
        cout << "No tickets have been sold yet." << endl;
        cout << endl;
    }
    return "";
}

void Flight::displaySeatingChart() {
    int counter = 1;
    cout << "\"X\" means the seat is taken" << endl;
    cout << "Front of the plane" << endl;
    for(int i = 0; i < totalSeats; i++) {
        if(seats[i]->getReservationStatus()) {
            cout << "X ";
        } else {
            cout << counter << " ";
        }
        if((i+1)%columns == 0) {
            cout << endl;
        }
        counter++;
    }
    cout << endl;
}

string Flight::toString() {
    cout << "Flight " << flightId << ":" << endl;
    cout << "Airplane model: " << airplaneType << endl;
    cout << "Total seats: " << totalSeats << endl;
    cout << "Departure information: " << departureLocation << "; " << departureDate << " at " << departureTime << endl;
    cout << "Arrival information: " << arrivalLocation << "; " << arrivalDate << " at " << arrivalTime << endl;
    cout << "Flight duration: " << durationMinutes << endl;
    return "";
}
