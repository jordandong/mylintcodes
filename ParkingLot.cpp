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


//Could pass OJ
#include <memory>

// Time:  O(n * m * k)
// Space: O(n * m * k)

// enum type for Vehicle
enum class VehicleSize {
    Motorcycle,
    Compact,
    Large
};

// Foward declaration to make circular reference work.
class ParkingSpot;
class Level;

// Use pImpl idiom to make copy assignment work.
class VehicleImpl {
public:
    vector<weak_ptr<ParkingSpot>> parking_spots() const noexcept {
        return parking_spots_;
    }

    int spots_needed() const noexcept {
        return spots_needed_;
    }

    VehicleSize size() const noexcept {
        return size_;
    }

    void park_in_spot(const shared_ptr<ParkingSpot>& spot) {
        parking_spots_.emplace_back(spot);
    }

    void clear_spots();

    virtual bool can_fit_in_spot(const shared_ptr<ParkingSpot>& spot)
        const noexcept {
        return true;
    }

protected:
    vector<weak_ptr<ParkingSpot>> parking_spots_;
    int spots_needed_;
    VehicleSize size_;
};

class Vehicle {
public:
    Vehicle() : pImpl_(new VehicleImpl()) {}

    vector<weak_ptr<ParkingSpot>> parking_spots() const noexcept {
        return pImpl_->parking_spots();
    }

    int spots_needed() const noexcept {
        return pImpl_->spots_needed();
    }

    VehicleSize size() const noexcept {
        return pImpl_->size();
    }

    void park_in_spot(const shared_ptr<ParkingSpot>& spot) {
        pImpl_->park_in_spot(spot);
    }

    void clear_spots() {
        pImpl_->clear_spots();
    }

    virtual bool can_fit_in_spot(const shared_ptr<ParkingSpot>& spot)
        const noexcept {
        return pImpl_->can_fit_in_spot(spot);
    }

protected:
    shared_ptr<VehicleImpl> pImpl_;
};

class ParkingSpot : public std::enable_shared_from_this<ParkingSpot> {
public:
    ParkingSpot(const shared_ptr<Level>& level, int row,
                int spot_number, VehicleSize spot_size) :
        level_(level), row_(row),
        spot_number_(spot_number), spot_size_(spot_size),
        vehicle_(nullptr) {}

    bool is_available() const noexcept {
        return vehicle_ == nullptr;
    }

    bool can_fit_vehicle(Vehicle *vehicle) {
        return is_available() && vehicle->can_fit_in_spot(shared_from_this());
    }

    void park(Vehicle *vehicle) {
        vehicle_ = vehicle;
        vehicle_->park_in_spot(shared_from_this());
    }

    void remove_vehicle();

    int row() const noexcept {
        return row_;
    }

    int spot_number() const noexcept {
        return spot_number_;
    }

    VehicleSize size() const noexcept {
        return spot_size_;
    }

private:
    weak_ptr<Level> level_;
    int row_, spot_number_;
    VehicleSize spot_size_;
    Vehicle *vehicle_;
};

// Use pImpl idiom to make copy assignment work.
class BusImpl: public VehicleImpl {
public:
    BusImpl() {
        spots_needed_ = 5;
        size_ = VehicleSize::Large;
    }

    virtual bool can_fit_in_spot(const shared_ptr<ParkingSpot>& spot)
        const noexcept {
        return spot->size() == VehicleSize::Large;
    }
};

class Bus: public Vehicle {
public:
    Bus() {
        pImpl_ = make_shared<BusImpl>();
    }
};

// Use pImpl idiom to make copy assignment work.
class CarImpl: public VehicleImpl {
public:
    CarImpl() {
        spots_needed_ = 1;
        size_ = VehicleSize::Compact;
    }

    virtual bool can_fit_in_spot(const shared_ptr<ParkingSpot>& spot)
        const noexcept {
        return spot->size() != VehicleSize::Motorcycle;
    }
};

class Car: public Vehicle {
public:
    Car() {
        pImpl_ = make_shared<CarImpl>();
    }
};

// Use pImpl idiom to make copy assignment work.
class MotorcycleImpl: public VehicleImpl {
public:
    MotorcycleImpl() {
        spots_needed_ = 1;
        size_ = VehicleSize::Motorcycle;
    }

    virtual bool can_fit_in_spot(const shared_ptr<ParkingSpot>& spot)
        const noexcept {
        return true;
    }
};

