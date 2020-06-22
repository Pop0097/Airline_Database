//
// Created by Dhruv Rawat on 2020-06-18.
//

#include "Classes.h"

Airline::Airline() {
    employeeNumber = 1;
    employees = new Employee * [employeeNumber];
    employees[0] = new Employee();
    flightNumber = 1;
    flights = new Flight * [flightNumber];
    flights[0] = new Flight();
    airlineName = "Air Pop0097";
}

int Airline::employeeLogin(string uname, string pass) {
    bool valid = false;
    int userNumber = 0;
    Employee * tempEmployee = new Employee();
    string inputPass = tempEmployee->passwordEncrypt(pass, "A5HDUQ71JRBC0SK2HRU");
    delete tempEmployee;

    for(int i = 0; i < employeeNumber; i++){ //checks all employees of airline
        //checks if credentials match that of an employee
        if(employees[i]->getUsername() == uname && employees[i]->getEncryptedPassword() == inputPass) {
            valid = true;
            userNumber = i;
        }
    }

    if(valid) { //if credentials are correct
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "You're logged in. Welcome!" << endl;
        cout << endl;
        cout << endl;
        return userNumber;
    } else { //if credentials are incorrect
        cout << endl;
        cout << "Credentials are incorrect. Please try again." << endl;
        cout << endl;
        return -1;
    }
}

string Airline::getAirlineName() {
    return airlineName;
}

void Airline::viewEmployeeAccount(int userNumber) {
    cout << "Your account information: " << endl;
    employees[userNumber]->toString();
    cout << endl;
}

void Airline::editEmployeeAccount(int userNumber) {
    cout << "Your current account information: " << endl;
    employees[userNumber]->toString();
    cout << endl;
    cout << endl;
    //Gets inputs
    string name = "", employeeID = "", uname = "", pass = "";
    cin.ignore();
    cout << "Fill in the fields. (If you don't want to change a field, enter \"0\". To cancel the process, enter \"0\" into all fields)" << endl;
    cout << "Name: ";
    getline(cin, name);
    cout << "Employee ID: " ;
    getline(cin, employeeID);
    cout << "Username: ";
    getline(cin, uname);
    cout << "Password: ";
    getline(cin, pass);

    if(name == "0" && employeeID == "0" && uname == "0" && pass == "0") { //if user cancels process
        cout << endl;
        cout << "Process canceled." << endl;
        cout << endl;
    } else {
        if(name != "0") {
            employees[userNumber]->setName(name);
        }
        if(employeeID != "0") {
            employees[userNumber]->setEmployeeId(employeeID);
        }
        if(uname != "0") {
           employees[userNumber]->setUsername(uname) ;
        }
        if(pass != "0") {
            employees[userNumber]->setPassword(pass);
        }
        cout << endl;
        cout << "Updated account information" << endl;
        employees[userNumber]->toString();
        cout << endl;
    }
}

void Airline::createEmployeeAccount() {
    //Gets inputs
    string name = "", employeeID = "", uname = "", pass = "";
    cin.ignore();
    cout << "Fill in the fields. (If you don't want to set a field, enter \"0\". To cancel the process, enter \"0\" into all fields)" << endl;
    cout << "Name: ";
    getline(cin, name);
    cout << "Employee ID: " ;
    getline(cin, employeeID);
    Employee * newEmployee = new Employee(name, employeeID); //creates new employee object
    cout << "The employee's temporary username is " << name << " and their temporary password is \"pass\"" << endl;

    //Re-defines and re-initializes employees array
    employeeNumber++;
    Employee ** tempArray = employees;
    employees = new Employee * [employeeNumber];
    for(int i = 0; i < employeeNumber; i++) {
        if(i < employeeNumber-1) {
            employees[i] = tempArray[i];
        } else {
            employees[i] = newEmployee;
        }
    }
    cout << endl;
    cout << "Employee account information:" << endl; //displays new employee account
    employees[employeeNumber-1]->toString();
    cout << endl;
}

