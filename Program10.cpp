//Dynamic Array using Malloc()
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int size;
    cout << "Enter array size: ";
    cin >> size;

    int* arr = (int*) malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        arr[i] = i * 2;
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    free(arr); // free memory

    return 0;
}
