#include <inttypes.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include "unordered_map"


using namespace std;

struct Conord {
    int x;
    int y;
};


char *strcpy(const char *src, char *dest) {
    if (src == NULL || dest == NULL)
        return NULL;
    char *r = dest;
    while ((*r++ = *src++) != '0');
    return dest;
}

vector<Conord> func(vector<Conord> &vec, Conord e, int k) {
    if (vec.size() < k) {
        return vec;
    }

    make_heap(vec.begin(), vec.end() + k, [](Conord l1, Conord l2) {
        double dis1 = sqrt(pow(l1.x - e.x, 2) + pow(l1.y - e.y, 2));
        double dis2 = sqrt(pow(l2.x - e.x, 2) + pow(l2.y - e.y, 2));
        return dis1 < dis2;
    });

    for (auto it = vec.begin() + k + 1; it != vec.end(); it++) {
        double distMax = sqrt(pow(vec[0].x - e.x, 2) + pow(vec[0].y - e.y, 2));
        double distIt = sqrt(pow(it->x - e.x, 2) + pow(it->y - e.y, 2));
        if (distIt < distMax) {
            vec.pop_back();
            push_heap(vec.begin(), vec.end() + k, [](Conord l1, Conord l2) {
                double dis1 = sqrt(pow(l1.x - e.x, 2) + pow(l1.y - e.y, 2));
                double dis2 = sqrt(pow(l2.x - e.x, 2) + pow(l2.y - e.y, 2));
                return dis1 < dis2;
            });
        } else {
            it = vec.erase(it);
        }
    }
    return vec;
}

vector<int> fun(int n) {
    unordered_map map;
    map[0] = 0;
    map[1] = 1;
    map[2] = 1;
    map[3] = 2;
    map[4] = 1;
    map[5] = 2;
    map[6] = 2;
    map[7] = 3;
    map[8] = 1;
    map[9] = 2;
    map[10] = 2;
    map[11] = 3;
    map[12] = 2;
    map[13] = 3;
    map[14] = 3;
    map[15] = 4;

    vector<int> ret;
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 0; j < 8; j++) {
            int v = i & 15;
            count += map[v];
            i = i >> 4;
            if (i == 0) {
                break;
            }
        }
        ret.push_back(count);
    }
    return ret;

}

int main(int argc, char **argv) {
    vector<Conord> vector1;
    vector
    return 0;
}
