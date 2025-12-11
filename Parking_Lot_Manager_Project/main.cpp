#include <iostream>
#include "ParkingLot.h"

int main() {
    int cap;
    std::cout << "Enter parking lot capacity: ";
    std::cin >> cap;

    ParkingLot lot(cap);

    while (true) {
        std::cout << "\n--- MENU ---\n";
        std::cout << "1. Arrive (Add Car)\n";
        std::cout << "2. Depart (Remove Car)\n";
        std::cout << "3. Show Parking\n";
        std::cout << "4. Show Waiting Queue\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose option: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string car;
            std::cout << "Enter car number: ";
            std::cin >> car;
            lot.arrive(car);
        }
        else if (choice == 2) {
            std::string car;
            std::cout << "Enter car number to remove: ";
            std::cin >> car;
            lot.depart(car);
        }
        else if (choice == 3) {
            lot.showParking();
        }
        else if (choice == 4) {
            lot.showWaiting();
        }
        else if (choice == 5) {
            std::cout << "Goodbye!\n";
            break;
        }
        else {
            std::cout << "Invalid option.\n";
        }
    }

    return 0;
}
