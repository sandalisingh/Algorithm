#include <iostream>
using namespace std;

void PrintArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

void PrintArray(int A[], int l, int h) {
    for (int i = l; i <= h; i++)
        cout << A[i] << " ";
    cout << endl;
}

int Partition(int A[], int low, int high) {
    int pivot = A[high];  
    int i = low - 1;   
    
    cout << "\n -> Pivot element = " << pivot << endl;

    for (int j = low; j < high; j++) {
        if (A[j] < pivot) {   
            i++;
            cout << "\nSwapping " << A[i] << " and " << A[j] << " : ";
            swap(A[i], A[j]);
            PrintArray(A, low, high);
        }
    }

    swap(A[i + 1], A[high]);
    return (i + 1);
}

void QuickSort(int A[], int low, int high) {
    if (low < high) {
        int pi = Partition(A, low, high); 

        QuickSort(A, low, pi - 1);
        QuickSort(A, pi + 1, high);
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

    QuickSort(A, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
