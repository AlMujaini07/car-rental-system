#ifndef Car_h
#define Car_h

#include <iostream>

using namespace std;


class Car{
    private:
    string Brand;   // Toyota
    string Model;   // Camry
    string SubModel;    // XSE
    int Year;   // 2018
    double PricePerDay; // 40 OMR per Day
    string NumberPlate; // "5542 AD"
    bool AvailabilityStatus; // True = Available
    double TotalKmDriven; // 70,532 KM on ODO
    double KmDrivenThisRental;
    double FuelLevel;   // 54.3% Fuel left
    int NumSeats; // 5 seats
    string Color; //blue

    public:
    // Construtor
    Car();
    Car(string Brand, string Model, string SubModel,int Year, double PricePerDay,
        string NumberPlate, bool AvailabilityStatus, double TotalKmDriven,
        double KmDrivenThisRental, double FuelLevel, int NumSeats, string Color);
    // Destructor
    virtual ~Car();

    // Getters
    string getBrand();
    string getModel();
    string getSubModel();
    int getYear();
    double getPricePerDay();
    string getNumberPlate();
    bool getAvailabilityStatus();
    double getTotalKmDriven();
    double getKmDrivenThisRental();
    double getFuelLevel();
    int getNumSeats();
    string getColor();

    //setters
    void SetBrand(string Brand);
    void SetModel(string Model);
    void SetSubModel(string SubModel);
    void SetYear(int Year);
    void SetPricePerDay(double PricePerDay);
    void SetNumberPlate(string NumberPlate);
    void SetAvailabilityStatus(bool AvailabilityStatus);
    void SetTotalKmDriven(double TotalKmDriven);
    void SetKmDrivenThisRental(double KmDrivenThisRental);
    void SetFuelLevel(double FuelLevel);
    void SetNumSeats(int NumSeats);
    void SetColor(string Color);


    //virtual getters
    virtual double getPrice();
    virtual void displayInfo();

    //Methods
    void addKMDriven(double km);
    void resetRentalKM();
};



#endif