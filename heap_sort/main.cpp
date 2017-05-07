#include <iostream>
#include <vector>

using namespace std;

void swap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

void heapify(vector<int> &arr, int i, int size) {
    int largetestIndex = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= size && arr[left - 1] > arr[i - 1]) {
        largetestIndex = left;
    }
    if (right <= size && arr[right - 1] > arr[largetestIndex - 1]) {
        largetestIndex = right;
    }
    if (largetestIndex != i) {
        swap(arr[i - 1], arr[largetestIndex - 1]);
        heapify(arr, largetestIndex, size);
    }
}


void buildHeap(vector<int> &arr) {
    int size = arr.size();
    for (int i = size / 2; i >= 1; i--) {
        heapify(arr, i, size);
    }
}

void heapSort(vector<int> &arr) {
    buildHeap(arr);
    for (int i = arr.size(); i >= 2; i--) {
        swap(arr[i - 1], arr[0]);
        heapify(arr, 1, i - 1);
    }
}

int main() {
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(16);
    arr.push_back(9);
    arr.push_back(10);
    arr.push_back(14);
    arr.push_back(8);
    arr.push_back(7);
    heapSort(arr);
    return 0;
}