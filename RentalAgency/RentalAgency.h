#ifndef RENTALAGENCY_H
#define RENTALAGENCY_H

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "../Car/Car.h"
#include "../Customer/Customer.h"
#include "../Booking/Booking.h"
#include "../Booking/RentalPlan.h"

using namespace std;

class RentalAgency {
private:
    string agencyName;
    vector<Car*> cars;
    vector<Customer*> customers;
    vector<Booking*> bookings;
    int bookingCounter;
public:
    RentalAgency(string name);
    ~RentalAgency();
    string getAgencyName()const;

    //car related methods
    void addCar(Car* car);
    void removeCar(string plate);
    Car* findCarByPlate(string plate);
    vector<Car*> searchAvailableCars(double minPrice,double maxPrice)const;
    int getTotalCars()const;

    //customer related methods
    void registerCustomer(Customer* customer);
    Customer* findCustomerByLicense(string license)const;
    int getTotalCustomers()const;

    //booking related methods
    Booking* makeBooking(Customer* customer,Car* car,time_t start,time_t end,RentalPlan* plan);
    void cancelBooking(string bookingID);
    Booking* findBooking(string bookingID);
    int getTotalBookings()const;

    void displayAllCars()const;
    void displayAvailableCars()const;
    void displayAllCustomers()const;
    void displayAllBookings()const;
};
#endif
