#include <iostream>
using namespace std;

void PrintArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

void SelectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[minIndex])
                minIndex = j;
        }

        if (minIndex != i)
            cout << "\nSwapping " << A[i] << " and " << A[minIndex] << " : ";
            swap(A[i], A[minIndex]);
            PrintArray(A, n);

    }
}

int main() {
    int n;
    cout << "\nInput array size : ";
    cin >> n;

    int A[n];
    cout << "\nInput array : ";
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    SelectionSort(A, n);

    cout << "Sorted array : ";
    PrintArray(A, n);

    return 0;
}
