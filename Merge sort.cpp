#include<iostream> // Include the IO stream header for input and output operations
using namespace std; // Use the standard namespace

// Global arrays and variable
int a[10] = { 10, 14, 33, 35, 42, 44 , 19, 26, 27, 31}; // Input array to be sorted
int b[10]; // Auxiliary array used for merging
int n=10; // Number of elements in the array

// Function to merge two subarrays of a[]
void mergee(int low, int mid, int high){
    int i, l1, l2;
    // Merge the two subarrays into b[]
    for(l1=low, l2=mid+1,i=low; l1<=mid && l2<=high; i++){
        if(a[l1]<a[l2]){
            b[i]=a[l1++];
        }
        else{
            b[i]=a[l2++];
        }
    }
    // Copy any remaining elements of the first subarray
    while(l1<=mid){
        b[i++]= a[l1++];
    }
    // Copy any remaining elements of the second subarray
    while(l2<=high){
        b[i++]= a[l2++];
    }
    // Copy the merged elements back into the original array a[]
    for(i=low; i<=high;i++){
        a[i]=b[i];
    }
}

// Function to perform merge sort on array a[]
void mergesort(int low, int high){
    int mid;
    if(low<high){
        mid=(low+high)/2; // Find the midpoint
        mergesort(low, mid); // Sort the first half
        mergesort(mid+1, high); // Sort the second half
        mergee(low, mid, high); // Merge the two halves
    }
    else{
        return; // Base case for recursion (single element)
    }
}

// Main function
int main(){
    mergesort(0,n-1); // Call mergesort on the entire array

    // Print the sorted array
    printf("\nList after sorting\n");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    return 0; // Return 0 to indicate successful completion
}
