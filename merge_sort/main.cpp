#include <iostream>
#include <vector>

using namespace std;

// 合并
void merge(vector<int> &src, vector<int> &dist, int p, int q, int r) {
    int i = p;
    int j = q + 1;
    int k = i;
    for (; i <= q || j <= r;) {
        if (i > q) {
            dist[k++] = src[j++];
            continue;
        }
        if (j > r) {
            dist[k++] = src[i++];
            continue;
        }
        if (src[i] < src[j]) {
            dist[k++] = src[i++];
        } else {
            dist[k++] = src[j++];
        }
    }
    for (int ii = p; ii <= r; ii++) {
        src[ii] = dist[ii];
    }

}

void mergeSortR(vector<int> &src, vector<int> &dist, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSortR(src, dist, low, mid);
        mergeSortR(src, dist, mid + 1, high);
        merge(src, dist, low, mid, high);
    }
}


void mergeSort(vector<int> &arr, int low, int high) {
    vector<int> copy(arr.size());
    if (low < high) {
        mergeSortR(arr, copy, low, high);
    }
    arr = copy;
}


int main() {
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(8);
    arr.push_back(9);
    arr.push_back(5);
    arr.push_back(4);
    mergeSort(arr, 0, arr.size() - 1);
    for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
        cout << *(it) << endl;
    }
    return 0;
}

