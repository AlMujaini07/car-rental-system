#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
using namespace std;

class Booking;

class Customer {
private:
    string name;
    int age;
    string licenseNumber;
    bool hasValidLicense;
    vector<Booking*> activeBookings; // Changed from vector<string>

public:
    // Constructor
    Customer(string name, int age, string licenseNumber, bool hasValidLicense);
    Customer() {}

    // Destructor
    ~Customer();

    // Getters
    string getName() const;
    int getAge() const;
    string getLicenseNumber() const;
    bool getHasValidLicense() const;
    vector<Booking*> getActiveBookings() const; // Changed from vector<string>

    // Setters
    void setName(string name);
    void setAge(int age);
    void setLicenseNumber(string licenseNumber);
    void setHasValidLicense(bool status);

    // Booking management
    void addBooking(Booking* booking);    // Changed from string
    void removeBooking(Booking* booking); // Changed from string

    // Returns true if age >= 18 and has a valid license
    bool checkEligibility() const;

    // Returns true if customer has any active bookings that are unpaid
    bool hasUnpaidBookings() const;

    // Display customer info
    void displayInfo() const;

    // Operator overload: compare customers by license number
    bool operator==(const Customer& other) const;
};

#endif
