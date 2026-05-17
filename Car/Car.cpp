#include "Car.h"
// Construtor
Car::Car() : Brand(""), Model(""), SubModel(""), Year(0), PricePerDay(0.0),
    NumberPlate(""), TotalKmDriven(0.0),
     KmDrivenThisRental(0.0), FuelLevel(0.0), NumSeats(0), Color("") {}

Car::Car(string Brand, string Model, string SubModel,int Year, double PricePerDay,
    string NumberPlate, double TotalKmDriven,
    double KmDrivenThisRental, double FuelLevel, int NumSeats, string Color) : Brand(Brand), Model(Model), SubModel(SubModel) ,Year(Year), PricePerDay(PricePerDay),
    NumberPlate(NumberPlate),
    KmDrivenThisRental(KmDrivenThisRental),TotalKmDriven(TotalKmDriven), FuelLevel(FuelLevel), NumSeats(NumSeats),
    Color(Color) {}

// Getters
string Car::getBrand() const { return Brand; }
string Car::getModel() const { return Model; }
string Car::getSubModel() const { return SubModel; }
int Car::getYear() const { return Year; }
double Car::getPricePerDay() const { return PricePerDay; }
string Car::getNumberPlate() const { return NumberPlate; }
double Car::getTotalKmDriven() const { return TotalKmDriven; }
double Car::getKmDrivenThisRental() const { return KmDrivenThisRental; }
double Car::getFuelLevel() const { return FuelLevel; }
int Car::getNumSeats() const { return NumSeats; }
string Car::getColor() const { return Color; }

//setters
void Car::SetBrand(string Brand){
    this->Brand = Brand;
}
void Car::SetModel(string Model){
    this->Model = Model;
}
void Car::SetSubModel(string SubModel){
    this->SubModel = SubModel;
}
void Car::SetYear(int Year){
    this->Year = Year;
}
void Car::SetPricePerDay(double PricePerDay){
    this->PricePerDay = PricePerDay;
}
void Car::SetNumberPlate(string NumberPlate){
    this->NumberPlate = NumberPlate;
}
void Car::SetTotalKmDriven(double TotalKmDriven){
    this->TotalKmDriven = TotalKmDriven;
}
void Car::SetKmDrivenThisRental(double KmDrivenThisRental){
    this->KmDrivenThisRental = KmDrivenThisRental;
}
void Car::SetFuelLevel(double FuelLevel){
    this->FuelLevel = FuelLevel;
}
void Car::SetNumSeats(int NumSeats){
    this->NumSeats = NumSeats;
}
void Car::SetColor(string Color){
    this->Color = Color;
}


//virtual getters
double Car::getPrice(){
    return PricePerDay;
}
void Car::displayInfo(){
    cout << "Car Name and Model: " << Brand << " " << Model << " " << SubModel << " " << Year << endl;
    cout << "The price per day is " << PricePerDay << " OMR" << endl;
    cout << "The number plate is " << NumberPlate << endl;
    cout << "The number of seats is " << NumSeats << endl;
    cout << "The color of car is " << Color << endl;
}

//Methods
void Car::addKMDriven(double km){
    this->TotalKmDriven += km;
    this->KmDrivenThisRental += km;
}
void Car::resetRentalKM(){
    this->KmDrivenThisRental = 0;
}

//Destructor

Car::~Car(){}

