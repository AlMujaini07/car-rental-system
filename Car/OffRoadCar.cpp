#include "OffRoadCar.h"

OffRoadCar::OffRoadCar()
    : Car(), hasDiffLock(false), hasFourWD(false), groundClearance(0),
      terrainType(""), horsepower(0), hasLowRange(false) {}

OffRoadCar::OffRoadCar(string Brand, string Model, string SubModel, int Year, double PricePerDay,
    string NumberPlate, double TotalKmDriven,
    double KmDrivenThisRental, double FuelLevel, int NumSeats, string Color,
    bool hasDiffLock, bool hasFourWD, int groundClearance, string terrainType,
    int horsepower, bool hasLowRange)
    : Car(Brand, Model, SubModel, Year, PricePerDay, NumberPlate,
          TotalKmDriven, KmDrivenThisRental, FuelLevel, NumSeats, Color),
      hasDiffLock(hasDiffLock), hasFourWD(hasFourWD), groundClearance(groundClearance),
      terrainType(terrainType), horsepower(horsepower), hasLowRange(hasLowRange) {}

OffRoadCar::~OffRoadCar() {}

// Getters
bool OffRoadCar::getHasDiffLock() const { return hasDiffLock; }
bool OffRoadCar::getHasFourWD() const { return hasFourWD; }
int OffRoadCar::getGroundClearance() const { return groundClearance; }
string OffRoadCar::getTerrainType() const { return terrainType; }
int OffRoadCar::getHorsepower() const { return horsepower; }
bool OffRoadCar::getHasLowRange() const { return hasLowRange; }

// Setters
void OffRoadCar::setHasDiffLock(bool hasDiffLock) { this->hasDiffLock = hasDiffLock; }
void OffRoadCar::setHasFourWD(bool hasFourWD) { this->hasFourWD = hasFourWD; }
void OffRoadCar::setGroundClearance(int groundClearance) { this->groundClearance = groundClearance; }
void OffRoadCar::setTerrainType(string terrainType) { this->terrainType = terrainType; }
void OffRoadCar::setHorsepower(int horsepower) { this->horsepower = horsepower; }
void OffRoadCar::setHasLowRange(bool hasLowRange) { this->hasLowRange = hasLowRange; }

// Overrides
double OffRoadCar::getPrice() { return getPricePerDay(); }

void OffRoadCar::displayInfo() {
    Car::displayInfo();
    cout << "Diff Lock: " << (hasDiffLock ? "Yes" : "No") << endl;
    cout << "4WD: " << (hasFourWD ? "Yes" : "No") << endl;
    cout << "Ground Clearance: " << groundClearance << " mm" << endl;
    cout << "Terrain Type: " << terrainType << endl;
    cout << "Horsepower: " << horsepower << " HP" << endl;
    cout << "Low Range: " << (hasLowRange ? "Yes" : "No") << endl;
}
