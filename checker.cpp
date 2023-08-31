#include <iostream>
#include <unistd.h>
#include <cassert>
#include <functional>
#include <vector>

using namespace std;

struct VitalsCheck {
    string alertMessage;
    function<bool(float)> checkFunction;
};

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
    vector<VitalsCheck> checks = {
        {"Temperature critical!", isTemperatureOutOfRange},
        {"Pulse Rate is out of range!", isPulseRateOutOfRange},
        {"Oxygen Saturation out of range!", isSpo2OutOfRange}
    };

    for (const auto &check : checks) {
        if (check.checkFunction(temperature) ||
            check.checkFunction(pulseRate) ||
            check.checkFunction(spo2)) {
            displayAlert(check.alertMessage);
            return 0;
        }
    }

    return 1;
}

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