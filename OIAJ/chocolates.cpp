#include <vector>
#include <algorithm>

using namespace std;

int chocolates(int K, vector<int> &x) {
    int rta = 0;
    while(true) {
        sort(x.begin(),x.end());
        reverse(x.begin(),x.end());
        int cnt = 0;
        for (int i = 0; i < (int)x.size(); i++) {
            if (x[i]) ++cnt, --x[i];
            if (cnt >= K) break;
        }
        if (cnt < K) break;
        rta++;
    }
    return rta;
}
