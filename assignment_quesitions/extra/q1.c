#include <stdio.h>

int main() {
    int n;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Elements that occur more than once: ");
    
    for(int i = 0; i < n; i++) {
        int count = 1;
        if(arr[i] != -1) 
        {  
            for(int j = i + 1; j < n; j++) {
                if(arr[i] == arr[j]) {
                    count++;
                    arr[j] = -1; 
                }
            }
            if(count > 1) {
                printf("%d ", arr[i]);
            }
        }
    }

    printf("\n");
    return 0;
}
