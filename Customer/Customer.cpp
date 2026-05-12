#include "Customer.h"
#include <iostream>
#include <algorithm>
//I need to include "Booking.h" here

//Constructor
Customer::Customer(string name, int age,string licenseNumber, bool hasValidLicense): name(name), age(age),licenseNumber(licenseNumber), hasValidLicense(hasValidLicense) {}

//Destructor
Customer::~Customer() {
    cout<<"Deleting Customer";
    activeBookings.clear();
}

//Getters
string Customer::getName() const { return name; }
int Customer::getAge() const { return age; }
string Customer::getLicenseNumber() const { return licenseNumber; }
bool Customer::getHasValidLicense() const { return hasValidLicense; }
vector<string> Customer::getActiveBookings() const { return activeBookings; } // vector<Booking>

//Setters
void Customer::setName(string newName) { name = newName; }
void Customer::setAge(int newAge) { age = newAge; }
void Customer::setLicenseNumber(string newLicense) { licenseNumber = newLicense; }
void Customer::setHasValidLicense(bool status) { hasValidLicense = status; }

//Booking management
void Customer::addBooking(string bookingId) { //Booking instead of string
    activeBookings.push_back(bookingId);
    cout<<"Booking ["+ bookingId+"] added\n";
}

void Customer::removeBooking(string bookingId) { // Here I used an iterator to find a pointer to Booking
    auto it = find(activeBookings.begin(), activeBookings.end(), bookingId);
    if (it != activeBookings.end()) {
        activeBookings.erase(it);
    }
}

bool Customer::checkEligibility() const {
    if (age < 18) {
        cout << "   Not eligible: customer is underage (age " << age << ").\n";
        return false;
    }
    if (!hasValidLicense) {
        cout << "   Not eligible: no valid driver's license.\n";
        return false;
    }
    return true;
}

bool Customer::hasUnpaidBookings() const {
    // check if Booking is paid
}

void Customer::displayInfo() const {
    cout << "=== Customer Info ===\n";
    cout << "Name:    " << name << "\n";
    cout << "Age:     " << age << "\n";
    cout << "License: " << licenseNumber << "\n";
    cout << "Valid License: " << (hasValidLicense ? "Yes" : "No") << "\n";
    cout << "Active Bookings: " << activeBookings.size() << "\n";
}

//Compare License Numbers
bool Customer::operator==(const Customer& other) const {
    return licenseNumber == other.licenseNumber;
}
