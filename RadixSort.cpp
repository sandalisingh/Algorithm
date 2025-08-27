#include <iostream>
using namespace std;

void PrintArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

int GetMax(int A[], int n) {
    int maxValue = A[0];
    for (int i = 1; i < n; i++)
        if (A[i] > maxValue)
            maxValue = A[i];
    return maxValue;
}

void CountingSort(int A[], int n, int exp) {
    int output[n]; 
    int count[10] = {0};

    // Count occurrences of digits
    for (int i = 0; i < n; i++)
        count[(A[i] / exp) % 10]++;

    // Change count[i] so it contains actual position
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array (stable sort)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (A[i] / exp) % 10;
        output[count[digit] - 1] = A[i];
        count[digit]--;
    }

    // Copy output[] back to A[]
    for (int i = 0; i < n; i++)
        A[i] = output[i];
}

void RadixSort(int A[], int n) {
    int m = GetMax(A, n); 

    for (int exp = 1; m / exp > 0; exp *= 10)
        CountingSort(A, n, exp);
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

    RadixSort(A, n);

    cout << "Sorted array: ";
    PrintArray(A, n);

    return 0;
}
