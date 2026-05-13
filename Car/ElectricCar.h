#ifndef ElectricCar_h
#define ElectricCar_h
#include "Car.h"

class ElectricCar : public Car {
    private:
    int batteryRange;
    double batteryLevel;
    double chargingCostPerKwh;
    int horsepower;
    int torque;
    double chargingTimeHours;

    public:
    ElectricCar();
    ElectricCar(string Brand, string Model, string SubModel, int Year, double PricePerDay,
        string NumberPlate, double TotalKmDriven,
        double KmDrivenThisRental, double FuelLevel, int NumSeats, string Color,
        int batteryRange, double batteryLevel, double chargingCostPerKwh,
        int horsepower, int torque, double chargingTimeHours);
    ~ElectricCar();

    // Setters
    void setBatteryRange(int batteryRange);
    void setBatteryLevel(double batteryLevel);
    void setChargingCostPerKwh(double chargingCostPerKwh);
    void setHorsepower(int horsepower);
    void setTorque(int torque);
    void setChargingTimeHours(double chargingTimeHours);

    // Getters
    int getBatteryRange() const;
    double getBatteryLevel() const;
    double getChargingCostPerKwh() const;
    int getHorsepower() const;
    int getTorque() const;
    double getChargingTimeHours() const;

    // Overrides
    double getPrice() override;
    void displayInfo() override;
};

#endif
