
#include <stdio.h>

//Day 5

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate the middle index
        
        // Check if the target is found at the middle
        if (arr[mid] == target) {
            return mid;
        }
        
        // If the target is in the left half, narrow the search to the left subarray
        if (arr[mid] > target) {
            right = mid - 1;
        }
        // If the target is in the right half, narrow the search to the right subarray
        else {
            left = mid + 1;
        }
    }
    
    // Return -1 if the target is not found in the array
    return -1;
}

int main() {
    //Array
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
    
    //Lenght array
    int n = sizeof(arr) / sizeof(arr[0]);
    
    //Target read from console
    int target;

    printf("Input target:\n");
    scanf("%d", &target);
    
    //Call the function
    int index = binarySearch(arr, 0, n - 1, target);
    
    //Print the result
    if (index != -1) {
        printf("Element found at index: %d\n", index);
    } else {
        printf("Element not found in the array.\n");
    }
    
    return 0;
}
