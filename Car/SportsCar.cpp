#include "SportsCar.h"

// Default Constructor
SportsCar::SportsCar() : Car(), horsepower(0), Torque(0), hasTurbo(false), TopSpeed(0), ZeroToHundred(0.0) {}

// Parameterized Constructor
SportsCar::SportsCar(string Brand, string Model, string SubModel, int Year, double PricePerDay,
    string NumberPlate, double TotalKmDriven,
    double KmDrivenThisRental, double FuelLevel, int NumSeats, string Color,
    int horsepower, int Torque, bool hasTurbo, int TopSpeed, double ZeroToHundred)
    : Car(Brand, Model, SubModel, Year, PricePerDay, NumberPlate,
        TotalKmDriven, KmDrivenThisRental, FuelLevel, NumSeats, Color),
      horsepower(horsepower), Torque(Torque), hasTurbo(hasTurbo), TopSpeed(TopSpeed), ZeroToHundred(ZeroToHundred) {}


// Getters
int SportsCar::getHorsepower() { return horsepower; }
int SportsCar::getTorque() { return Torque; }
bool SportsCar::gethasTurbo() { return hasTurbo; }
int SportsCar::getTopSpeed() { return TopSpeed; }
double SportsCar::getZeroToHundred() { return ZeroToHundred; }

// Setters
void SportsCar::setHorsepower(int Horsepower) { this->horsepower = Horsepower; }
void SportsCar::setTorque(int Torque) { this->Torque = Torque; }
void SportsCar::sethasTurbo(bool hasTurbo) { this->hasTurbo = hasTurbo; }
void SportsCar::setTopSpeed(int TopSpeed) { this->TopSpeed = TopSpeed; }
void SportsCar::setZeroToHundred(double ZeroToHundred) { this->ZeroToHundred = ZeroToHundred; }

// getPrice - overridden
double SportsCar::getPrice() {
    return getPricePerDay();
}

// displayInfo - overridden
void SportsCar::displayInfo() {
    Car::displayInfo();
    cout << "Horsepower: " << horsepower << " HP" << endl;
    cout << "Torque: " << Torque << " Nm" << endl;
    cout << "Has Turbo: ";
    if (hasTurbo)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << "Top Speed: " << TopSpeed << " km/h" << endl;
    cout << "0-100 km/h: " << ZeroToHundred << " seconds" << endl;
}