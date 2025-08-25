#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

void PrintArray(float arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void PrintArray(vector<float> arr, int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void InsertionSort(vector<float>& bucket) {
    cout << "Applying insertion sort in array : ";
    PrintArray(bucket, bucket.size());

    for (int i = 1; i < bucket.size(); i++) {
        float key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;

        cout << "Putting element " << key << " in right place : ";
        PrintArray(bucket, bucket.size());
    }
}

void BucketSort(float arr[], int n) {
    vector<vector<float>> buckets(n);

    for (int i = 0; i < n; i++) {
        int index = n * arr[i]; 
        buckets[index].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << "\nInsertion sort on Bucket-"<<i<<"\n";
        InsertionSort(buckets[i]);
        PrintArray(buckets[i], buckets[i].size());
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[k++] = buckets[i][j];
        }
    }
}

int main() {
    int n;
    cout << "\nInput array size : ";
    cin >> n;

    float arr[n];
    cout << "\nInput array : ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    BucketSort(arr, n);

    cout << "\nSorted array: ";
    PrintArray(arr, n);

    return 0;
}
