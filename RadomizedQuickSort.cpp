#include <iostream>
#include <cstdlib>  // for rand()
#include <ctime>    // for seeding rand()
using namespace std;

void PrintArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

int Partition(int A[], int low, int high) {
    int pivot = A[high];  
    int i = low - 1;        

    for (int j = low; j < high; j++) {
        if (A[j] < pivot) {
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[high]); 
    return (i + 1);
}

int RandomizedPartition(int A[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1); 
    swap(A[randomIndex], A[high]); 
    return Partition(A, low, high);
}

void RandomizedQuickSort(int A[], int low, int high) {
    if (low < high) {
        int pi = RandomizedPartition(A, low, high);

        RandomizedQuickSort(A, low, pi - 1);
        RandomizedQuickSort(A, pi + 1, high);
    }
}

int main() {
    srand(time(0)); 

    int n;
    cout << "\nInput array size : ";
    cin >> n;

    int A[n];
    cout << "\nInput array : ";
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    RandomizedQuickSort(A, 0, n - 1);

    cout << "Sorted array : ";
    PrintArray(A, n);

    return 0;
}
