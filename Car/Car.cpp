#include "Car.h"
// Construtor
Car::Car() : Brand(""), Model(""), SubModel(""), Year(0), PricePerDay(0.0),
    NumberPlate(""), AvailabilityStatus(true), TotalKmDriven(0.0),
     KmDrivenThisRental(0.0), FuelLevel(0.0), NumSeats(0), Color("") {}

Car::Car(string Brand, string Model, string SubModel,int Year, double PricePerDay,
    string NumberPlate, bool AvailabilityStatus, double TotalKmDriven,
    double KmDrivenThisRental, double FuelLevel, int NumSeats, string Color) : Brand(Brand), Model(Model), SubModel(SubModel) ,Year(Year), PricePerDay(PricePerDay),
    NumberPlate(NumberPlate), AvailabilityStatus(AvailabilityStatus),
    KmDrivenThisRental(KmDrivenThisRental),TotalKmDriven(TotalKmDriven), FuelLevel(FuelLevel), NumSeats(NumSeats),
    Color(Color) {}

// Getters
string Car::getBrand(){
    return Brand;
}
string Car::getModel(){
    return Model;
}
string Car::getSubModel(){
    return SubModel;
}
int Car::getYear(){
    return Year;
}
double Car::getPricePerDay(){
    return PricePerDay;
}
string Car::getNumberPlate(){
    return NumberPlate;
}
bool Car::getAvailabilityStatus(){
    return AvailabilityStatus;
}
double Car::getTotalKmDriven(){
    return TotalKmDriven;
}
double Car::getKmDrivenThisRental(){
    return KmDrivenThisRental;
}
double Car::getFuelLevel(){
    return FuelLevel;
}
int Car::getNumSeats(){
    return NumSeats;
}
string Car::getColor(){
    return Color;
}

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
void Car::SetAvailabilityStatus(bool AvailabilityStatus){
    this->AvailabilityStatus = AvailabilityStatus;
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
    if (AvailabilityStatus){
        cout << "The Car is Currently Available" << endl;
    }
    else{
        cout << "The Car Currently isn't Available" << endl;
    }
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

