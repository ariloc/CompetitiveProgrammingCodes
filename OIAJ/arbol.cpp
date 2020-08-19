#include <iostream>
#include <vector>

#define forn(i,n) for(int i = 0; i < int(n); i++)

using namespace std;

typedef vector<int> vi;
const int MAXN = 1e5;

vi arbol[MAXN], done, raices, arcos;
int cantE[MAXN];
int recor = 0;

int dfs(int &n) {
    done[n] = true;
    recor++;
    for (auto &i: arbol[n]) {
        if (not done[i])
            dfs(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("arbol.in","r",stdin);
//    freopen("arbol.out","w",stdout);
    int N,M;
    bool tree = 1;

    cin >> N >> M;

    forn(i,M) {
        int a, b;
        cin >> a >> b; --a; --b;
        arbol[a].push_back(b);
        cantE[b]++;
    }
    forn (i,N)  {
        if (cantE[i] == 0) raices.push_back(i+1);
        if (cantE[i] > 1) arcos.push_back(i+1);
    }
    if (raices.size() == 1) {
        int x = raices[0]-1;
        done.resize(N, false);
        dfs(x);
    }
    if (raices.size() > 1 or arcos.size() or recor != N) tree = false;

    if (tree)
        cout << "Si" << ' ' << raices[0];
    else {
        cout << "No" << '\n';

        if (raices.size() > 1) {
            for (auto &i : raices) cout << i << ' ';
        }
        else if (raices.size() == 0)
            cout << 0;
        else cout << raices[0];

        cout << '\n';

        if (arcos.size())
            for (auto &i : arcos) cout << i << ' ';
        else cout << 0;

        cout << '\n';

        if (recor != 1 and recor != N and recor != 0) {
            forn (i,N) {
                if (!done[i]) cout << i+1 << ' ';
            }
        }
        else cout << 0;
    }
    return 0;
}
