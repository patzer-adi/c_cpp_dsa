#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int arr[10];
    double sum = 0, mean, sd = 0;

    cout << "Enter 10 numbers:\n";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    mean = sum / 10.0;

    for (int i = 0; i < 10; i++) {
        sd += pow(arr[i] - mean, 2);
    }

    sd = sqrt(sd / 10.0);

    cout << "Standard Deviation = " << sd;
    return 0;
}
