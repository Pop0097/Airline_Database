//
// Created by Dhruv Rawat on 2020-06-17.
//

#import "Classes.h"

Flight::Flight() {
    flightId = 12345;
    departureDate = "01/01/2021";
    arrivalDate = "01/01/2021";
    departureTime = "0000 ET";
    arrivalTime = "0100 ET";
    departureLocation = "Ottawa, Canada (YOW)";
    arrivalLocation = "Toronto, Canada (YYZ)";
    airplaneType = "Bombardier Q400";
    durationMinutes = 60;
    totalSeats = 76;
    seatsSold = 0;
    seats = new Seat*[totalSeats];
    for(int i = 0; i < totalSeats; i++) {
        seats[i] = new Seat(flightId, (i+1));
    }
    rows = 19;
    columns = 4;
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

    //sets value
    int tempLength = seatsNum; //stores input
    seatsNum = totalSeats; //stores original total seat value
    totalSeats = tempLength; //sets totalSeat value in flight object to the input value

    if(tempLength < seatsNum) { //if there are less seats in the new plane than before, then the seats will be modified
        this->adjustPassengerSeats(seatsNum); //passes the original number of seats that were present
    } else { //if there are more seats in the new plane than before, all passengers retain their current seats
        Seat ** tempArray = seats;
        seats = new Seat * [totalSeats];
        for(int i = 0; i < totalSeats; i++) {
            if(i < seatsNum) {
                seats[i] = tempArray[i];
            } else {
                seats[i] = new Seat(flightId, (i+1));
            }
        }
    }
}

void Flight::adjustPassengerSeats(int originalSeatNum) {
    /*
     * Idea for this part:
     * If the user's ticket number still exists, they will retain their current seat. If not, then they will be placed in reverse order starting from the back of the plane.
     */

    Seat ** tempArray = seats;
    seats = new Seat * [totalSeats];
    for(int i = 0; i < totalSeats; i++) { //reinitializes seats array
        seats[i] = tempArray[i];
    }

    bool seatFound = false;
    int j = totalSeats-1, counter = 1;
    cout << endl;
    cout << "Notify these passengers that their seat has changed: " << endl;
    for(int i = (originalSeatNum-1); i >= totalSeats; i--) { //goes through all seats that will not be present on the smaller plane in reverse order
        seatFound = false;
        if(tempArray[i]->getReservationStatus()) { //if a seat is reserved
            while(!seatFound) { //Finding new seat loop starts
                if(!seats[j]->getReservationStatus()) { //If the seat is not reserved
                    seats[j] = tempArray[i]; //passenger placed at seat
                    seats[j]->setSeatNumber(j+1);
                    //Tells employee to update these passengers
                    cout << counter << ". ";
                    seats[j]->displayTicketSummary();
                    cout << endl;
                    seatFound = true;
                    counter++;
                }
                j--;
            } //Finding new seat loop ends
        }
    }
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
    seats[s]->setBooking(n, b, e, p, a, this->getFlightNumber());
}

void Flight::findTicket(int confirmation, int operation) { //operation = 1 means view ticket. operation = 2 means cancel ticket
    cout << endl;
    bool found = false;
    for(int i = 0; i < totalSeats; i++) {
        if(confirmation == seats[i]->getConfirmationNum()) {
            found = true;
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

    if(!found) { //if ticket is not found
        cout << endl;
        cout << "Ticket not found." << endl;
        cout << endl;
    }
}

void Flight::updateSeat(string email, string phone, string add, int confirmation, int seatNum) {
    int originalSeatNum = -1;
    for(int i = 0; i < totalSeats; i++) {
        if (confirmation == seats[i]->getConfirmationNum()) {
            originalSeatNum = i;
        }
    }

    //updates the values only if the user did not enter the value to "skip" the field and if the confirmation number matches a ticket
    if(email != "0" && originalSeatNum != -1) {
        seats[originalSeatNum]->setCustomerEmail(email);
    }
    if(phone != "0" && originalSeatNum != -1) {
        seats[originalSeatNum]->setCustomerPhone(phone);
    }
    if(add != "0" && originalSeatNum != -1) {
        seats[originalSeatNum]->setCustomerAdd(add);
    }
    if(seatNum != -1 && originalSeatNum != -1) {
        //switches seats
        Seat * tempSeat = seats[seatNum];
        seats[seatNum] = seats[originalSeatNum];
        seats[originalSeatNum] = tempSeat;
        //re-initializes the seat numbers
        seats[seatNum]->setSeatNumber(seatNum+1);
        seats[originalSeatNum]->setSeatNumber(originalSeatNum+1);
    }

    if(originalSeatNum == -1) { //if ticket is not found
        cout << endl;
        cout << "Ticket not found." << endl;
        cout << endl;
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
            if(counter < 10) {
                cout << "X   ";
            } else if(counter >= 10 && counter < 100) {
                cout << "X  ";
            } else {
                cout << "X ";
            }
        } else {
            if(counter < 10) {
                cout << counter << "   ";
            } else if(counter >= 10 && counter < 100) {
                cout << counter << "  ";
            } else {
                cout << counter << " ";
            }
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
