# ParkingLotManager

A simple command-line application to manage a parking lot.

## Features

*   Park cars in a parking lot with a limited capacity.
*   When the parking lot is full, cars are added to a waiting queue.
*   Remove cars from the parking lot or the waiting queue.
*   When a car leaves the parking lot, the first car from the waiting queue is moved to the parking lot.
*   Display the cars in the parking lot and the waiting queue.

## How to build and run

### Prerequisites

*   A C++17 compatible compiler (e.g., GCC, Clang)
*   CMake (version 3.10 or later)

### Build steps

1.  Create a build directory:
    ```bash
    mkdir build
    ```
2.  Navigate to the build directory:
    ```bash
    cd build
    ```
3.  Run CMake to configure the project:
    ```bash
    cmake ..
    ```
4.  Build the project:
    ```bash
    cmake --build .
    ```

### Running the application

After building the project, you can run the application from the `build` directory:

```bash
./parking_lot
```

## Example Usage

```
Enter parking lot capacity: 2

--- MENU ---
1. Arrive (Add Car)
2. Depart (Remove Car)
3. Show Parking
4. Show Waiting Queue
5. Exit
Choose option: 1
Enter car number: CAR1
Car parked: CAR1

--- MENU ---
1. Arrive (Add Car)
2. Depart (Remove Car)
3. Show Parking
4. Show Waiting Queue
5. Exit
Choose option: 1
Enter car number: CAR2
Car parked: CAR2

--- MENU ---
1. Arrive (Add Car)
2. Depart (Remove Car)
3. Show Parking
4. Show Waiting Queue
5. Exit
Choose option: 1
Enter car number: CAR3
Parking full. Car added to waiting queue.

--- MENU ---
1. Arrive (Add Car)
2. Depart (Remove Car)
3. Show Parking
4. Show Waiting Queue
5. Exit
Choose option: 3

Parking (top → bottom):
  CAR2
  CAR1

--- MENU ---
1. Arrive (Add Car)
2. Depart (Remove Car)
3. Show Parking
4. Show Waiting Queue
5. Exit
Choose option: 4

Waiting Queue (front → back):
  CAR3

--- MENU ---
1. Arrive (Add Car)
2. Depart (Remove Car)
3. Show Parking
4. Show Waiting Queue
5. Exit
Choose option: 2
Enter car number to remove: CAR1
Car departed: CAR1
Moved from waiting → parked: CAR3

--- MENU ---
1. Arrive (Add Car)
2. Depart (Remove Car)
3. Show Parking
4. Show Waiting Queue
5. Exit
Choose option: 3

Parking (top → bottom):
  CAR3
  CAR2

--- MENU ---
1. Arrive (Add Car)
2. Depart (Remove Car)
3. Show Parking
4. Show Waiting Queue
5. Exit
Choose option: 5
Goodbye!
```
