#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
#include <ctime>
#include <stdexcept>
#include "RentalPlan.h"
#include "../Car/Car.h"
#include "../Customer/Customer.h"
using namespace std;

class DeliveryService; //This is just a forward declaration member 4 will implement it according to the devided classes.

class Booking {
    private:
        string bookingID; //string bc B001 or BID123
        Customer* customer;
        Car* car;
        time_t startDate;
        time_t endDate;
        string Status; //Status of the booking Active,Cancelled,Completed
        RentalPlan* rentalPlan;
        DeliveryService* deliveryService;
    public:
        Booking(string bookingID, Customer* customer, Car* car, time_t startDate, time_t endDate, RentalPlan rentalPlan, DeliveryService* deliveryService= nullptr);
        //nullptr because deliveryService is still not decided (because we dont know if we will have selfpickup or keep that option as null or nothing).
        ~Booking();
        //Getters:
        string getBookingID() const;
        Customer* getCustomer() const;
        Car* getCar() const;
        time_t getStartDate() const;
        time_t getEndDate() const;
        string getStatus() const;
        RentalPlan* getRentalPlan() const;
        DeliveryService* getDeliveryService() const;
        //Setters:
        void setStatus(string status);
        void setDeliveryService(DeliveryService* ds);
        //Class methods:
        int getNumDays() const;
        double calculateTotalCost() const;
        void displayInfo() const;
        //== Operator overload to compare bookings by dates:
        bool operator==(const Booking& other) const;
        //Helper to build a time_t from day, month, year:
        static time_t makeDate(int day, int month, int year);
};

#endif


