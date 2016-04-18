/*
Design a parking lot.

see CC150 OO Design for details.
1) n levels, each level has m rows of spots and each row has k spots.So each level has m x k spots.
2) The parking lot can park motorcycles, cars and buses
3) The parking lot has motorcycle spots, compact spots, and large spots
4) Each row, motorcycle spots id is in range [0,k/4)(0 is included, k/4 is not included), compact spots id is in range [k/4,k/4*3) and large spots id is in range [k/4*3,k).
5) A motorcycle can park in any spot
6) A car park in single compact spot or large spot
7) A bus can park in five large spots that are consecutive and within same row. it can not park in small spots

Have you met this question in a real interview? Yes
Example
level=1, num_rows=1, spots_per_row=11
parkVehicle("Motorcycle_1") // return true
parkVehicle("Car_1") // return true
parkVehicle("Car_2") // return true
parkVehicle("Car_3") // return true
parkVehicle("Car_4") // return true
parkVehicle("Car_5") // return true
parkVehicle("Bus_1") // return false
unParkVehicle("Car_5")
parkVehicle("Bus_1") // return true

Tags 
OO Design
*/

//Passed in Local
// Example program
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

// enum type for Vehicle
enum class VehicleSize {
    Motorcycle,
    Compact,
    Large,
    Default
};

class Vehicle {
public:
    virtual VehicleSize size() {
        return VehicleSize::Default;
    }
};

class Bus: public Vehicle {
public:
    virtual VehicleSize size() {
        return VehicleSize::Large;
    }
};

class Car: public Vehicle {
public:
    virtual VehicleSize size() {
        return VehicleSize::Compact;
    }
};

class Motorcycle: public Vehicle {
public:
    virtual VehicleSize size() {
        return VehicleSize::Motorcycle;
    }
};

class Level {
private:
    vector<Vehicle* > motoSpots;
    vector<Vehicle* > compactSpots;
    vector<Vehicle* > largeSpots;
    map<Vehicle*, pair<VehicleSize, int>> vehicle2spot;
public:
    Level(int num_rows, int spots_per_row) {
        int motoSpotSize = spots_per_row / 4;
        motoSpots.resize(motoSpotSize);
        int compactSpotSize = spots_per_row / 4 * 3 - motoSpotSize;
        compactSpots.resize(compactSpotSize);
        int largeSpotSize = spots_per_row - motoSpotSize - compactSpotSize;
        largeSpots.resize(largeSpotSize);
    }

    int canParkVehicle(Vehicle* vehicle, VehicleSize size, int num) {
        if (size == VehicleSize::Motorcycle) {
            for(int i = 0; i < motoSpots.size(); i++) {
                if (motoSpots[i] == NULL) {
                    return i;
                }
            }
            return -1;
        } else if (size == VehicleSize::Compact) {
            for(int i = 0; i < compactSpots.size(); i++) {
                if (compactSpots[i] == NULL) {
                    return i;
                }
            }
            return -1;
        } else {
            for(int i = 0; i < largeSpots.size(); i++) {
                if (largeSpots[i] == NULL) {
                    bool flag = true;
                    for(int j = i; j < i + num; j++) {
                        if (largeSpots[j] != NULL) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        return i;
                    }
                }
            }
            return -1;
        }
    }

    void parkVehicle(Vehicle* vehicle, VehicleSize parkSpotType, int index, int num) {
        if (parkSpotType == VehicleSize::Motorcycle) {
            motoSpots[index] = vehicle;
        } else if (parkSpotType == VehicleSize::Compact) {
            compactSpots[index] = vehicle;
        } else {
            for(int i = index; i < index + num; i++) {
                largeSpots[i] = vehicle;
            }
        }
        vehicle2spot[vehicle] = make_pair(parkSpotType, index);
    }

    void unParkVehicle(Vehicle *vehicle) {
        pair<VehicleSize, int> spot = vehicle2spot[vehicle];
        VehicleSize size = spot.first;
        int index = spot.second;
        if (size == VehicleSize::Motorcycle) {
            motoSpots[index] = NULL;
        } else if (size == VehicleSize::Compact) {
            compactSpots[index] = NULL;
        } else {
            for(int i = index; i < index + largeSpots.size(); i++) {
                if (largeSpots[i] == vehicle) {
                    largeSpots[i] = NULL;
                } else {
                    break;
                }
            }
        }
    }
};