bool Airline::findEmployees(int userNumber) {
    bool done = false, canceled = false;
    cin.ignore();
    string name = "", empName = "";
    int found = 0;

    while(!done) { //Employee search loop starts
        //gets input
        cout << "Search for an employee (Enter employee name. Type \"0\" to cancel): ";
        getline(cin, name);

        if(name == "0"){ //if user cancels search
            done = true;
            canceled = true;
            cout << endl;
            cout << "Process canceled." << endl;
            cout << endl;
        } else {
            for(int i = 0; i < employeeNumber; i++) { //searches all employees to find those that match the input
                empName = employees[i]->getName();
                found = empName.find(name);
                if(i != userNumber && found != -1) { //if employees match the input (and are not the current user)
                    done = true;
                    cout << "(Type \"" << (i+1) << "\") | " << employees[i]->getName() << " (ID: " << employees[i]->getEmployeeId() << ")" << endl;
                }
            }

            if(!done) {
                cout << endl;
                cout << "None of the employees matched your search." << endl;
                cout << endl;
            }
        }
    } //Employee search loop ends
    return canceled;
}

int Airline::deleteEmployeeAccount(int userNumber) {
    bool search = findEmployees(userNumber); //calls function to search for employees

    if(!search) { //if user did not cancel the search
        int decision = 0;
        cout << "Choose a user to delete (Type \"0\" to cancel): ";
        cin >> decision;

        if(decision > 0) { //user does not cancel process
            decision--;
            if(decision < userNumber) {
                userNumber--;
            }

            //Re-defines and re-initializes employees array
            employeeNumber--;
            Employee ** tempArray = employees;
            employees = new Employee * [employeeNumber];
            for(int i = 0; i < employeeNumber; i++){
                if(i < decision) {
                    employees[i] = tempArray[i];
                } else {
                    employees[i] = tempArray[i+1];
                }
            }
            cout << endl;
            cout << "Employee deleted." << endl;
            cout << endl;
        } else {
            cout << endl;
            cout << "Process canceled." << endl;
            cout << endl;
        }
    }
    return userNumber;
}

void Airline::createFlight() {
    cout << "Fill in all of the fields (Type \"0\" into at least one of the fields to cancel):" << endl;
    //gets inputs
    int flightNum = 0, durationMinutes = 0, totalSeats = 0;
    string airplaneType = "", departureDate = "", departureTime = "", arrivalTime = "", departureLocation = "", arrivalLocation = "", arrivalDate= "";
    //ensures flight number input is valid
    bool valid = false;
    while(!valid) {
        cout << "Flight Number (Number between 10000 and 99999 inclusive): ";
        cin >> flightNum;
        if(flightNum >= 10000 && flightNum <= 99999) {
            valid = true;
        } else {
            cout << "Invalid input." << endl;
        }
    }
    cout << "Airplane model: ";
    cin.ignore();
    getline(cin, airplaneType);
    cout << "Total seats: ";
    cin >> totalSeats;
    cout << "Departure location (Format: \"City name, Country (airport code)\"): ";
    cin.ignore();
    getline(cin, departureLocation);
    cout << "Departure date (Format: DD/MM/YYYY): ";
    getline(cin, departureDate);
    cout << "Departure time (Format: \"24 hour time (Time zone)\"): ";
    getline(cin, departureTime);
    cout << "Arrival location (Format: \"City name, Country (airport code)\"): ";
    getline(cin, arrivalLocation);
    cout << "Arrival date (Format: DD/MM/YYYY): ";
    getline(cin, arrivalDate);
    cout << "Arrival time (Format: \"24 hour time (Time zone)\"): ";
    getline(cin, arrivalTime);
    cout << "Flight duration (minutes): ";
    cin >> durationMinutes;

    //checks if any of the fields are "0" because that means the employee wants to cancel the process
    if(flightNum == 0 || totalSeats == 0 || durationMinutes == 0 || airplaneType == "0" || departureLocation == "0" || departureDate == "0" || departureTime == "0" || arrivalLocation == "0" || arrivalDate == "0" || arrivalTime == "0") {
        cout << endl;
        cout << "Process canceled." << endl;
        cout << endl;
    } else {
        flightNumber++;
        //creates new flight with provided inputs
        Flight * newFlight = new Flight(flightNum, durationMinutes, totalSeats, departureDate, departureTime, departureLocation, arrivalDate, arrivalTime, arrivalLocation, airplaneType);
        //Re-defines and re-initializes flights array
        Flight ** tempArray = flights;
        flights = new Flight*[flightNumber];
        for(int i = 0; i < flightNumber; i++) {
            if(i < flightNumber - 1) {
                flights[i] = tempArray[i];
            } else {
                cout << "Adding to array" << endl;
                flights[i] = newFlight; //adds new flight to array
            }
        }
        cout << endl;
        flights[flightNumber - 1]->toString(); //displays the new flight
        cout << endl;
    }
}

