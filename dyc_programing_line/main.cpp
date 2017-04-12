#include <iostream>
#include "Pipeline.h"

int main() {

    Pipeline pipeline(6);
    map<int,int> map1;
    map1.insert(pair<int,int>(7,2));
    map1.insert(pair<int,int>(9,3));
    map1.insert(pair<int,int>(3,1));
    map1.insert(pair<int,int>(4,3));
    map1.insert(pair<int,int>(8,4));
    map1.insert(pair<int,int>(4,3));
    map<int,int> map2;
    map2.insert(pair<int,int>(8,2));
    map2.insert(pair<int,int>(5,1));
    map2.insert(pair<int,int>(6,2));
    map2.insert(pair<int,int>(4,2));
    map2.insert(pair<int,int>(5,1));
    map2.insert(pair<int,int>(7,2));
    pipeline.setInfo(1,map1);
    pipeline.setInfo(2,map2);
    return 0;
}