//AIM:1 A.	Write a program to accept ‘n’ numbers into an array and then calculate the sum of numbers present 
//in odd positions and even positions respectively.//roll no 102
#include <stdio.h>

int main() {
    int n, i, sumOdd = 0, sumEven = 0;

    // Accept the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Accept the elements of the array
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate the sum of numbers at odd and even positions
    for (i = 0; i < n; i++) {
        if ((i + 1) % 2 == 0) { // Even position (1-based index)
            sumEven += arr[i];
        } else { // Odd position (1-based index)
            sumOdd += arr[i];
        }
    }

    // Print the results
    printf("Sum of numbers at odd positions: %d\n", sumOdd);
    printf("Sum of numbers at even positions: %d\n", sumEven);

    return 0;
}
