//
// Created by Dhruv Rawat on 2020-06-17.
//

#import "Classes.h"

Seat::Seat() { //sets default values
    flightNumber = 0;
    seatNumber = 0;
    person = new Customer();
    reserved = false;
}
