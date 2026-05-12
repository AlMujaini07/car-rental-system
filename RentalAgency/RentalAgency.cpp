#include "RentalAgency.h"
#include <iostream>
#include <stdexcept>

using namespace std;

//constructor
RentalAgency::RentalAgency(string name) {
    agnecyName=name;        //eg: Muscat Car rentals
    bookingCounter=1;       //sets the booking counter eg: B1 ... B2
}
//destructor
RentalAgency::~RentalAgency() {
    for (int=0;i<bookings.size();i++) {
        delete bookings[i];
    }
    bookings.clear();
}
string RentalAgency::getAgencyName()const {
    return agencyName;
}
//car related methods;
void RentalAgency::addCar(Car*car) {
    cars.push_back(car);
}
void RentalAgency::removeCar(string plate) {
    for (int i=0;i<cars.size();i++) {
        if (cars[i]->getNumberPlate()==plate) {
            cars.erase(cars.begin()+i);
            return;
        }
        throw runtime_error("Car not found");
    }
}
Car* RentalAgency::findCarByPlate(string plate) {
    for (int i=0;i<cars.size();i++) {
        if (cars[i]->getNumberPlate()==plate){
            return cars[i];
        }
    }
    return nullptr;     //if cars wasn't found
}
//filter price range
vector<Car*>RentalAgency::searchAvailableCars(double minPrice,double maxPrice)const {
    vector<Car*> results;
    for (int i=0;i<cars.size();i++) {
        if (cars[i]->getAvailabilityStatus() and cars[i]->getPricePerDay()>=minPrice and cars[i]->getPricePerDay()<=maxPrice) {
            results.push_back(cars[i]);
        }
    }
    return results;
}
int RentalAgency::getTotalCars()const {
    return cars.size();
}
//customer related methods;
void RentalAgency::registerCustomer(Customer* customer) {
    customers.push_back(customer);
}
Customer* RentalAgency::findCustomerByLicense(string license)const {
    for (int i=0;i<customers.size();i++) {
        if (customers[i]->getLicenseNumber()==license) {
            return customers[i]
        }
    }
    return nullptr;
}
int RentalAgency::getTotalCustomers()const {
    return customers.size();
}
//booking related methods;
//most imp class
Booking*RentalAgency::makeBooking(Customer* customer,Cars* car,time_t start,time_t end,RentalPlan* plan) {
    if (!customer->checkEligibility()) {
        throw runtime_error("Customer is not eligable");
    }
    if (!car->getAvailabilityStatus()) {
        throw runtime_error("Car is not available");
    }
    if (end<=start) {
        throw runtime_error("End date must be after Start date");
    }
    string id="B"+to_string(bookingCounter);
    bookingCounter++;
    booking* b=new Booking(id,customer,car,start,end,plan);
    car->SetAvailabilityStatus(false);
    customer->addBooking(id);
    bookings.push_back(b);
    return b;
}
void RentalAgency::cancelBooking(string bookingID) {
    for(int i=0;i<booking.size();i++) {
        if (bookings[i]->getBookingID()==bookingID) {
            bookings[i]->getCar()->SetAvailabilityStatus(true);
            bookings[i]->getCustomer()->removeBooking(bookingId);
            bookings[i]->setStatus("Cancelled");
            return;
        }
    }
    throw runtime_error("Booking not found");
}
Booking* RentalAgency::findBooking(string bookingID) {
    for (int i=0;i<booking.size();i++) {
        if (bookings[i]->getBookingID()==bookingID) {
            return bookings[i];
        }
    }
    return nullptr;
}
int RentalAgency::getTotalBookings()const {
    return bookings.size();
}
//display
//to be completed
void RentalAgency::displayAllCars()const{}
void RentalAgency::displayAvailableCars()const{}
void RentalAgency::displayAllCustomers()const{}
void RentalAgency::displayAllBookings()const{}
