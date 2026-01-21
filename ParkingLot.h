#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <stack>
#include <queue>
#include <string>

class ParkingLot {
public:
    ParkingLot(int capacity);

    // Main actions
    void arrive(const std::string& carNumber);
    void depart(const std::string& carNumber);

    // Display functions
    void showParking() const;
    void showWaiting() const;

private:
    int capacity;                     // maximum cars allowed
    std::stack<std::string> parking;  // stores parked cars
    std::queue<std::string> waiting;  // stores cars waiting outside

    // Helper function to move waiting cars into parking
    void moveCarFromQueue();

    // Helper functions to check if a car already exists
    bool isInParking(const std::string& carNumber) const;
    bool isInWaiting(const std::string& carNumber) const;
};

#endif
