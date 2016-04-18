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
    map<Vehicle*, pair<int, int>> vehicle2spot;
    vector<vector<Vehicle*> > spots;
    int moto_start;
    int compact_start;
    int large_start;
    int num_rows;
    int spots_per_row;
public:
    Level(int num_rows, int spots_per_row) {
        this->num_rows = num_rows;
        this->spots_per_row = spots_per_row;
        moto_start = 0;
        compact_start = spots_per_row / 4;
        large_start = spots_per_row / 4 * 3;
        vector<Vehicle*> row_spots(spots_per_row, NULL);
        spots.resize(num_rows, row_spots);
    }

    bool ParkVehicleInMoto(Vehicle* vehicle) {
        for (int r = 0; r < num_rows; r++) {
            for (int c = moto_start; c < compact_start; c++) {
                if(spots[r][c] == NULL) {
                    spots[r][c] = vehicle;
                    vehicle2spot[vehicle] = make_pair(r, c);
                    return true;
                }
            }
        }
        return false;
    }

    bool ParkVehicleInCompact(Vehicle* vehicle) {
        for (int r = 0; r < num_rows; r++) {
            for (int c = compact_start; c < large_start; c++) {
                if(spots[r][c] == NULL) {
                    spots[r][c] = vehicle;
                    vehicle2spot[vehicle] = make_pair(r, c);
                    return true;
                }
            }
        }
        return false;
    }

    bool ParkVehicleInLarge(Vehicle* vehicle) {
        VehicleSize size = vehicle->size();
        for (int r = 0; r < num_rows; r++) {
            for (int c = large_start; c < spots_per_row; c++) {
                if(spots[r][c] == NULL) {
                    if (size != VehicleSize::Large) {
                        spots[r][c] = vehicle;
                        vehicle2spot[vehicle] = make_pair(r, c);
                        return true;
                    } else {
                        if (spots_per_row - c >= 5) {
                            for (int i = c; i < c + 5; i++) {
                                spots[r][i] = vehicle;
                                if (i == c)
                                    vehicle2spot[vehicle] = make_pair(r, i);
                            }
                            return true;
                        }
                        break;
                    }
                }
            }
        }
        return false;
    }

    bool ParkVehicle(Vehicle* vehicle) {
        VehicleSize size = vehicle->size();
        if (size == VehicleSize::Motorcycle) {
            if(!ParkVehicleInMoto(vehicle)) {
                if(!ParkVehicleInCompact(vehicle)) {
                    return ParkVehicleInLarge(vehicle);
                }
            }
            return true;
        } else if (size == VehicleSize::Compact) {
            if(!ParkVehicleInCompact(vehicle)) {
                return ParkVehicleInLarge(vehicle);
            }
            return true;
        } else {
            return ParkVehicleInLarge(vehicle);
        }    
    }

    void unParkVehicle(Vehicle *vehicle) {
        pair<int, int> spot = vehicle2spot[vehicle];
        int r = spot.first;
        int c = spot.second;
        for(int i = c; i < c + 5; i++) {
            if (spots[r][i] == vehicle) {
                spots[r][i] = NULL;
            } else {
                break;
            }
        }
        vehicle2spot.erase(vehicle);
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
        Level *level = vehicle2level[&vehicle];
        if (level) {
            cout<<"already parked"<<endl;
            return true;
        }
        
        for (int i = 0; i < levels.size(); i++) {
            if (levels[i]->ParkVehicle(&vehicle)) {
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
            vehicle2level.erase(&vehicle);
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
    
    ParkingLot PL (1,1,11) ;
    cout<<PL.parkVehicle(*m1)<<endl;
    cout<<PL.parkVehicle(*c1)<<endl;
    cout<<PL.parkVehicle(*c2)<<endl;
    cout<<PL.parkVehicle(*c3)<<endl;
    cout<<PL.parkVehicle(*c4)<<endl;
    cout<<PL.parkVehicle(*c5)<<endl;
    cout<<PL.parkVehicle(*b1)<<endl;
    PL.unParkVehicle(*c5);
    cout<<PL.parkVehicle(*b1)<<endl;
    cout<<PL.parkVehicle(*b2)<<endl;
    
    return 1;
    
}

output:
1
1
1
1
1
1
0
1
0
 
