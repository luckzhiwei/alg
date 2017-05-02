#include <iostream>
#include <vector>

using namespace std;

// 合并
void merge(vector<int> &arr, int p, int q, int r) {
    vector<int> l;
    vector<int> h;
    for (int i = p; i <= q; i++) {
        l.push_back(arr[i]);
    }
    for (int i = q + 1; i <= r; i++) {
        h.push_back(arr[i]);
    }
    int i = 0;
    int j = 0;
    for (int k = p; k <= r; k++) {
        if (i == l.size()) {
            arr[k] = h[j];
            j++;
            continue;
        }
        if (j == h.size()) {
            arr[k] = l[i];
            i++;
            continue;
        }

        if (l[i] <= h[j]) {
            arr[k] = l[i];
            i++;
        } else {
            arr[k] = h[j];
            j++;
        }
    }

}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(8);
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(7);
    mergeSort(arr, 0, arr.size() - 1);
    for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
        cout << *(it) << endl;
    }
    return 0;
}

