#include <iostream>
using namespace std;

void addMultiply(int a, int b, int &sum, int &product) {
    sum = a + b;
    product = a * b;
}

int main() {
    int sum, product;
    addMultiply(5, 6, sum, product);

    cout << "Sum = " << sum << endl;
    cout << "Product = " << product;

    return 0;
}
