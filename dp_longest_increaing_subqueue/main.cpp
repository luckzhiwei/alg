#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        vector<int> table(size, 1);
        int max = 1;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i] && table[j] + 1 > table[i]) {
                    table[i] = table[j] + 1;
                }
            }
            if (max < table[i]) {
                max = table[i];
            }
        }
        return max;
    }
};

int main() {
    vector<int> test{1, 3, 6, 7, 9, 4, 10, 5, 6};
    Solution sl;
    cout << sl.lengthOfLIS(test) << endl;
    return 0;
}