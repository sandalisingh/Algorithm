#include <iostream>
using namespace std;

int LinearSearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; 

        if (arr[mid] == target)
            return mid; 
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1; 
    }
    return -1;
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

    int element;
    cout << "\nInput element to search : ";
    cin >> element;

    int ans = LinearSearch(A, n, element);

    if (ans != -1)
        cout << "\nElement found at index " << ans << endl;
    else
        cout << "\nElement not found" << endl;

    return 0;
}
