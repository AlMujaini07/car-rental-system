#include "Payment.h"

// Constructors

Payment::Payment()
    : paymentID(""), amount(0.0), paymentMethod(""), status("Pending") {}

Payment::Payment(string paymentID, double amount, string paymentMethod, string status)
    : paymentID(paymentID), amount(amount),
      paymentMethod(paymentMethod), status(status) {}

// Destructor

Payment::~Payment() {}

// Getters

string Payment::getPaymentID()     const { return paymentID; }
double Payment::getAmount()        const { return amount; }
string Payment::getPaymentMethod() const { return paymentMethod; }
string Payment::getStatus()        const { return status; }

// Setters

void Payment::setPaymentID(string paymentID) {
    this->paymentID = paymentID;
}
void Payment::setAmount(double amount) {
    this->amount = amount;
}
void Payment::setPaymentMethod(string paymentMethod) {
    this->paymentMethod = paymentMethod;
}
void Payment::setStatus(string status) {
    this->status = status;
}

// Core Method

bool Payment::processPayment() {
    if (amount <= 0) {
        status = "Failed";
        cout << "Payment failed — amount must be greater than 0." << endl;
        return false;
    }
    status = "Completed";
    cout << "Payment of " << amount << " OMR processed successfully via " << paymentMethod << "." << endl;
    return true;
}

// Display

void Payment::displayInfo() const {
    cout << "Payment ID     : " << paymentID     << endl;
    cout << "Amount         : " << amount        << " OMR" << endl;
    cout << "Payment Method : " << paymentMethod << endl;
    cout << "Status         : " << status        << endl;
}

// Operator Overload

bool Payment::operator==(const Payment& other) const {
    return paymentID == other.paymentID;
}
