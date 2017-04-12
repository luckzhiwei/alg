//
// Created by 廖志伟 on 2017/4/12.
//

#include "Pipeline.h"
Pipeline::Pipeline(int len){
    this->mPipeline1.resize(len);
    this->mPipelien2.resize(len);
}
void Pipeline::setInfo(int id, map<int, int> &map) {
     vector<Node> pipline=id==1?this->mPipeline1:this->mPipelien2;
     for(map<int,int>::iterator iterator=map.begin();iterator!=map.end();iterator++){
           Node node(iterator->first,iterator->second);
           pipline.push_back(node);
     }
}

void Pipeline::findPath() {
    
}