bool Airline::findFlights() { //method used to search for flights to improve UI
    bool done = false, canceled = false;
    cin.ignore();
    string flightNum = "", num = "";
    int found = 0;

    while(!done) { //Flight search loop starts
        //gets input
        cout << "Search for a flight (Enter flight number. Type \"0\" to cancel): ";
        getline(cin, flightNum);

        if(flightNum == "0"){ //if user cancels search
            done = true;
            canceled = true;
            cout << endl;
            cout << "Process canceled." << endl;
            cout << endl;
        } else {
            for(int i = 0; i < flightNumber; i++) { //searches all flights to find those that match the search
                num = to_string(flights[i]->getFlightNumber());
                found = num.find(flightNum);
                if(found != -1) { //if flight match the input, it is displayed
                    done = true;
                    cout << "(Type \"" << (i+1) << "\") | Flight " << num << ". " <<  "Departure information: " << flights[i]->getDepartureLocation() << "; " << flights[i]->getDepartureDate() << " at " << flights[i]->getDepartureTime() << endl;
                }
            }

            if(!done) {
                cout << endl;
                cout << "None of the flights matched your search." << endl;
                cout << endl;
            }
        }
    } //Flight search loop ends
    return canceled;
}

void Airline::viewFlight() {
    bool search = findFlights(); //user searches for a flight to view

    if(!search) { //if user did not cancel the process
        int decision = 0;
        cout << "Choose a flight to view (Type \"0\" to cancel): ";
        cin >> decision;
        if(decision > 0) { //if user does not cancel, then flight is displayed
            decision--;
            flights[decision]->toString();
            cout << endl;
            cout << "View passenger list (enter \"y\" or \"n\"): "; //option to view all passengers on the flight
            cin.ignore();
            string choice = "";
            getline(cin, choice);
            if(choice == "y") { //if user decides to view passenger list, following function is called in Flights class
                flights[decision]->displayPassengerList();
            }
        } else {
            cout << endl;
            cout << "Process canceled." << endl;
            cout << endl;
        }
    }
}

