#include <iostream>
using namespace std;

int LinearSearch(int A[], int n, int element) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; 

        if (A[mid] == element)
            return mid; 
        else if (A[mid] < element)
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
