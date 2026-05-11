#include "RentalPlan.h"

//Limited KM:

LimitedKM::LimitedKM(double kmCap, double extraChargePerKm): kmCap(kmCap), extraChargePerKm(extraChargePerKm) {}

double LimitedKM::calculateCost(double pricePerDay, int days, double kmDriven){
    double baseCost= pricePerDay*days;
    double extraKm= kmDriven-kmCap;
    if (extraKm>0){
        baseCost += extraKm*extraChargePerKm;
    }
    return baseCost;
}

void LimitedKM::displayInfo(){
    cout<<"Plan: Limited KM"<<endl;
    cout<<"KM cap: "<<kmCap<< "km"<<endl;
    cout<<"Extra Charge: "<<extraChargePerKm<<" OMR/km over cap"<<endl;
}

//Unlimited KM:

UnlimitedKM::UnlimitedKM(double flatRatePerDay): flatRatePerDay(flatRatePerDay) {}

double UnlimitedKM::calculateCost(double pricePerDay, int days, double kmDriven){
    return flatRatePerDay*days;
}

void UnlimitedKM::displayInfo(){
    cout<<"Plan: Unlimited KM"<<endl;
    cout<<"Flat Rate: "<<flatRatePerDay<<" OMR/day"<<endl;
}