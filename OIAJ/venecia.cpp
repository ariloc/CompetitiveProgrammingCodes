#include <iostream>
#include <vector>
#include <algorithm>

#define forn(i,n) for(int i = 0; i < int(n); i++)

using namespace std;

struct calle {
    int L,e,c;
};

const int MAXN = 3e5+1;
vector<calle> esquinas[MAXN];
vector<bool> done;
vector<int> orden;

int dfs(int n) {
    for (auto &i : esquinas[n]) {
        if (not done[i.c]) {
            orden.push_back(i.c);
            done[i.c] = true;
            dfs(i.e);
            orden.push_back(i.c);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("venecia.in","r",stdin);

    int N,M,S;
    cin >> N >> M >> S;

    forn(i,M) {
        int a,b,L;
        cin >> a >> b >> L;
        esquinas[a].push_back({L,b,(i+1)});
        esquinas[b].push_back({L,a,(i+1)});
    }

    done.resize(MAXN, false);
    dfs(S);

    cout << M*2 << endl;
    forn (i,M*2) cout << orden[i] << ' ';
    return 0;
}
