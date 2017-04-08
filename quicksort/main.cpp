//
//  main.cpp
//  alg
//
//  Created by 廖志伟 on 2017/4/8.
//  Copyright © 2017年 廖志伟. All rights reserved.
//

#include <iostream>
using namespace std;

void swap(int &num0,int &num1){
    int tmp=num0;
    num0=num1;
    num1=tmp;
}


int parition(int *arr,int p,int r){
    int x=arr[r];
    int i=p-1;
    for(int j=p;j<r;j++){
        if(arr[j]<x){
            i++;  // i 在移动过程中代表了当前比x小的数字的坐标，循环完成i+1代表最终x的位置
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}


void quickSort(int * arr,int p,int r){
    int q=parition(arr,p,r);
    quickSort(arr, p, q-1);
    quickSort(arr,q+1 ,r);
}


int main(int argc, const char * argv[]) {
    int arr[10]={45,23,43,23,49,66,1,3,4,10};
    quickSort(arr,0,10);
    for(int i=0;i<10;i++){
        cout << arr[i]<<endl;
    }
    return 0;
}


