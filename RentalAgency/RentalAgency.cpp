#include "RentalAgency.h"
#include <iostream>
#include <stdexcept>
using namespace std;
//constructor
RentalAgency::RentalAgency(string name) {
    agencyName=name;
    bookingCounter=1;
}
//destructors
RentalAgency::~RentalAgency() {
    for (int i=0;i<bookings.size();i++)
        delete bookings[i];
    for (int i=0;i<cars.size();i++)
        delete cars[i];
    for (int i=0;i<customers.size();i++)
        delete customers[i];
    bookings.clear();
    cars.clear();
    customers.clear();
}
string RentalAgency::getAgencyName()const {
    return agencyName;
}
//car related methods
void RentalAgency::addCar(Car*car) {
    cars.push_back(car);
}
void RentalAgency::removeCar(string plate) {
    for (int i=0;i<cars.size();i++) {
        if (cars[i]->getNumberPlate()==plate) {
            cars.erase(cars.begin()+i);
            return;
        }
    }
    throw runtime_error("Car not found");
}
Car* RentalAgency::findCarByPlate(string plate) {
    for (int i=0;i<cars.size();i++) {
        if (cars[i]->getNumberPlate()==plate)
            return cars[i];
    }
    return nullptr;
}
vector<Car*>RentalAgency::searchAvailableCars(double minPrice,double maxPrice)const {
    vector<Car*> results;
    for (int i=0;i<cars.size();i++) {
        if (cars[i]->getPricePerDay()>=minPrice && cars[i]->getPricePerDay()<=maxPrice)
            results.push_back(cars[i]);
    }
    return results;
}
int RentalAgency::getTotalCars()const {
    return cars.size();
}
//customer related methods
void RentalAgency::registerCustomer(Customer* customer) {
    if (findCustomerByLicense(customer->getLicenseNumber())!=nullptr)
        throw runtime_error("Customer already registered");
    customers.push_back(customer);
}
Customer* RentalAgency::findCustomerByLicense(string license)const {
    for (int i=0;i<customers.size();i++) {
        if (customers[i]->getLicenseNumber()==license)
            return customers[i];
    }
    return nullptr;
}
int RentalAgency::getTotalCustomers()const {
    return customers.size();
}
//booking related methods
bool RentalAgency::isCarAvailable(Car* car,time_t start,time_t end)const {
    for (int i=0;i<bookings.size();i++) {
        if (bookings[i]->getCar()==car && bookings[i]->getStatus()=="Active") {
            if (start<bookings[i]->getEndDate() && end>bookings[i]->getStartDate())
                return false;
        }
    }
    return true;
}
Booking*RentalAgency::makeBooking(Customer* customer,Car* car,time_t start,time_t end,RentalPlan* plan) {
    if (!customer->checkEligibility())
        throw runtime_error("Customer is not eligible");
    if (customer->hasUnpaidBookings())
        throw runtime_error("Customer has unpaid bookings");
    if (!isCarAvailable(car,start,end))
        throw runtime_error("Car is not available during this period");
    if (end<=start)
        throw runtime_error("End date must be after Start date");
    string id="B"+to_string(bookingCounter);
    bookingCounter++;
    Booking* b=new Booking(id,customer,car,start,end,plan);
    customer->addBooking(b);
    bookings.push_back(b);
    return b;
}
//completes booking,calculates cost,processes payment,resets car km
void RentalAgency::completeBooking(string bookingID,string paymentMethod) {
    Booking* b=findBooking(bookingID);
    if (b==nullptr)
        throw runtime_error("Booking not found");
    if (b->getStatus()!="Active")
        throw runtime_error("Booking is not active");
    double cost=b->calculateTotalCost();
    string payID="PAY-"+bookingID;
    Payment* payment=new Payment(payID,cost,paymentMethod,"Pending");
    payment->processPayment();
    b->setPayment(payment);
    b->setStatus("Completed");
    b->getCar()->resetRentalKM();
    b->getCustomer()->removeBooking(b);
}
void RentalAgency::cancelBooking(string bookingID) {
    for(int i=0;i<bookings.size();i++) {
        if (bookings[i]->getBookingID()==bookingID) {
            bookings[i]->getCustomer()->removeBooking(bookings[i]);
            bookings[i]->setStatus("Cancelled");
            return;
        }
    }
    throw runtime_error("Booking not found");
}
Booking* RentalAgency::findBooking(string bookingID) {
    for (int i=0;i<bookings.size();i++) {
        if (bookings[i]->getBookingID()==bookingID)
            return bookings[i];
    }
    return nullptr;
}
int RentalAgency::getTotalBookings()const {
    return bookings.size();
}
//display methods
void RentalAgency::displayAllCars()const {
    cout<<"All cars:"<<endl;
    for (int i=0;i<cars.size();i++) {
        cars[i]->displayInfo();
        cout<<endl;
    }
}
void RentalAgency::displayAvailableCars()const {
    cout<<"Available cars:"<<endl;
    for (int i=0;i<cars.size();i++) {
        bool available=true;
        for (int j=0;j<bookings.size();j++) {
            if (bookings[j]->getCar()==cars[i] && bookings[j]->getStatus()=="Active") {
                available=false;
                break;
            }
        }
        if (available) {
            cars[i]->displayInfo();
            cout<<endl;
        }
    }
}
void RentalAgency::displayAllCustomers()const {
    cout<<"All customers:"<<endl;
    for (int i=0;i<customers.size();i++) {
        customers[i]->displayInfo();
        cout<<endl;
    }
}
void RentalAgency::displayAllBookings()const {
    cout<<"All bookings:"<<endl;
    for (int i=0;i<bookings.size();i++) {
        bookings[i]->displayInfo();
        cout<<endl;
    }
}
//to be completed
void RentalAgency::displayProfits()const {

}