#include <iostream>
using namespace std;

void PrintArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

void Merge(int A[], int left, int mid, int right) {
    int n1 = mid - left + 1; 
    int n2 = right - mid;   

    int L1[n1], L2[n2];

    for (int i = 0; i < n1; i++)
        L1[i] = A[left + i];
    for (int j = 0; j < n2; j++)
        L2[j] = A[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L1[i] <= L2[j]) {
            A[k++] = L1[i++];
        } else {
            A[k++] = L2[j++];
        }
    }

    while (i < n1) {
        A[k++] = L1[i++];
    }
    while (j < n2) {
        A[k++] = L2[j++];
    }
}

void MergeSort(int A[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        MergeSort(A, left, mid);
        MergeSort(A, mid + 1, right);
        Merge(A, left, mid, right);
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

    MergeSort(A, 0, n - 1);

    cout << "\nSorted array : ";
    PrintArray(A, n);

    return 0;
}
