#include <iostream>
using namespace std;

void PrintArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

void InsertionSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int key = A[i];    
        int j = i - 1;

        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key; 

        cout << "Putting element " << key << " in right place : ";
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

    InsertionSort(A, n);

    cout << "Sorted array: ";
    PrintArray(A, n);

    return 0;
}
