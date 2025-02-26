#include <iostream>
#include <string>

using namespace std;

void swap(int &a, int &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main() {
    int num1, num2;
    cout << "Please enter the two numbers:" << endl;
    cin >> num1;
    cin >> num2;
    swap(num1, num2);
    cout << "swapped num1: " << num1 << endl;;
    cout << "swapped num2: " << num2 << endl;
    return 0;
}