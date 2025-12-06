# 1603 Design-Parking-System

A C++ class design to manage a parking lot with different slot sizes.

-----

## 📊 Difficulty Level

**Easy**

## 🔗 Problem Link

[LeetCode 1603: Design Parking System](https://leetcode.com/problems/design-parking-system/)

## 🏷️ Topic Tags

  - Design
  - Simulation
  - Counting

-----

## Problem

Design a parking system for a parking lot. The parking lot has three kinds of parking spaces: big, medium, and small, with a fixed number of slots for each size.

Implement the `ParkingSystem` class:

  - `ParkingSystem(int big, int medium, int small)` Initializes object of the `ParkingSystem` class. The number of slots for each parking space are given as part of the constructor.
  - `bool addCar(int carType)` Checks whether there is a parking space of `carType` for the car that wants to get into the parking lot. `carType` can be of three kinds: big, medium, or small, which are represented by 1, 2, and 3 respectively. A car can only park in a parking space of its `carType`. If there is no space available, return `false`, else park the car in that size space and return `true`.

-----

## Example

**Input:**

```cpp
["ParkingSystem", "addCar", "addCar", "addCar", "addCar"]
[[1, 1, 0], [1], [2], [3], [1]]
```

**Explanation:**

1.  `ParkingSystem parkingSystem(1, 1, 0);` // Slots: Big=1, Medium=1, Small=0
2.  `parkingSystem.addCar(1);` // return true because there is 1 available slot for a big car. Slots: Big=0, Medium=1, Small=0
3.  `parkingSystem.addCar(2);` // return true because there is 1 available slot for a medium car. Slots: Big=0, Medium=0, Small=0
4.  `parkingSystem.addCar(3);` // return false because there is no available slot for a small car.
5.  `parkingSystem.addCar(1);` // return false because there is no available slot for a big car.

**Output:** `[null, true, true, false, false]`

-----

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

class ParkingSystem {
public:
    // Array to store counts for Big (index 1), Medium (index 2), and Small (index 3)
    int sloat[4]; 
    
    ParkingSystem(int big, int medium, int small) {
        sloat[1] = big;
        sloat[2] = medium;
        sloat[3] = small;
    }
    
    bool addCar(int carType) {
        // Check if there is space available for the specific car type
        if (sloat[carType] > 0) {
            sloat[carType]--; // Decrement the available slot count
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

// Example main to demonstrate usage
int main() {
    // Initialize with 1 Big, 1 Medium, and 0 Small slots
    ParkingSystem* obj = new ParkingSystem(1, 1, 0);
    
    cout << "Add Big Car (Type 1): " << (obj->addCar(1) ? "True" : "False") << endl;    // Output: True
    cout << "Add Medium Car (Type 2): " << (obj->addCar(2) ? "True" : "False") << endl; // Output: True
    cout << "Add Small Car (Type 3): " << (obj->addCar(3) ? "True" : "False") << endl;  // Output: False
    cout << "Add Big Car (Type 1): " << (obj->addCar(1) ? "True" : "False") << endl;    // Output: False

    delete obj;
    return 0;
}
```

-----

## Complexity

  - **Time:** $O(1)$ for both the constructor and the `addCar` function. Accessing and updating an array by index takes constant time.
  - **Space:** $O(1)$. We use a fixed-size integer array of size 4, regardless of the input.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o parking_system main.cpp`
  - **Run:** `./parking_system`

-----

## Notes

  - The solution uses a simple array `sloat` of size 4 to map the `carType` directly to an index.
      - Index 1 maps to `big`.
      - Index 2 maps to `medium`.
      - Index 3 maps to `small`.
  - Index 0 is unused but allows for cleaner code since `carType` is 1-indexed.