class Motorcycle: public Vehicle {
public:
    Motorcycle() {
        pImpl_ = make_shared<MotorcycleImpl>();
    }
};

class Level : public std::enable_shared_from_this<Level> {
public:
    Level(int flr, int num_rows, int spots_per_row) :
        num_rows_(num_rows),
        floor_(flr),
        spots_per_row_(spots_per_row),
        number_spots_(0),
        available_spots_(0) {
    }

    // Use two-phase construction to avoid the problem that
    // shared_from_this() cannot be used in ctor!
    void init() {
        for (int row = 0; row < num_rows_; ++row) {
            int i = 0;
            for (; i < spots_per_row_ / 4; ++i) {
                spots_.emplace_back(
                    make_shared<ParkingSpot>(shared_from_this(),
                                             row, number_spots_,
                                             VehicleSize::Motorcycle));
                ++number_spots_;
            }

            for (; i < spots_per_row_ / 4 * 3; ++i) {
                spots_.emplace_back(
                    make_shared<ParkingSpot>(shared_from_this(),
                                             row, number_spots_,
                                             VehicleSize::Compact));
                ++number_spots_;
            }

            for (; i < spots_per_row_; ++i) {
                spots_.emplace_back(
                    make_shared<ParkingSpot>(shared_from_this(),
                                             row, number_spots_,
                                             VehicleSize::Large));
                ++number_spots_;
            }
        }
        available_spots_ = number_spots_;
    }

    bool park_vehicle(Vehicle *vehicle) {
        if (available_spots() < vehicle->spots_needed()) {
            return false;
        }

        const auto& spot_num = find_available_spots(vehicle);
        if (spot_num < 0) {
            return false;
        } else {
            park_starting_at_spot(spot_num, vehicle);
            return true;
        }
    }

    int find_available_spots(Vehicle *vehicle) {
        const auto& spots_needed = vehicle->spots_needed();
        int last_row = -1;
        int spots_found = 0;

        for (int i = 0; i < spots_.size(); ++i) {
            auto& spot = spots_[i];
            if (last_row != spot->row()) {
                spots_found = 0;
                last_row = spot->row();
            }
            if (spot->can_fit_vehicle(vehicle)) {
                ++spots_found;
            } else {
                spots_found = 0;
            }

            if (spots_found == spots_needed) {
                return i - (spots_needed - 1);
            }
        }

        return -1;
    }

    void park_starting_at_spot(int spot_num, Vehicle *vehicle) {
        for (int i = spot_num; i < spot_num + vehicle->spots_needed(); ++i) {
            spots_[i]->park(vehicle);
        }
        available_spots_ -= vehicle->spots_needed();
    }

    void spot_freed() noexcept {
        ++available_spots_;
    }

    int available_spots() const noexcept {
        return available_spots_;
    }

private:
    int num_rows_;
    int floor_;
    int spots_per_row_;
    int number_spots_;
    int available_spots_;
    vector<shared_ptr<ParkingSpot>> spots_;
};

void VehicleImpl::clear_spots() {
    for (const auto& spot : parking_spots_) {
        if (auto spt = spot.lock()) {
            spt->remove_vehicle();
        }
    }
    parking_spots_.clear();
}

void ParkingSpot::remove_vehicle() {
    if (auto spt = level_.lock()) {
        spt->spot_freed();
    }
    vehicle_ = nullptr;
}

class ParkingLot {
public:
    // @param n number of leves
    // @param num_rows  each level has num_rows rows of spots
    // @param spots_per_row each row has spots_per_row spots
    ParkingLot(int n, int num_rows, int spots_per_row) {
        for (int i = 0; i < n; ++i) {
            auto&& ptr = make_shared<Level>(i, num_rows, spots_per_row);
            ptr->init();
            levels_.emplace_back(ptr);
        }
    }

    // Park the vehicle in a spot (or multiple spots)
    // Return false if failed
    bool parkVehicle(Vehicle &vehicle) {
        unParkVehicle(vehicle);  // This may make the parked vehicle move to another place.

        for (auto& level : levels_) {
            if (level->park_vehicle(&vehicle)) {
                return true;
            }
        }
        return false;
    }

    // unPark the vehicle
    void unParkVehicle(Vehicle &vehicle) {
        vehicle.clear_spots();
    }

private:
    vector<shared_ptr<Level>> levels_;
};
 
