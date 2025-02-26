#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool compare(int &a, int &b){
    return a > b;
}

void swap(int &a, int &b){
    a = a + b;
    b = a - b;
    a = a - b;
}

void userInput(int *arr, int size){
    for (int i = 0; i < size; i ++){
        cin >> arr[i];
    }
}

void printArray(int *arr, int size){
    for (int i = 0; i < size; i ++){
        cout << arr[i];
    }
}

void bubbleSort(int *arr, int size){
    for (int i = 0; i < size; i ++ ){
        for (int j = 0; j < size - i - 1; j ++ ){
            if(compare(arr[j], arr[j + 1])){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int size;
    cout << "Enter size of array: " << endl;
    cin >> size;
    int arr[size];
    userInput(arr, size);
    bubbleSort(arr, size);
    printArray(arr, size);
    return 0;
}