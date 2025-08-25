#include <iostream>
using namespace std;

void PrintArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void BubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                cout << "\nSwapping elements " << arr[j] << " and " << arr[j+1] << " : ";
                swap(arr[j], arr[j + 1]);
                swapped = true;
                PrintArray(arr, n);
            }
        }

        if (!swapped)
            break;
    }
}

int main() {
    int n;
    cout << "\nInput array size : ";
    cin >> n;

    int arr[n];
    cout << "\nInput array : ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    BubbleSort(arr, n);

    cout << "\nSorted array: ";
    PrintArray(arr, n);

    return 0;
}
