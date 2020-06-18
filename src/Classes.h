//
// Created by Dhruv Rawat on 2020-06-17.
//

#include <iostream>
#include <string.h>
#include <array>

using namespace std;

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
private:
    // Customer information
    string name;
    string birthDate;
    string email;
    string phoneNumber;
    string address;
    // Ticket information
    int confirmationNumber;
    int seatNumber;
    int flightNumber;
public:
    // Constructors and Destructors
    Customer();

    /* Add methods here */

};

#endif


#ifndef SEAT_H
#define SEAT_H

class Seat {
private:
    int flightNumber;
    int seatNumber;
    Customer * person; //occupying customer is seated here
    bool reserved; //used to see if the seat is actually reserved
public:
    // Constructors and Destructors
    Seat();

    /* Add methods here */

};

#endif


#ifndef FLIGHT_H
#define FLIGHT_H

class Flight {
private:
    int flightNumber;
    string departureDate;
    string arrivalDate;
    string departureTime;
    string arrivalTime;
    string departureLocation;
    string arrivalLocation;
    int durationMinutes; //duration of the flight in minutes
    int totalSeats;
    Seat ** seats; //array contains all seats on the flight
public:
    // Constructors and Destructors
    Flight();

    /* Add methods here */

};

#endif


#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
private:
    string username;
    string encrypted_password;
    string name;
public:
    // Constructors and Destructors
    Employee();
    string passwordEncrypt(string, string);
    string passwordDecrypt(string, string);
    // Getters and Setters
    string getUsername();
    string getEncryptedPassword();

    /* Add methods here */

};

#endif

#ifndef AIRLINE_H
#define AIRLINE_H

class Airline {
private:
    Employee ** employees;
    Flight ** flights;
    int employeeNumber;
    int flightNumber;
    string airlineName;
public:
    // Constructors and Destructors
    Airline();
    // Login operations
    int employeeLogin(string, string);
    // Getters and Setters
    string getAirlineName();
    void setAirlineName(string);
};

#endif
