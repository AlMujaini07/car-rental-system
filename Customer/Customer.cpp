#include "Customer.h"
#include "../Booking/Booking.h"
#include <iostream>
#include <algorithm>

//Constructor
Customer::Customer(string name, int age, string licenseNumber, bool hasValidLicense)
    : name(name), age(age), licenseNumber(licenseNumber), hasValidLicense(hasValidLicense) {}

//Destructor
Customer::~Customer() {
    cout << "Deleting Customer";
    activeBookings.clear(); // Clears pointers; does NOT delete the Booking objects (owned by the system)
}

//Getters
string Customer::getName() const { return name; }
int Customer::getAge() const { return age; }
string Customer::getLicenseNumber() const { return licenseNumber; }
bool Customer::getHasValidLicense() const { return hasValidLicense; }
vector<Booking*> Customer::getActiveBookings() const { return activeBookings; } // Changed return type

//Setters
void Customer::setName(string newName) { name = newName; }
void Customer::setAge(int newAge) { age = newAge; }
void Customer::setLicenseNumber(string newLicense) { licenseNumber = newLicense; }
void Customer::setHasValidLicense(bool status) { hasValidLicense = status; }

//Booking management
void Customer::addBooking(Booking* booking) { // Changed parameter from string to Booking*
    activeBookings.push_back(booking);
    cout << "Booking [" + booking->getBookingID() + "] added\n";
}

void Customer::removeBooking(Booking* booking) { // Changed parameter from string to Booking*
    auto it = find(activeBookings.begin(), activeBookings.end(), booking);
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
    for (Booking* booking : activeBookings) {
        // A booking is unpaid if it has no Payment object attached,
        // or if the booking is still Active (not yet completed/cancelled)
        if (booking->getPayment() == nullptr && booking->getStatus() == "Active") {
            return true;
        }
    }
    return false;
}

void Customer::displayInfo() const {
    cout << "=== Customer Info ===\n";
    cout << "Name: " << name << "\n";
    cout << "Age: " << age << "\n";
    cout << "License: " << licenseNumber << "\n";
    cout << "Valid License: " << (hasValidLicense ? "Yes" : "No") << "\n";
    cout << "Active Bookings: " << activeBookings.size() << "\n";
}

//Compare License Numbers
bool Customer::operator==(const Customer& other) const {
    return licenseNumber == other.licenseNumber;
}
