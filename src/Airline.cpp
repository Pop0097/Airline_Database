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
            for(int i = 0; i < employeeNumber; i++) { //searches all employees to find those that match the search
                empName = employees[i]->getName();
                found = empName.find(name);
                if(i != userNumber && found != -1) { //if employees match the search (and are not the current user)
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

        if(decision != 0) { //user does not cancel process
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