void Airline::editFlight() {
    bool search = findFlights();  //user searches for a flight to edit

    if(!search) {
        int decision = 0;
        cout << "Choose a flight to view (Type \"0\" to cancel): ";
        cin >> decision;
        if(decision > 0) { //if user does not cancel, then flight is edited
            decision--;
            cout << "Fill in all of the fields (Type \"0\" in a field to not change it. Type \"0\" into all fields to cancel):" << endl;
            //gets inputs
            int flightNum = 0, durationMinutes = 0, totalSeats = 0;
            string airplaneType = "", departureDate = "", departureTime = "", arrivalTime = "", departureLocation = "", arrivalLocation = "", arrivalDate= "";
            //ensures flight number input is valid
            bool valid = false;
            while(!valid) {
                cout << "Flight Number (Number between 10000 and 99999 inclusive): ";
                cin >> flightNum;
                if(flightNum >= 10000 && flightNum <= 99999) {
                    valid = true;
                } else {
                    cout << "Invalid input." << endl;
                }
            }
            cout << "Airplane model: ";
            cin.ignore();
            getline(cin, airplaneType);
            cout << "Total seats: ";
            cin >> totalSeats;
            cout << "Departure location (Format: \"City name, Country (airport code)\"): ";
            cin.ignore();
            getline(cin, departureLocation);
            cout << "Departure date (Format: DD/MM/YYYY): ";
            getline(cin, departureDate);
            cout << "Departure time (Format: \"24 hour time (Time zone)\"): ";
            getline(cin, departureTime);
            cout << "Arrival location (Format: \"City name, Country (airport code)\"): ";
            getline(cin, arrivalLocation);
            cout << "Arrival date (Format: DD/MM/YYYY): ";
            getline(cin, arrivalDate);
            cout << "Arrival time (Format: \"24 hour time (Time zone)\"): ";
            getline(cin, arrivalTime);
            cout << "Flight duration (minutes): ";
            cin >> durationMinutes;

            //Sets new values after checking if the inputted value is not "0"
            if(flightNum != 0) {
                flights[decision]->setFlightNumber(flightNum);
            }
            if(durationMinutes != 0) {
                flights[decision]->setFlightDuration(durationMinutes);
            }
            //to ensure the airline does not accidentally cancel a customer's seat, the program ensures that the new seat number is at least as much as the number of tickets sold
            if(totalSeats < flights[decision]->getSeatsSold()) {
                cout << "Total seats and airplane type will not be updated as you cannot reduce the seat number below the amount already sold." << endl;
            } else if (totalSeats != 0 && totalSeats >= flights[decision]->getSeatsSold()) {
                flights[decision]->setTotalSeats(totalSeats);
                if(airplaneType != "0") { //if seats can be changed, then so can the airplane type :))
                    flights[decision]->setAirplaneType(airplaneType);
                }
            }
            if(departureLocation != "0") {
                flights[decision]->setDepartureLocation(departureLocation);
            }
            if(departureDate != "0") {
                flights[decision]->setDepartureDate(departureDate);
            }
            if(departureTime != "0") {
                flights[decision]->setDepartureTime(departureTime);
            }
            if(arrivalLocation != "0") {
                flights[decision]->setArrivalLocation(arrivalLocation);
            }
            if(arrivalDate != "0") {
                flights[decision]->setArrivalDate(arrivalDate);
            }
            if(arrivalTime != "0") {
                flights[decision]->setArrivalTime(arrivalTime);
            }

            //prints updated information
            cout << endl;
            cout << "Updated flight information:" << endl;
            flights[decision]->toString();
            cout << endl;
        } else {
            cout << endl;
            cout << "Process canceled." << endl;
            cout << endl;
        }
    }
}

void Airline::deleteFlight() {
    bool search = findFlights(); //user searches for a flight to delete
    int decision = -1;
    string confirmation = "";

    if(!search) { //if user did not cancel the process
        cout << "Choose a flight to view (Type \"0\" to cancel): ";
        cin >> decision;
        decision--;
        if(decision > -1) { //if user does not cancel, then flight is displayed
            cout << "Are you sure (Type \"y\" or \"n\"): ";
            cin.ignore();
            getline(cin, confirmation);
            if(confirmation == "y"){
                cout << "Contact all passenger to notify them of this cancellation:" << endl;
                flights[decision]->displayPassengerList();
                //Re-defines and re-initializes flights array
                flightNumber--;
                Flight ** tempArray = flights;
                flights = new Flight*[flightNumber];
                for(int i = 0; i < flightNumber; i++) {
                    if(i < decision) {
                        flights[i] = tempArray[i];
                    } else {
                        flights[i] = tempArray[i+1];
                    }
                }
            }
        }
    }

    if(decision == 0 || confirmation == "n") { //if user canceled process
        cout << endl;
        cout << "Process canceled." << endl;
        cout << endl;
    }
}

