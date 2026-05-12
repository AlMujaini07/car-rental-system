#ifndef PAYMENT_H
#define PAYMENT_H
#include <iostream>
#include <string>
using namespace std;

class Payment {
private:
    string  paymentID;
    double  amount;
    string  paymentMethod;  // "Cash", "Card", "Online"
    string  status;         // "Pending", "Completed", "Failed"

public:
    // Constructor
    Payment();
    Payment(string paymentID, double amount, string paymentMethod, string status);

    // Destructor
    ~Payment();

    // Getters
    string getPaymentID()     const;
    double getAmount()        const;
    string getPaymentMethod() const;
    string getStatus()        const;

    // Setters
    void setPaymentID(string paymentID);
    void setAmount(double amount);
    void setPaymentMethod(string paymentMethod);
    void setStatus(string status);

    // Core method
    // Simulates processing — sets status to "Completed" if amount > 0
    bool processPayment();

    // Display payment info
    void displayInfo() const;

    // Operator overload: compare payments by paymentID
    bool operator==(const Payment& other) const;
};

#endif
