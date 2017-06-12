#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Item {
public:
    Item(int w, int v) : w(w), v(v) {}

    int w;
    int v;
};


using namespace std;

int main() {


    vector<Item> items = {{5, 20},
                          {4, 10},
                          {3, 12}};
    int w = 10;

    vector<vector<int>> tables;
    tables.resize(w + 1);
    for (int i = 0; i < tables.size(); i++) {
        tables[i].resize(items.size() + 1, 0);
    }

    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= items.size(); j++) {
            if (i < items[j - 1].w) {
                tables[i][j] = tables[i][j - 1];
            } else {
                tables[i][j] = max(tables[i - items[j - 1].w][j - 1] + items[j - 1].v, tables[i][j - 1]);
            }
        }
    }


}