#include <iostream>
using namespace std;

int* incrementArr(int* arr, int size) {
    int* tempArr = new int[size + 1];

    for (int i = 0; i < size; i++) {
        tempArr[i] = arr[i];
    }
    tempArr[size] = 0;

    return tempArr;
}

int main() {
    int size = 5;
    int* num1 = new int[size]{1, 2, 3, 4, 5};

    cout << "Original array size: " << size << endl;

    int* newNum1 = incrementArr(num1, size);
    delete[] num1; // Delete the old array
    num1 = newNum1;
    size++; // Increment size to reflect new array size

    cout << "New array size: " << size << endl;
    cout << "Incremented array: ";
    for (int i = 0; i < size; i++) {
        cout << num1[i] << " ";
    }
    cout << endl;

    delete[] num1; // Delete the new array

    return 0;
}
