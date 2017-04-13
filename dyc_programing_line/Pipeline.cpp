//
// Created by 廖志伟 on 2017/4/12.
//

#include "Pipeline.h"

Pipeline::Pipeline(int len, int startTime1, int startIime2) : mLen(len), mStartTime1(startTime1),
                                                              mStartTime2(startIime2) {

}

void Pipeline::setInfo(int id, const vector<pair<int, int>> &infos) {
    vector<Node> &pipline = id == 1 ? this->mPipeline1 : this->mPipelien2;
    for (int i = 0; i < infos.size(); i++) {
        pipline.push_back(Node(infos[i].first, infos[i].second));
    }
}

void Pipeline::findPath() {
    for (int i = 0; i < this->mLen; i++) {
        if (i == 0) {
            this->mCostPipeline1.push_back(this->mStartTime1 + this->mPipeline1[i].assemblyTime);
            this->mCostPipeline2.push_back(this->mStartTime2 + this->mPipelien2[i].assemblyTime);
            continue;
        }
        int costPipline1_1 = this->mCostPipeline1[i - 1] + this->mPipeline1[i].assemblyTime;
        int costPipline1_2 =
                this->mCostPipeline2[i - 1] + this->mPipelien2[i - 1].toNextNodeTime + this->mPipeline1[i].assemblyTime;

        if (costPipline1_1 < costPipline1_2) {
            this->mCostPipeline1.push_back(costPipline1_1);
            this->path1.push_back(1);
        } else {
            this->mCostPipeline1.push_back(costPipline1_2);
            this->path1.push_back(2);
        }

        int costPipline2_2 = this->mCostPipeline2[i - 1] + this->mPipelien2[i].assemblyTime;
        int costPipline2_1 =
                this->mCostPipeline1[i - 1] + this->mPipeline1[i - 1].toNextNodeTime + this->mPipelien2[i].assemblyTime;

        if (costPipline2_2 < costPipline2_1) {
            this->mCostPipeline2.push_back(costPipline2_2);
            this->path2.push_back(2);
        } else {
            this->mCostPipeline2.push_back(costPipline2_1);
            this->path2.push_back(1);
        }
    }


}

void Pipeline::outputLine() {
    int choose = -1;
    stack<int> pathOutput;
    if (this->mCostPipeline1[this->mLen - 1] < this->mCostPipeline2[this->mLen - 1]) {
        choose = 1;
    } else {
        choose = 2;
    }
    pathOutput.push(choose);
    for (int i = this->mLen - 2; i >= 0; i--) {
        if (choose == 1) {
            int index = this->path1[i];
            choose = index;
        } else if (choose == 2) {
            int index = this->path2[i];
            choose = index;
        }
        pathOutput.push(choose);

    }
    for (int i = 0; !pathOutput.empty(); i++) {
        cout << "step  " << i + 1 << endl;
        cout << "choose  " << pathOutput.top() << endl;
        pathOutput.pop();
    }
}