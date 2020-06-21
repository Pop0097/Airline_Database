//
// Created by Dhruv Rawat on 2020-06-17.
//

#include <iostream>
#include <string.h>
#include <array>
#include <math.h>

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
    int flightId;
    string departureLocation;
    string arrivalLocation;
    string departureDate;
    string arrivalDate;
    string departureTime;
    string arrivalTime;
    string airplaneType;
    int durationMinutes; //duration of the flight in minutes
    int totalSeats;
    Seat ** seats; //array contains all seats on the flight
    int seatsSold;
    int rows; //number of set rows in the plane
    int columns; //number of seats per row
public:
    // Constructors and Destructors
    Flight();
    Flight(int, int, int, string, string, string, string, string, string, string);
    ~Flight();
    // Getters and Setters
    int getFlightNumber();
    string getDepartureLocation();
    string getDepartureDate();
    string getDepartureTime();
    int getSeatsSold();
    void setFlightNumber(int);
    void setFlightDuration(int);
    void setTotalSeats(int);
    void adjustPassengerSeats();
    void setAirplaneType(string);
    void setDepartureLocation(string);
    void setDepartureDate(string);
    void setDepartureTime(string);
    void setArrivalLocation(string);
    void setArrivalDate(string);
    void setArrivalTime(string);
    // Display
    string displayPassengerList();
    string toString();
};

#endif


#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
private:
    string username;
    string encrypted_password;
    string name;
    string employeeID; //valid employee ID is an "E" followed by 9 digits
public:
    // Constructors and Destructors
    Employee();
    Employee(string, string);
    string passwordEncrypt(string, string);
    ~Employee();
    // Getters and Setters
    string getName();
    string getEmployeeId();
    string getUsername();
    string getEncryptedPassword();
    void setName(string);
    void setEmployeeId(string);
    void setUsername(string);
    void setPassword(string);
    bool idValid(string);
    // Display
    string toString();
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
    // Methods for Employee account
    void viewEmployeeAccount(int);
    void editEmployeeAccount(int);
    void createEmployeeAccount();
    bool findEmployees(int);
    int deleteEmployeeAccount(int);
    // Methods for Flight
    void createFlight();
    bool findFlights();
    void viewFlight();
    void editFlight();
    void deleteFlight();
    // Display
    string toString();
};

#endif
