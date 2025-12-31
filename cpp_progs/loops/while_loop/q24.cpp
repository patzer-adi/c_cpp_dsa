#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int a[10], i = 0;
    float sum = 0, mean, sd = 0;
    while (i < 10) {
        cin >> a[i];
        sum += a[i];
        i++;
    }
    mean = sum / 10;
    i = 0;
    while (i < 10) {
        sd += (a[i] - mean) * (a[i] - mean);
        i++;
    }
    cout << sqrt(sd / 10);
}
