#include <vector>
#include <iostream>

#define forn(i,n) for(int i = 0;i<int(n); i++)

using namespace std;

long long escalera(vector<int> v, int H)
{
    int hAct = 0;
    float cVuelta = 0;
    long long cnt = 0;
    float aux;
    for (auto &i : v) {
        hAct+=i;
        cnt++;
        if (hAct >= H) break;
    }
    if (hAct < H) {
        cVuelta = H-hAct;
        cVuelta = cVuelta / hAct;
        aux += (cVuelta*v.size());
        aux--;
        cnt += (int)aux;
    }
    else return cnt;
    return cnt;
}


#ifndef EVAL
    #include <iostream>

    int main() {
        //freopen("escalera1.in","r",stdin);

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
