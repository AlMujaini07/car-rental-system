#include "LuxuryCar.h"

LuxuryCar::LuxuryCar()
    : Car(), seatMaterial(""), soundSystem(""), hasHeatedSeats(false), hasMassageSeats(false), horsepower(0) {}

LuxuryCar::LuxuryCar(string Brand, string Model, string SubModel, int Year, double PricePerDay,
    string NumberPlate, double TotalKmDriven,
    double KmDrivenThisRental, double FuelLevel, int NumSeats, string Color,
    string seatMaterial, string soundSystem, bool hasHeatedSeats, bool hasMassageSeats, int horsepower)
    : Car(Brand, Model, SubModel, Year, PricePerDay, NumberPlate,
          TotalKmDriven, KmDrivenThisRental, FuelLevel, NumSeats, Color),
      seatMaterial(seatMaterial), soundSystem(soundSystem), hasHeatedSeats(hasHeatedSeats),
      hasMassageSeats(hasMassageSeats), horsepower(horsepower) {}

LuxuryCar::~LuxuryCar() {}

// Getters
string LuxuryCar::getSeatMaterial() const { return seatMaterial; }
string LuxuryCar::getSoundSystem() const { return soundSystem; }
bool LuxuryCar::getHasHeatedSeats() const { return hasHeatedSeats; }
bool LuxuryCar::getHasMassageSeats() const { return hasMassageSeats; }
int LuxuryCar::getHorsepower() const { return horsepower; }

// Setters
void LuxuryCar::setSeatMaterial(string seatMaterial) { this->seatMaterial = seatMaterial; }
void LuxuryCar::setSoundSystem(string soundSystem) { this->soundSystem = soundSystem; }
void LuxuryCar::setHasHeatedSeats(bool hasHeatedSeats) { this->hasHeatedSeats = hasHeatedSeats; }
void LuxuryCar::setHasMassageSeats(bool hasMassageSeats) { this->hasMassageSeats = hasMassageSeats; }
void LuxuryCar::setHorsepower(int horsepower) { this->horsepower = horsepower; }

// Overrides
double LuxuryCar::getPrice() { return getPricePerDay(); }

void LuxuryCar::displayInfo() {
    Car::displayInfo();
    cout << "Seat Material: " << seatMaterial << endl;
    cout << "Sound System: " << soundSystem << endl;
    cout << "Heated Seats: " << (hasHeatedSeats ? "Yes" : "No") << endl;
    cout << "Massage Seats: " << (hasMassageSeats ? "Yes" : "No") << endl;
    cout << "Horsepower: " << horsepower << " HP" << endl;
}
