#ifndef LuxuryCar_h
#define LuxuryCar_h
#include "Car.h"

class LuxuryCar : public Car {
    private:
    string seatMaterial;
    string soundSystem;
    bool hasHeatedSeats;
    bool hasMassageSeats;
    int horsepower;

    public:
    LuxuryCar();
    LuxuryCar(string Brand, string Model, string SubModel, int Year, double PricePerDay,
        string NumberPlate, double TotalKmDriven,
        double KmDrivenThisRental, double FuelLevel, int NumSeats, string Color,
        string seatMaterial, string soundSystem, bool hasHeatedSeats, bool hasMassageSeats, int horsepower);
    ~LuxuryCar();

    // Setters
    void setSeatMaterial(string seatMaterial);
    void setSoundSystem(string soundSystem);
    void setHasHeatedSeats(bool hasHeatedSeats);
    void setHasMassageSeats(bool hasMassageSeats);
    void setHorsepower(int horsepower);

    // Getters
    string getSeatMaterial() const;
    string getSoundSystem() const;
    bool getHasHeatedSeats() const;
    bool getHasMassageSeats() const;
    int getHorsepower() const;

    // Overrides
    double getPrice() override;
    void displayInfo() override;
};

#endif
