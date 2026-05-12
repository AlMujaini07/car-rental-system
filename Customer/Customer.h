#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
//I need to include "Booking.h" here
using namespace std;


class Customer {
private:
    string name;
    int age;
    string licenseNumber;
    bool hasValidLicense;
    vector<string> activeBookings; // This has to be vector<Booking>

public:
    // Constructor
    Customer(string name, int age,string licenseNumber, bool hasValidLicense);
    Customer() {}

    // Destructor
    ~Customer();

    // Getters
    string getName() const;
    int getAge() const;
    string getLicenseNumber() const;
    bool getHasValidLicense() const;
    vector<string> getActiveBookings() const; //vector<Booking>

    // Setters
    void setName(string name);
    void setAge(int age);
    void setLicenseNumber(string licenseNumber);
    void setHasValidLicense(bool status);

    // Booking management
    void addBooking(string bookingId); //Booking instead of string
    void removeBooking(string bookingId); // Booking instead of string

    // Returns true if age >= 18 and has a valid license
    bool checkEligibility() const;

    // Returns true if customer has any active bookings
    bool hasUnpaidBookings() const;

    // Display customer info
    void displayInfo() const;

    // Operator overload: compare customers by license number
    bool operator==(const Customer& other) const;
};

#endif
