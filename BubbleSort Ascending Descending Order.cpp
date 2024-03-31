#include <iostream> // Includes the iostream library to allow the program to perform input and output operations.

using namespace std; // Allows the use of elements in the standard namespace without the prefix 'std::'.

// Defines a function to sort an array using the selection sort algorithm.
void selectionsortAscending(int arr[], int n) {
    // Iterates over each element of the array except the last one.
    for (int i = 0; i < n - 1; i++) {
        int min_index = i; // Initializes the minimum index to the current index 'i'.
        // Iterates over the unsorted part of the array to find the minimum element.
        for (int j = i + 1; j < n; j++) {
            // Compares the current element with the current minimum.
            if (arr[j] < arr[min_index]) {
                min_index = j; // Updates the minimum index if a smaller element is found.
            }
        }
        swap(arr[min_index], arr[i]); // Swaps the minimum element found with the first element of the unsorted part.
    }
}
void selectionsortDescending(int arr[], int n) {
    // Iterates over each element of the array except the last one.
    for (int i = 0; i < n - 1; i++) {
        int max_index = i; // Initializes the minimum index to the current index 'i'.
        // Iterates over the unsorted part of the array to find the minimum element.
        for (int j = i + 1; j < n; j++) {
            // Compares the current element with the current minimum.
            if (arr[j] > arr[max_index]) {
                max_index = j; // Updates the minimum index if a smaller element is found.
            }
        }
        swap(arr[max_index], arr[i]); // Swaps the minimum element found with the first element of the unsorted part.
    }
}  


// The main function where the program execution begins.
int main() {
    // Descending order
    int arr1[] = {8, -9, 0, -10, 3}; // Initializes an array with given elements.
    int n1 = sizeof(arr1) / sizeof(arr1[0]); // Calculates the number of elements in the array.
    selectionsortAscending(arr1, n1); // Calls the selectionsort function to sort the array.
    cout << "Ascending order: "; // Prints a message to indicate the order of sorting.
    // Iterates over the sorted array and prints each element.
    for (int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl; // Prints a newline character.

    // Ascending order
    int arr2[] = {8, -9, 0, -10, 3}; // Initializes another array with the same elements.
    int n2 = sizeof(arr2) / sizeof(arr2[0]); // Calculates the number of elements in this array.
    selectionsortDescending(arr2, n2); // Calls the selectionsort function to sort this array.
    cout << "Descending order: "; // Prints a message to indicate the order of sorting.
    // Iterates over the sorted array and prints each element.
    for (int i = 0; i < n2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl; // Prints a newline character.

    return 0; // Returns 0 to indicate successful completion of the program.
}