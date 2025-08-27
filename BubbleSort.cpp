#include <iostream>
using namespace std;

void PrintArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

void BubbleSort(int A[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                cout << "\nSwapping elements " << A[j] << " and " << A[j+1] << " : ";
                swap(A[j], A[j + 1]);
                swapped = true;
                PrintArray(A, n);
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

    int A[n];
    cout << "\nInput array : ";
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    BubbleSort(A, n);

    cout << "\nSorted array: ";
    PrintArray(A, n);

    return 0;
}
