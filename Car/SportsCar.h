#ifndef SportsCar_h
#define SportsCar_h
#include "Car.h"

class SportsCar : public Car { 
    private:
    int horsepower;
    int Torque;
    bool hasTurbo;
    int TopSpeed;
    double ZeroToHundred;
    
    public:
    SportsCar(); // Default Constructor
    SportsCar(string Brand, string Model, string SubModel,int Year, double PricePerDay,
        string NumberPlate, double TotalKmDriven,
        double KmDrivenThisRental, double FuelLevel, int NumSeats, string Color, int horsepower,
        int Torque, bool hasTurbo, int TopSpeed, double ZeroToHundred);
    ~SportsCar(); // Destrcutor

    // setters
    void setHorsepower(int Horsepower);
    void setTorque(int Torque);
    void sethasTurbo(bool hasTurbo);
    void setTopSpeed(int TopSpeed);
    void setZeroToHundred(double ZeroToHundred);

    //getters
    int getHorsepower() const;
    int getTorque() const;
    bool gethasTurbo() const;
    int getTopSpeed() const;
    double getZeroToHundred() const;

    //methods - overriden
    double getPrice() override;
    void displayInfo() override;
    
};


#endif