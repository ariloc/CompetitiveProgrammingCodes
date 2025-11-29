#include <vector>
#include <iostream>

#define forn(i,n) for(int i = 0;i<int(n); i++)

using namespace std;

long long escalera(vector<int> v, int H)
{
    long long hAct = 0;
    long long cnt = 0;
    for (auto &i : v) {
        hAct+=i;
        cnt++;
        if (hAct >= H) break;
    }
    if (hAct < H) {
        int cVuelta = hAct;
        int vueltas;
        vueltas = H/cVuelta;
        vueltas-=(vueltas > 50 ? 50 : v.size()-2);
        cnt= vueltas*v.size();
        hAct = cVuelta*vueltas;
    }
    if (hAct < H) {
    while (hAct < H) {
        for (auto &i : v) {
            hAct+=i;
            cnt++;
            if (hAct >= H) break;
        }
    }
    }

        /*int cVuelta = hAct;
        while (H-hAct > v.size()) {
            hAct+=cVuelta;
            cnt+=v.size();
        }
        if (hAct != H) {
            for (auto &i : v) {
                hAct+=i;
                cnt++;
                if (hAct >= H) break;
            }
        }
    }*/
    return cnt;
}


#ifndef EVAL
    #include <iostream>

    int main() {
//        freopen("escalera1.in","r",stdin);

        int N, H;
        cin >> N >> H;
        vector<int> v;
        v.reserve(N);
        for (int i=0;i<N;i++) {
            int x; cin >> x;
            v.push_back(x);
        }
        cout << escalera(v, H) << endl;
    }
#endif
