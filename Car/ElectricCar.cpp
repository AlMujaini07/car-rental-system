#include "ElectricCar.h"

ElectricCar::ElectricCar()
    : Car(), batteryRange(0), batteryLevel(0.0), chargingCostPerKwh(0.0),
      horsepower(0), torque(0), chargingTimeHours(0.0) {}

ElectricCar::ElectricCar(string Brand, string Model, string SubModel, int Year, double PricePerDay,
    string NumberPlate, double TotalKmDriven,
    double KmDrivenThisRental, double FuelLevel, int NumSeats, string Color,
    int batteryRange, double batteryLevel, double chargingCostPerKwh,
    int horsepower, int torque, double chargingTimeHours)
    : Car(Brand, Model, SubModel, Year, PricePerDay, NumberPlate,
          TotalKmDriven, KmDrivenThisRental, FuelLevel, NumSeats, Color),
      batteryRange(batteryRange), batteryLevel(batteryLevel), chargingCostPerKwh(chargingCostPerKwh),
      horsepower(horsepower), torque(torque), chargingTimeHours(chargingTimeHours) {}

ElectricCar::~ElectricCar() {}

// Getters
int ElectricCar::getBatteryRange() const { return batteryRange; }
double ElectricCar::getBatteryLevel() const { return batteryLevel; }
double ElectricCar::getChargingCostPerKwh() const { return chargingCostPerKwh; }
int ElectricCar::getHorsepower() const { return horsepower; }
int ElectricCar::getTorque() const { return torque; }
double ElectricCar::getChargingTimeHours() const { return chargingTimeHours; }

// Setters
void ElectricCar::setBatteryRange(int batteryRange) { this->batteryRange = batteryRange; }
void ElectricCar::setBatteryLevel(double batteryLevel) { this->batteryLevel = batteryLevel; }
void ElectricCar::setChargingCostPerKwh(double chargingCostPerKwh) { this->chargingCostPerKwh = chargingCostPerKwh; }
void ElectricCar::setHorsepower(int horsepower) { this->horsepower = horsepower; }
void ElectricCar::setTorque(int torque) { this->torque = torque; }
void ElectricCar::setChargingTimeHours(double chargingTimeHours) { this->chargingTimeHours = chargingTimeHours; }

// Overrides
double ElectricCar::getPrice() { return getPricePerDay(); }

void ElectricCar::displayInfo() {
    Car::displayInfo();
    cout << "Battery Range: " << batteryRange << " km" << endl;
    cout << "Battery Level: " << batteryLevel << "%" << endl;
    cout << "Charging Cost: " << chargingCostPerKwh << " OMR/kWh" << endl;
    cout << "Horsepower: " << horsepower << " HP" << endl;
    cout << "Torque: " << torque << " Nm" << endl;
    cout << "Charging Time: " << chargingTimeHours << " hours" << endl;
}
