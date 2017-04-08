//
// Created by lzw on 17-4-8.
//

#include <iostream>

using namespace std;

void swap(int &num0, int &num1) {
    int tmp = num0;
    num0 = num1;
    num1 = tmp;
}


int parition(int arr[], int p, int r) {
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (arr[j] < x) {
            i++;  // i 在移动过程中代表了当前比x小的数字的坐标，循环完成i+1代表最终x的位置
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}


void quickSort(int arr[], int p, int r) {
    if (p < r) { // 数组中只有一个元素的时候就会结束
        int q = parition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}


int main(int argc, const char *argv[]) {
    int arr[10] = {45, 23, 43, 23, 49, 66, 1, 3, 4, 10};
    quickSort(arr, 0, 9);
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}
