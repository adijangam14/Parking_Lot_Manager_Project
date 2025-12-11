#include "ParkingLot.h"
#include <iostream>

// Constructor
ParkingLot::ParkingLot(int capacity) {
    this->capacity = capacity;
}

// ---------------------------------------------------------
// ARRIVE FUNCTION
// ---------------------------------------------------------
void ParkingLot::arrive(const std::string& carNumber) {
    // Prevent duplicates
    if (isInParking(carNumber) || isInWaiting(carNumber)) {
        std::cout << "Car " << carNumber << " is already here.\n";
        return;
    }

    // If there is space, park the car
    if ((int)parking.size() < capacity) {
        parking.push(carNumber);
        std::cout << "Car parked: " << carNumber << "\n";
    }
    else {
        // Otherwise put it in waiting queue
        waiting.push(carNumber);
        std::cout << "Parking full. Car added to waiting queue.\n";
    }
}

// ---------------------------------------------------------
// DEPART FUNCTION
// ---------------------------------------------------------
void ParkingLot::depart(const std::string& carNumber) {
    // First check waiting queue
    if (isInWaiting(carNumber)) {
        std::queue<std::string> tempQueue;
        while (!waiting.empty()) {
            if (waiting.front() == carNumber) {
                std::cout << "Removed " << carNumber << " from waiting queue.\n";
                waiting.pop();
                break;
            }
            tempQueue.push(waiting.front());
            waiting.pop();
        }
        waiting = tempQueue;
        return;
    }

    // If car is not found in parking
    if (!isInParking(carNumber)) {
        std::cout << "Car not found.\n";
        return;
    }

    // Car IS in parking; remove it carefully
    std::stack<std::string> temp;
    bool found = false;

    // Move cars until target is found
    while (!parking.empty()) {
        if (parking.top() == carNumber) {
            std::cout << "Car departed: " << carNumber << "\n";
            parking.pop();
            found = true;
            break;
        }
        else {
            temp.push(parking.top());
            parking.pop();
        }
    }

    // Restore the other cars
    while (!temp.empty()) {
        parking.push(temp.top());
        temp.pop();
    }

    // After removing, a free space exists → move from waiting queue
    moveCarFromQueue();
}

// ---------------------------------------------------------
// DISPLAY FUNCTIONS
// ---------------------------------------------------------
void ParkingLot::showParking() const {
    std::cout << "\nParking (top → bottom):\n";

    if (parking.empty()) {
        std::cout << "  [empty]\n";
        return;
    }

    std::stack<std::string> copy = parking;
    while (!copy.empty()) {
        std::cout << "  " << copy.top() << "\n";
        copy.pop();
    }
}

void ParkingLot::showWaiting() const {
    std::cout << "\nWaiting Queue (front → back):\n";

    if (waiting.empty()) {
        std::cout << "  [empty]\n";
        return;
    }

    std::queue<std::string> copy = waiting;
    while (!copy.empty()) {
        std::cout << "  " << copy.front() << "\n";
        copy.pop();
    }
}

// ---------------------------------------------------------
// HELPER: Move car from queue into parking
// ---------------------------------------------------------
void ParkingLot::moveCarFromQueue() {
    if ((int)parking.size() < capacity && !waiting.empty()) {
        std::string nextCar = waiting.front();
        waiting.pop();
        parking.push(nextCar);
        std::cout << "Moved from waiting → parked: " << nextCar << "\n";
    }
}

// ---------------------------------------------------------
// HELPER: Check functions
// ---------------------------------------------------------
bool ParkingLot::isInParking(const std::string& carNumber) const {
    std::stack<std::string> copy = parking;
    while (!copy.empty()) {
        if (copy.top() == carNumber)
            return true;
        copy.pop();
    }
    return false;
}

bool ParkingLot::isInWaiting(const std::string& carNumber) const {
    std::queue<std::string> copy = waiting;
    while (!copy.empty()) {
        if (copy.front() == carNumber)
            return true;
        copy.pop();
    }
    return false;
}
