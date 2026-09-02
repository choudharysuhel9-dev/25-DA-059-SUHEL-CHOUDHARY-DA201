//EXPERIMENT 2
// NAME = SUHEL CHOUDHARY
//ROLL NO. = 25/DA/059
#include <iostream>
using namespace std;

int partition(int arr[], int si, int ei) {
    int pivot = arr[si];
    int count = 0;
    for (int i = si + 1; i <= ei; i++) {
        if (arr[i] <= pivot)
            count++;
    } 
    int pivotidx = si + count;
    swap(arr[si], arr[pivotidx]);

    int i = si;
    int j = ei;

    
    while (i < pivotidx && j > pivotidx) {

        if (arr[i] <= pivot) {
            i++;
        }
        else if (arr[j] > pivot) {
            j--;
        }
        else {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return pivotidx;
}

void quicksort(int arr[], int si, int ei) {

    if (si >= ei)
        return;

    int pivotidx = partition(arr, si, ei);

    quicksort(arr, si, pivotidx - 1);
    quicksort(arr, pivotidx + 1, ei);
}

int main() {

    int arr[] = {50, 1, 21, 3, 8, 45, 2, 69};

    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}