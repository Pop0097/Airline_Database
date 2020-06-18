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
