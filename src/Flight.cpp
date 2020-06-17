//
// Created by Dhruv Rawat on 2020-06-17.
//

#import "Classes.h"

Flight::Flight() {
    flightNumber = 0;
    departureDate = "Default Departure Date";
    arrivalDate = "Default Arrival Date";
    departureTime = "Default Departure Time";
    arrivalTime = "Default Arrival Time";
    departureLocation = "Default Departure Time";
    arrivalLocation = "Default Arrival Time";
    durationMinutes = 0;
    totalSeats = 10;
    seats = new Seat*[totalSeats];
    for(int i = 0; i < 10; i++) {
        seats[i] = new Seat();
    }
}
