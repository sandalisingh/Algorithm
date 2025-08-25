#include <iostream>
#include <vector>
using namespace std;

void PrintArray(vector<int> arr, int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void CountSort(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    vector<int> count(maxVal + 1, 0);

    for (int i = 0; i < n; i++) // frequency
        count[arr[i]]++;
    cout << "\nFrequency array : ";
    PrintArray(count, n);

    vector<int> output(n);
    int j = 0;
    for (int i = 0; i <= maxVal; i--) {
        while(count[i]>0) {
            arr[j++] = i;
            count[i]--;
        }
    }
    cout << "\nRebuild array : ";
    PrintArray(output, n);
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    CountSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
