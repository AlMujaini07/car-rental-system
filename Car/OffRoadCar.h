#ifndef OffRoadCar_h
#define OffRoadCar_h
#include "Car.h"

class OffRoadCar : public Car {
    private:
    bool hasDiffLock;
    bool hasFourWD;
    int groundClearance;
    string terrainType;
    int horsepower;
    bool hasLowRange;

    public:
    OffRoadCar();
    OffRoadCar(string Brand, string Model, string SubModel, int Year, double PricePerDay,
        string NumberPlate, double TotalKmDriven,
        double KmDrivenThisRental, double FuelLevel, int NumSeats, string Color,
        bool hasDiffLock, bool hasFourWD, int groundClearance, string terrainType,
        int horsepower, bool hasLowRange);
    ~OffRoadCar();

    // Setters
    void setHasDiffLock(bool hasDiffLock);
    void setHasFourWD(bool hasFourWD);
    void setGroundClearance(int groundClearance);
    void setTerrainType(string terrainType);
    void setHorsepower(int horsepower);
    void setHasLowRange(bool hasLowRange);

    // Getters
    bool getHasDiffLock() const;
    bool getHasFourWD() const;
    int getGroundClearance() const;
    string getTerrainType() const;
    int getHorsepower() const;
    bool getHasLowRange() const;

    // Overrides
    double getPrice() override;
    void displayInfo() override;
};

#endif
