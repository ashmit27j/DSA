#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};

    //adds an element to top
    numbers.push_back(35);
    cout << "Vector at position 5: " << numbers[5] << endl;
    
    cout << "Size: " << numbers.size() << endl;

    //removes last element
    numbers.pop_back();
    numbers.pop_back();

    for (int i = 0; i < numbers.size(); i++){
        cout << numbers[i];
    }

    cout << endl;

    numbers.clear();
    cout << "capacity: " << numbers.capacity() << endl;
    numbers.push_back(10);
    numbers.shrink_to_fit();  // Requests to reduce the capacity to fit the size
    cout << "capacity: " << numbers.capacity() << endl;

    return 0;
}