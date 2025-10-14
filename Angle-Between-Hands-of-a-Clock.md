# Angle-Between-Hands-of-a-Clock

A C++ program to calculate the smaller angle between the hour and minute hands of a clock.

-----

## Problem

Given two numbers, `hour` and `minutes`, return the smaller angle (in degrees) formed between the two hands of an analog clock.

-----

## Example

**Input:** `hour = 12`, `minutes = 30`

**Explanation:**

1.  **Minute Hand Position:** At 30 minutes, the minute hand is exactly at the '6'. Its angle from the '12' is `30 minutes * 6 degrees/minute = 180` degrees.
2.  **Hour Hand Position:** At 12:30, the hour hand is halfway between the '12' and the '1'.
      * The position for the hour '12' is `12 * 30 degrees/hour = 360` degrees (or 0).
      * The additional movement due to minutes is `30 minutes * 0.5 degrees/minute = 15` degrees.
      * Total hour hand angle is `360 + 15 = 375` degrees.
3.  **Angle Difference:** The absolute difference is `|375 - 180| = 195` degrees.
4.  **Smaller Angle:** The angle can be measured clockwise or counter-clockwise. The smaller angle is `min(195, 360 - 195) = min(195, 165) = 165` degrees.

**Output:** `165`

-----

## Code

```cpp
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        // Each minute is 6 degrees (360/60)
        double minutes_angle = minutes * 6.0;
        
        // Each hour is 30 degrees (360/12).
        // The hour hand also moves 0.5 degrees per minute (30/60).
        // Use hour % 12 to handle the case where hour is 12.
        double hour_angle = (hour % 12) * 30.0 + minutes * 0.5;
        
        double diff = abs(hour_angle - minutes_angle);
        
        // Return the smaller of the two possible angles
        return min(diff, 360.0 - diff);
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    int hour = 12;
    int minutes = 30;

    double result = sol.angleClock(hour, minutes);

    cout << "The smaller angle at " << hour << ":" << minutes << " is: " << result << " degrees." << endl; // Output: 165

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(1)$. The calculation involves a fixed number of arithmetic operations.
  - **Space:** $O(1)$. No extra space is used that scales with the input.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o angle_clock main.cpp`
  - **Run:** `./angle_clock`

-----

## Notes

  - The calculation for the minute hand's angle is `minutes * 6` because a full 360° circle is divided into 60 minutes, so each minute mark is 6° apart.
  - The calculation for the hour hand's angle is `(hour % 12) * 30 + minutes * 0.5`.
      - The `* 30` part is because the circle is divided into 12 hours, making each hour mark 30° apart.
      - The `+ minutes * 0.5` part accounts for the hour hand's movement between hour marks, which is proportional to the minutes passed.
  - The final step, `min(diff, 360.0 - diff)`, is crucial to ensure you return the smaller (interior) angle, not the larger reflex angle.
