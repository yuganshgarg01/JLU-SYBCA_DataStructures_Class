//Dynamic Array using New Keyword
 #include <iostream>
using namespace std;
    int main() {
        int size;
        cout << "Enter array size: ";
        cin >> size;

        int* dynamicArray = new int[size]; // Dynamically allocate an array

        // Use the dynamic array
        for (int i = 0; i < size; ++i) {
            dynamicArray[i] = i * 10;
            cout << dynamicArray[i] << " ";
        }
        cout << endl;

        delete[] dynamicArray; // Deallocate the memory
        dynamicArray = nullptr; // Set pointer to nullptr after deletion

        return 0 ;
    }
