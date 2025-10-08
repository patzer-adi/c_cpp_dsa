#include <stdio.h>

// Function to find the second largest element in the array
int getSecondLargest(int arr[], int n) {
    
    int largest = -1, secondLargest = -1;

    // Finding the largest element
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest)
            largest = arr[i];
    }

    // Finding the second largest element
    for (int i = 0; i < n; i++) {
        
        // Update second largest if the current element is greater
        // than second largest and not equal to the largest
        if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1}; 
	int n = sizeof(arr)/sizeof(arr[0]);
  
    printf("%d\n", getSecondLargest(arr, n)); 
    return 0; 
}