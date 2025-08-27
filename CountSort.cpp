#include <iostream>
#include <vector>
using namespace std;

void PrintArray(vector<int> A, int n) {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

void PrintArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

void CountSort(int A[], int n) {
    int maxVal = A[0];
    for (int i = 1; i < n; i++)
        if (A[i] > maxVal)
            maxVal = A[i];

    vector<int> count(maxVal + 1, 0);

    for (int i = 0; i < n; i++) 
        count[A[i]]++;
    cout << "\nFrequency array : \n";
    for (int i = 0; i <= maxVal; i++) {
        cout << i << " ";
    }
    cout << endl;
    PrintArray(count, maxVal+1);

    int j = 0;
    for (int i = 0; i <= maxVal; i++) {
        while(count[i]>0) {
            A[j++] = i;
            count[i]--;
        }
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

    CountSort(A, n);

    cout << "Sorted array : ";
    PrintArray(A, n);

    return 0;
}
