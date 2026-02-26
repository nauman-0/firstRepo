#include <iostream>
#include <string>
using namespace std;

template<typename T>
void printArr(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            T temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {

    int arr[] = { 3,1,54,24,1,67,54,69,41,21,5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArr(arr, size);

    selectionSort(arr, size);

    cout << "Sorted Array: ";
    printArr(arr, size);

    string stringArray[] = { "apple", "orange", "banana", "grape" };
    int stringSize = sizeof(stringArray) / sizeof(stringArray[0]);

    cout << "\nOriginal string array: ";
    printArr(stringArray, stringSize);

    selectionSort(stringArray, stringSize);

    cout << "Sorted string array: ";
    printArr(stringArray, stringSize);

    return 0;
}