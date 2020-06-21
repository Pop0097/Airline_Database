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
        seats[i] = new Seat();
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
    //adjusts passenger seats to smaller planes by changing rows and columns
    if(seatsNum < totalSeats) {
        this->adjustPassengerSeats();
    }
    //sets value
    totalSeats = seatsNum;
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

string Flight::displayPassengerList() {
    cout << "All passengers on flight " << flightId << ":" << endl;
    int counter = 0;
    for(int i = 0; i < totalSeats; i++ && counter <= seatsSold) {



        /* Write code later */



    }
    if(counter == 0) {
        cout << endl;
        cout << "No tickets have been sold yet." << endl;
        cout << endl;
    }
    return "";
}

string Flight::toString() {
    cout << "Flight " << flightId << ":" << endl;
    cout << "Airplane model: " << airplaneType << endl;
    cout << "Total seats: " << totalSeats << endl;
    cout << "Departure information: " << departureLocation << "; " << departureDate << " at " << departureTime << endl;
    cout << "Arrival information: " << arrivalLocation << "; " << arrivalDate << " at " << arrivalTime << endl;
    cout << "Flight duration: " << durationMinutes << endl;
    cout << "Percent of seats purchased: " << (round(seatsSold / totalSeats * 1000) / 10) << endl;
    return "";
}