class ParkingLot {
private:
    vector<Level* > levels;
    map<Vehicle*, Level*> vehicle2level;
public:
    // @param n number of leves
    // @param num_rows  each level has num_rows rows of spots
    // @param spots_per_row each row has spots_per_row spots
    ParkingLot(int n, int num_rows, int spots_per_row) {
        for(int i = 0; i < n; i++) {
            Level *level = new Level(num_rows, spots_per_row);
            levels.push_back(level);
        }
    }

    // Park the vehicle in a spot (or multiple spots)
    // Return false if failed
    bool parkVehicle(Vehicle &vehicle) {
        VehicleSize size = vehicle.size();
        if (size == VehicleSize::Motorcycle) {
            if (!parkInMotoSpot(vehicle)) {
                if (!parkInCompactSpot(vehicle)) {
                    return parkInLargeSpot(vehicle, 1);
                }
            }
            return true;
        } else if (size == VehicleSize::Compact) {
            if (!parkInCompactSpot(vehicle)) {
                return parkInLargeSpot(vehicle, 1);
            }
            return true;
        } else if (size == VehicleSize::Large) {
            return parkInLargeSpot(vehicle, 5);
        } else {
            return false;
        }
    }

    bool parkInMotoSpot(Vehicle &vehicle) {
        for(int i = 0; i < levels.size(); i++) {
            int index = levels[i]->canParkVehicle(&vehicle, VehicleSize::Motorcycle, 1);
            if (index != -1) {
                levels[i]->parkVehicle(&vehicle, VehicleSize::Motorcycle, index, 1);
                vehicle2level[&vehicle] = levels[i];
                return true;
            }
        }
        return false;
    }

    bool parkInCompactSpot(Vehicle &vehicle) {
        for(int i = 0; i < levels.size(); i++) {
            int index = levels[i]->canParkVehicle(&vehicle, VehicleSize::Compact, 1);
            if (index != -1) {
                levels[i]->parkVehicle(&vehicle, VehicleSize::Compact, index, 1);
                vehicle2level[&vehicle] = levels[i];
                return true;
            }
        }
        return false;
    }

    bool parkInLargeSpot(Vehicle &vehicle, int num) {
        for(int i = 0; i < levels.size(); i++) {
            int index = levels[i]->canParkVehicle(&vehicle, VehicleSize::Large, num);
            if (index != -1) {
                levels[i]->parkVehicle(&vehicle, VehicleSize::Large, index, num);
                vehicle2level[&vehicle] = levels[i];
                return true;
            }
        }
        return false;
    }

    // unPark the vehicle
    void unParkVehicle(Vehicle &vehicle) {
        Level *level = vehicle2level[&vehicle];
        if (level) {
            level->unParkVehicle(&vehicle);
        }
    }
};

int main()
{
    Vehicle *m1 = new Motorcycle();
    Vehicle *c1 = new Car();
    Vehicle *c2 = new Car();
    Vehicle *c3 = new Car();
    Vehicle *c4 = new Car();
    Vehicle *c5 = new Car();
    Vehicle *b1 = new Bus();
    Vehicle *b2 = new Bus();
    
    ParkingLot PL(1,1,11) ;
    cout<<PL.parkVehicle(*m1)<<endl;
    cout<<PL.parkVehicle(*c1)<<endl;
    cout<<PL.parkVehicle(*c2)<<endl;
    cout<<PL.parkVehicle(*c3)<<endl;
    cout<<PL.parkVehicle(*c4)<<endl;
    cout<<PL.parkVehicle(*c5)<<endl;
    cout<<PL.parkVehicle(*b1)<<endl;
    PL.unParkVehicle(*c5);
    cout<<PL.parkVehicle(*b1)<<endl;
    
    return 1;
    
}

1
1
1
1
1
1
0
1
