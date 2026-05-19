#include <iostream>
#include <string>
#include <vector>
#include "RentalAgency/RentalAgency.h"
#include "Car/SportsCar.h"
#include "Car/LuxuryCar.h"
#include "Car/OffRoadCar.h"
#include "Car/ElectricCar.h"
#include "Booking/RentalPlan.h"

using namespace std;

void handleCarMenu(RentalAgency& agency) {
    int choice;
    do {
    cout << "\n--- Car Management ---" << endl;
    cout << "1. Add Car" << endl;
    cout << "2. Remove Car" << endl;
    cout << "3. View All Cars" << endl;
    cout << "4. View Available Cars" << endl;
    cout << "5. Search by Price Range" << endl;
    cout << "0. Back" << endl;
    cout << "Choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int type;
            cout << "Car Type: 1.Regular  2.Sports  3.Luxury  4.OffRoad  5.Electric: ";
            cin >> type;

            string brand, model, subModel, plate, color;
            int year, numSeats;
            double pricePerDay, totalKm, fuelLevel;

            cout << "Brand: ";           
            cin >> brand;
            cout << "Model: ";           
            cin >> model;
            cout << "SubModel: ";        
            cin >> subModel;
            cout << "Year: ";            
            cin >> year;
            cout << "Price/Day (OMR): "; 
            cin >> pricePerDay;
            cout << "Number Plate: ";    
            cin >> plate;
            cout << "Total KM: ";        
            cin >> totalKm;
            cout << "Fuel Level (%): ";  
            cin >> fuelLevel;
            cout << "Num Seats: ";       
            cin >> numSeats;
            cout << "Color: ";           
            cin >> color;

            Car* car = nullptr;

            if (type == 1) {
                car = new Car(brand, model, subModel, year, pricePerDay,
                              plate, totalKm, 0, fuelLevel, numSeats, color);

            } else if (type == 2) {
                int hp, torque, topSpeed;
                double zeroToHundred;
                bool hasTurbo;
                cout << "Horsepower: ";       
                cin >> hp;
                cout << "Torque (Nm): ";      
                cin >> torque;
                cout << "Has Turbo (1 or 0): ";  
                cin >> hasTurbo;
                cout << "Top Speed (km/h): "; 
                cin >> topSpeed;
                cout << "0-100 (seconds): ";  
                cin >> zeroToHundred;
                car = new SportsCar(brand, model, subModel, year, pricePerDay,
                                    plate, totalKm, 0, fuelLevel, numSeats, color,
                                    hp, torque, hasTurbo, topSpeed, zeroToHundred);

            } else if (type == 3) {
                string seatMaterial, soundSystem;
                bool hasHeatedSeats, hasMassageSeats;
                int hp;
                cout << "Seat Material: ";       
                cin >> seatMaterial;
                cout << "Sound System: ";        
                cin >> soundSystem;
                cout << "Heated Seats (1 or 0): ";  
                cin >> hasHeatedSeats;
                cout << "Massage Seats (1 or 0): "; 
                cin >> hasMassageSeats;
                cout << "Horsepower: ";          
                cin >> hp;
                car = new LuxuryCar(brand, model, subModel, year, pricePerDay,
                                    plate, totalKm, 0, fuelLevel, numSeats, color,
                                    seatMaterial, soundSystem, hasHeatedSeats, hasMassageSeats, hp);

            } else if (type == 4) {
                bool hasDiffLock, hasFourWD, hasLowRange;
                int groundClearance, hp;
                string terrainType;
                cout << "Diff Lock (1 or 0): ";        
                cin >> hasDiffLock;
                cout << "4WD (1 or 0): ";              
                cin >> hasFourWD;
                cout << "Ground Clearance (mm): ";  
                cin >> groundClearance;
                cout << "Terrain Type: ";           
                cin >> terrainType;
                cout << "Horsepower: ";             
                cin >> hp;
                cout << "Low Range (1 or 0): ";        
                cin >> hasLowRange;
                car = new OffRoadCar(brand, model, subModel, year, pricePerDay,
                                     plate, totalKm, 0, fuelLevel, numSeats, color,
                                     hasDiffLock, hasFourWD, groundClearance, terrainType, hp, hasLowRange);

            } else if (type == 5) {
                int batteryRange, hp, torque;
                double batteryLevel, chargingCost, chargingTime;
                cout << "Battery Range (km): ";      
                cin >> batteryRange;
                cout << "Battery Level (%): ";       
                cin >> batteryLevel;
                cout << "Charging Cost/kWh (OMR): "; 
                cin >> chargingCost;
                cout << "Horsepower: ";              
                cin >> hp;
                cout << "Torque (Nm): ";             
                cin >> torque;
                cout << "Charging Time (hours): ";   
                cin >> chargingTime;
                car = new ElectricCar(brand, model, subModel, year, pricePerDay,
                                      plate, totalKm, 0, fuelLevel, numSeats, color,
                                      batteryRange, batteryLevel, chargingCost, hp, torque, chargingTime);
            }

            if (car) {
                agency.addCar(car);
                cout << "Car added successfully." << endl;
            } else {
                cout << "Invalid car type." << endl;
            }
            break;
        }
        case 2: {
            string plate;
            cout << "Number Plate: "; 
            cin >> plate;
            try {
                agency.removeCar(plate);
                cout << "Car removed." << endl;
            } catch (runtime_error& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }
        case 3: agency.displayAllCars(); break;
        case 4: agency.displayAvailableCars(); break;
        case 5: {
            double min, max;
            cout << "Min price (OMR): "; 
            cin >> min;
            cout << "Max price (OMR): "; 
            cin >> max;
            vector<Car*> results = agency.searchAvailableCars(min, max);
            if (results.empty())
                cout << "No cars found in this price range." << endl;
            else
                for (Car* c : results) { c->displayInfo(); cout << endl; }
            break;
        }
        case 0: break;
        default: cout << "Invalid choice." << endl;
    }
    } while (choice != 0);
}

