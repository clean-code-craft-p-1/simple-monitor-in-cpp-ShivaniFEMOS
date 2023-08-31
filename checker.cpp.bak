#include <iostream>
#include <unistd.h>
#include <cassert>

using namespace std;

// Separate pure functions from I/O

bool isTemperatureOutOfRange(float temperature) {
    return temperature > 102 || temperature < 95;
}

bool isPulseRateOutOfRange(float pulseRate) {
    return pulseRate < 60 || pulseRate > 100;
}

bool isSpo2OutOfRange(float spo2) {
    return spo2 < 90;
}

void displayAlert(const string &message) {
    cout << message << endl;
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        sleep(1);
        cout << "\r *" << flush;
        sleep(1);
    }
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
    if (isTemperatureOutOfRange(temperature)) {
        displayAlert("Temperature critical!");
        return 0;
    } else if (isPulseRateOutOfRange(pulseRate)) {
        displayAlert("Pulse Rate is out of range!");
        return 0;
    } else if (isSpo2OutOfRange(spo2)) {
        displayAlert("Oxygen Saturation out of range!");
        return 0;
    }
    return 1;
}

// Complete the tests - cover all conditions

void testVitals() {
    assert(!vitalsOk(99, 102, 70));
    assert(vitalsOk(98.1, 70, 98));
    assert(!vitalsOk(95, 59, 95));
    assert(!vitalsOk(101, 100, 89));
    assert(!vitalsOk(96, 105, 96));
    assert(!vitalsOk(98, 80, 85));
    assert(vitalsOk(98.6, 75, 92));
}

int main() {
    testVitals();
    cout << "All tests passed.\n";
}