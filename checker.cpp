#include <iostream>
#include <unistd.h>
#include <cassert>

using namespace std;

struct Alert {
    string message;
    int delayInSeconds;
};

void showAlertWithDelay(const Alert &alert) {
    cout << alert.message << endl;
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        sleep(alert.delayInSeconds);
        cout << "\r *" << flush;
        sleep(alert.delayInSeconds);
    }
}

bool isOutOfRange(float value, float lowerLimit, float upperLimit) {
    return value < lowerLimit || value > upperLimit;
}

bool isTemperatureCritical(float temperature) {
    return isOutOfRange(temperature, 95, 102);
}

bool isPulseRateOutOfRange(float pulseRate) {
    return isOutOfRange(pulseRate, 60, 100);
}

bool isSpo2OutOfRange(float spo2) {
    return isOutOfRange(spo2, 0, 90);
}

void checkAndAlert(const Alert &alert, bool condition) {
    if (condition) {
        showAlertWithDelay(alert);
    }
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
    Alert temperatureAlert = {"Temperature critical!", 1};
    Alert pulseRateAlert = {"Pulse Rate is out of range!", 1};
    Alert spo2Alert = {"Oxygen Saturation out of range!", 1};

    checkAndAlert(temperatureAlert, isTemperatureCritical(temperature));
    checkAndAlert(pulseRateAlert, isPulseRateOutOfRange(pulseRate));
    checkAndAlert(spo2Alert, isSpo2OutOfRange(spo2));

    return !temperatureAlert.message.empty() ||
           !pulseRateAlert.message.empty() ||
           !spo2Alert.message.empty();
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