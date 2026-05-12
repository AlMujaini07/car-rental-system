#include "Booking.h"
#include <iomanip>

//Static helper, this is how we will manage time using <ctime>

time_t Booking::makeDate(int day, int month, int year) {
    tm date = {};
    date.tm_mday= day;
    date.tm_mon = month-1;
    date.tm_year= year-1900;
    return mktime(&date);
}

//Constructor: 
Booking::Booking(string bookingID, Customer* customer, Car* car, time_t startDate, time_t endDate, RentalPlan* rentalPlan,DeliveryService* deliveryService)
: bookingID(bookingID), customer(customer), car(car), startDate(startDate), endDate(endDate), status("Active"), rentalPlan(rentalPlan), deliveryService(deliveryService)
{
    if (endDate< startDate)
        throw invalid_argument("End date cannot be before the start date.");//this is why we used <stdexcept>
}

//Destructor: 
Booking::~Booking(){}

//Getters:
string Booking::getBookingID() const {return bookingID;}
Customer* Booking::getCustomer() const {return customer;}
Car* Booking::getCar() const {return car;}
time_t Booking::getStartDate() const {return startDate;}
time_t Booking::getEndDate() const {return endDate;}
string Booking::getStatus() const {return status;}
RentalPlan* Booking::getRentalPlan() const {return rentalPlan;}
DeliveryService* Booking::getDeliveryService() const {return deliveryService;}

//Setters:
void Booking::setStatus(string newStatus){status= newStatus;}
void Booking::setDeliveryService(DeliveryService* ds) {deliveryService= ds;}

//Class methods:
int Booking::getNumDays() const{
    return (int)(difftime(endDate, startDate)/86400);
}

double Booking::calculateTotalCost() const{
    int days=getNumDays();
    double kmDriven= car->getKmDrivenThisRental();
    double pricePerDay= car->getPricePerDay();
    return rentalPlan->calculateCost(pricePerDay, days, kmDriven);
}
void Booking::displayInfo() const{
    tm* s=localtime(&startDate);
    tm* e=localtime(&endDate);

    cout<<"=== Booking Info ==="<<endl;
    cout<<"Booking ID: "<<bookingID<<endl;
    cout<<"Customer:   "<<customer->getName()<<endl;
    cout<<"Car:        "<<car->getBrand()<<" "<< car->getModel()<<endl;
    cout<<"Start Date: "<<s->tm_mday<<"-"<<setfill('0')<<setw(2)<<(s->tm_mon+1)<<"-"<<(s->tm_year+1900)<<endl;
    cout<<"End Date:   "<<e->tm_mday<<"-"<<setfill('0')<<setw(2)<<(e->tm_mon+1)<<"-"<<(e->tm_year+1900)<<endl;
    cout<<"Days:       "<<getNumDays()<<endl;
    cout<<"Status:     "<<status<<endl;
    rentalPlan->displayInfo();
    cout<<"Total Cost: "<<calculateTotalCost()<<" OMR"<<endl;
}
//== Operator
bool Booking::operator==(const Booking& other) const{
    return (startDate==other.startDate && endDate == other.endDate);
}