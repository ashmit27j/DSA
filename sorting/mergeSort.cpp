#include <iostream>
#include <string>

using namespace std;

void merge(int **arr, int left, int mid, int right){
    int leftSize, rightSize;
    leftSize = mid - left + 1;
    rightSize = right - mid;
    int leftArray(leftSize), rightArray(rightSize);

    for (int i = 0; i < leftSize; i++){
        leftArray[i] = arr[left + i];
    }
    
}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2; //prevents overflow
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(&arr, left, mid, right);
    }
}
void printArray(int *arr){

    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        cout << arr[i];
    }
}
void inputArray(int *arr){
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        cin >> arr[i];
    }
}
int main() {
    // Your code here
    int size;
    cout << "Please enter the size of the array: " << endl;
    cin >> size;
    int arr[size];

    inputArray(arr);
    printArray(arr);
    return 0;
}