void handleBookingMenu(RentalAgency& agency) {
    int choice;
    do {
    cout << "\n--- Booking Management ---" << endl;
    cout << "1. Register Customer" << endl;
    cout << "2. Make Booking" << endl;
    cout << "3. Cancel Booking" << endl;
    cout << "4. Complete Booking" << endl;
    cout << "5. View All Bookings" << endl;
    cout << "6. Find Booking by ID" << endl;
    cout << "0. Back" << endl;
    cout << "Choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            string name, license;
            int age;
            bool hasLicense;
            cout << "Name: ";                    
            cin >> name;
            cout << "Age: ";                     
            cin >> age;
            cout << "License Number: ";          
            cin >> license;
            cout << "Has Valid License (1/0): "; 
            cin >> hasLicense;
            try {
                agency.registerCustomer(new Customer(name, age, license, hasLicense));
                cout << "Customer registered." << endl;
            } catch (runtime_error& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }
        case 2: {
            string license, plate;
            cout << "Customer License: "; 
            cin >> license;
            cout << "Car Number Plate: "; 
            cin >> plate;

            Customer* customer = agency.findCustomerByLicense(license);
            Car* car = agency.findCarByPlate(plate);

            if (!customer) 
            { cout << "Customer not found." << endl; break; }
            if (!car)      
            { cout << "Car not found." << endl; break; }

            int sd, sm, sy, ed, em, ey;
            cout << "Start Date (day month year): "; 
            cin >> sd >> sm >> sy;
            cout << "End Date   (day month year): "; 
            cin >> ed >> em >> ey;

            time_t start = Booking::makeDate(sd, sm, sy);
            time_t end   = Booking::makeDate(ed, em, ey);

            int planChoice;
            cout << "Rental Plan: 1.LimitedKM  2.UnlimitedKM: "; cin >> planChoice;

            RentalPlan* plan = nullptr;
            if (planChoice == 1) {
                double kmCap, extraCharge;
                cout << "KM Cap: ";                
                cin >> kmCap;
                cout << "Extra charge/km (OMR): "; 
                cin >> extraCharge;
                plan = new LimitedKM(kmCap, extraCharge);
            } else {
                double flatRate;
                cout << "Flat rate/day (OMR): "; 
                cin >> flatRate;
                plan = new UnlimitedKM(flatRate);
            }

            try {
                Booking* b = agency.makeBooking(customer, car, start, end, plan);
                cout << "Booking created: " << b->getBookingID() << endl;
            } catch (runtime_error& e) {
                cout << "Error: " << e.what() << endl;
                delete plan;
            }
            break;
        }
        case 3: {
            string id;
            cout << "Booking ID: "; 
            cin >> id;
            try {
                agency.cancelBooking(id);
                cout << "Booking cancelled." << endl;
            } catch (runtime_error& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }
        case 4: {
            string id, method;
            cout << "Booking ID: ";      
            cin >> id;
            cout << "Payment Method (Cash/Card/Online): "; 
            cin >> method;
            try {
                agency.completeBooking(id, method);
                cout << "Booking completed." << endl;
            } catch (runtime_error& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }
        case 5: agency.displayAllBookings(); break;
        case 6: {
            string id;
            cout << "Booking ID: "; 
            cin >> id;
            Booking* b = agency.findBooking(id);
            if (b) b->displayInfo();
            else   
            cout << "Booking not found." << endl;
            break;
        }
        case 0: break;
        default: cout << "Invalid choice." << endl;
    }
    } while (choice != 0);
}

int main() {
    RentalAgency agency("Muscat Car Rentals");
    int choice;

    do {
        cout << "\n=== " << agency.getAgencyName() << " ===" << endl;
        cout << "1. Car Management"     << endl;
        cout << "2. Booking Management" << endl;
        cout << "0. Exit"               << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: handleCarMenu(agency);      break;
            case 2: handleBookingMenu(agency);  break;
            case 0: cout << "Goodbye!" << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    return 0;
}
