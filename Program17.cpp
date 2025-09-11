#include <iostream>
using namespace std;

void insertElement(int arr[], int &n, int element, int position) {
    if (position < 0 || position > n) {
        cout << "Invalid position!" << endl;
        return;
    }

    // Shift elements to the right
    for (int i = n; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    n++; // increase array size
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50}; // initial array
    int n = 5; // current size of array

    cout << "Original array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    int element = 25, position = 2; // insert at index 2
    insertElement(arr, n, element, position);

    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
