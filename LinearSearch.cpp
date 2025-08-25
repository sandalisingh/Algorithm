#include <iostream>
using namespace std;

int LinearSearch(int arr[], int n, int target) {
    for(int i=0; i<n; i++) {
        if(arr[i] == target) {
            return i;
        }
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
