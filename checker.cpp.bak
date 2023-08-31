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
    // Temperature critical, Pulse Rate OK, Spo2 OK
    assert(!vitalsOk(99, 70, 98));

    // Temperature OK, Pulse Rate out of range, Spo2 OK
    assert(!vitalsOk(98.1, 40, 98));

    // Temperature OK, Pulse Rate OK, Spo2 out of range
    assert(!vitalsOk(98.6, 75, 85));

    // All vitals OK
    assert(vitalsOk(98.6, 75, 92));

    // Temperature critical, Pulse Rate out of range, Spo2 out of range
    assert(!vitalsOk(104, 105, 80));

    // Temperature critical, Pulse Rate OK, Spo2 out of range
    assert(!vitalsOk(100, 75, 85));

    // Temperature OK, Pulse Rate critical, Spo2 out of range
    assert(!vitalsOk(98.6, 105, 85));
}

int main() {
    testVitals();
    cout << "All tests passed.\n";
}