#include <vector>

using namespace std;

int basquet(vector<int> &x, vector<int> &y) {
    int acc = 0;
    for (int i = 0; i < (int)x.size(); i++) {
        if (x[i] >= 90 && 10 <= y[i] && y[i] <= 40)
            acc += 2;
        else acc += 3;
    }
    return acc;
}