bool Airline::searchFlightByDateAndCity() {
    string date = "", depCity = "", arrCity = "", choice = "";
    int found = 0, found1 = 0, found2 = 0;
    bool done = false, redoDepCity = true, redoArrCity = true, cancel = false;
    cin.ignore();
    while(!done) {
        cout << "Fill in the fields (Enter \"0\" into the first field to cancel):" << endl;
        cout << "Preferred departure date (DD/MM/YYYY): ";
        getline(cin, date);
        if(redoDepCity == true) {
            cout << "Departure city (City name or airport code): ";
            getline(cin, depCity);
            redoDepCity = false;
        }
        if(redoArrCity == true) {
            cout << "Arrival city (City name or airport code): ";
            getline(cin, arrCity);
            redoArrCity = false;
        }

        if(date == "0") {
            done = true;
            cancel = true;
            cout << endl;
            cout << "Process canceled." << endl;
            cout << endl;
        } else {
            for(int i = 0; i < flightNumber; i++) { //searches all flights to find those that match the search
                found = flights[i]->getDepartureDate().find(date);
                found1 = flights[i]->getDepartureLocation().find(depCity);
                found2 = flights[i]->getArrivalLocation().find(arrCity);
                if(found != -1 && found1 != -1 && found2 != -1) { //if flight match the inputs, it is displayed
                    done = true;
                    cout << "(Type \"" << (i+1) << "\") | Flight " << flights[i]->getFlightNumber() << ". " <<  "Departure information: " << flights[i]->getDepartureLocation() << "; " << flights[i]->getDepartureDate() << " at " << flights[i]->getDepartureTime() << endl;
                }
            }

            if(!done) {
                cout << endl;
                cout << "None of the flights matched your search. Choose a different date." << endl;
                //sees if customer wants to change the cities
                cout << "Would you like to select a different departure city? (Type \"y\" or \"n\"): ";
                getline(cin, choice);
                if(choice == "y") {
                    redoDepCity = true;
                }
                cout << "Would you like to select a different arrival city? (Type \"y\" or \"n\"): ";
                getline(cin, choice);
                if(choice == "y") {
                    redoArrCity = true;
                }
                cout << endl;
            }
        }

    }
    return cancel;
}

void Airline::bookTicket() {
    bool search = this->searchFlightByDateAndCity(); //searches for flight user wants to book
    int decision = 0;
    if(!search) {//if user did not cancel
        cout << "Choose a flight (Type \"0\" to cancel): ";
        cin >> decision;
        if(decision != 0) {
            decision--;
            cin.ignore();
            //gets inputs
            cout << "Fill in all of the fields (Type \"0\" into at least one of the fields to cancel):" << endl;
            string name = "", birth = "", email = "", phone = "", address = "";
            int seat = 0, flight = 0;
            cout << "Name: ";
            getline(cin, name);
            cout << "Email: ";
            getline(cin, email);
            cout << "Phone Number: ";
            getline(cin, phone);
            cout << "Date of birth (DD/MM/YYYY): ";
            getline(cin, birth);
            cout << "Address: ";
            getline(cin, address);
            flight = flights[decision]->getFlightNumber();
            flights[decision]->displaySeatingChart();
            cout << "Type in a number to select the seat: ";
            cin >> seat;
            seat--;
            //confirms once again
            cout << "Are you sure you want to proceed with checkout? (Type \"y\" or \"n\"): ";
            string confirmation = "";
            cin.ignore();
            getline(cin, confirmation);
            if(confirmation == "y") {
                cout << "The ticket confirmation number is: ";
                flights[decision]->setTicketReservation(name, birth, email, phone, address, seat);
                cout << "The flight number is: " << flight << endl;
                cout << "You need this information to view, edit, or delete your ticket. Without them, none of the actions are possible." << endl;
                cout << endl;
                cout << "Booking process complete. " << endl;
                cout << endl;
            } else {
                cout << endl;
                cout << "Process canceled." << endl;
                cout << endl;
            }
        } else {
            cout << endl;
            cout << "Process canceled." << endl;
            cout << endl;
        }
    }
}

void Airline::viewTicket() {
    bool search = this->findFlights();

    if(!search) {
        int decision = 0;
        cout << "Choose a flight to view (Type \"0\" to cancel): ";
        cin >> decision;
        if(decision > 0) { //if user does not cancel, then flight is edited
            decision--;
            int confirmationNum = 0;
            cout << "Enter ticket confirmation number: ";
            cin >> confirmationNum;
            flights[decision]->displayTicket(confirmationNum);
        } else {
            cout << endl;
            cout << "Process canceled." << endl;
            cout << endl;
        }
    }
}

string Airline::toString() {
    cout << endl;
    cout << "All scheduled flights:" << endl;
    for(int i = 0; i < flightNumber; i++) {
        flights[i]->toString();
        cout << endl;
    }
    cout << endl;
    return "";
}
