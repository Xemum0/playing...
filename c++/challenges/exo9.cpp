//remove duplicate in array
#include <iostream>
using namespace std;

void remove_duplicates(int arr[], int& size) {
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (i == 0 || arr[i] != arr[i-1]) {
            arr[j] = arr[i];
            j++;
        }
    }
    size = j;
}

int main() {
    int arr[] = {1, 1, 2, 3, 3, 3, 4, 5, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    remove_duplicates(arr, size);
    cout << "\nArray after removing duplicates: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
