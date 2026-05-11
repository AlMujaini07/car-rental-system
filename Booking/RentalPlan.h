#ifndef RENTALPLAN_H
#define RENTALPLAN_H
#include <iostream>
using namespace std;


class RentalPlan {
    public:
        virtual double calculateCost(double pricePerDay, int days, double kmDriven) = 0;
        virtual void displayInfo() = 0;
        virtual ~RentalPlan() {}
};

class LimitedKM: public RentalPlan {
    private:
        double kmCap, extraChargePerKm;
    public:
        LimitedKM(double kmCap, double extraChargePerKm);
        double calculateCost(double pricePerDay,int days, double kmDriven);
        void displayInfo();
};
class UnlimitedKM: public RentalPlan{
    private:
        double flatRatePerDay;
    public:
        UnlimitedKM(double flatRatePerDay);
        double calculateCost(double pricePerDay,int days, double kmDriven);
        void displayInfo();
};

#endif