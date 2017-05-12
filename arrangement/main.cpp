#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> arragements;

    vector<vector<int>> permute(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            vector<int> oneArragement;
            oneArragement.push_back(nums[i]);
            arragement(nums, oneArragement, 1);
        }
        return this->arragements;
    }

    void arragement(vector<int> &nums, vector<int> oneArragement, int l) {
        if (l == nums.size()) {
            arragements.push_back(oneArragement);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (isUsed(oneArragement, nums[i])) {
                continue;
            } else {
                vector<int> tmp(oneArragement);
                tmp.push_back(nums[i]);
                arragement(nums, tmp, l + 1);
            }
        }
    }

    bool isUsed(vector<int> oneArragement, int num) {
        for (auto it = oneArragement.begin(); it != oneArragement.end(); it++) {
            if (*it == num) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sl;
    vector<int> nums{1, 2, 3};
    sl.permute(nums);
    return 0;
}