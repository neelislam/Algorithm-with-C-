//descending order
#include<iostream>
using namespace std;

void selectionsortAscending(int arr[], int n ){
    for( int i = 0; i < n-1; i++ ){
       int min_index = i;
        for(int j = i+1; j < n; j++){
            if (arr[j] < arr[min_index]){
               min_index = j;
            }
        }
       swap(arr[min_index], arr[i]);
    }
}
void selectionsortDescending(int arr[], int n ){
    for( int i = 0; i < n-1; i++ ){
       int min_index = i;
        for(int j = i+1; j < n; j++){
            if (arr[j] > arr[min_index]){
               min_index = j;
            }
        }
       swap(arr[min_index], arr[i]);
    }
}

int main(){
    int arr[] = {8, -9, 0, -10, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionsortAscending(arr, n);
    cout <<"Ascending Order: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    selectionsortDescending(arr, n);
    cout <<"Descending Order: ";
    for(int i = 0; i < n; i++){
         cout << arr[i] << " ";
    }
    return 0;
}






