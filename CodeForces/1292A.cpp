#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 10e5;

bool plano[2][MAXN];
set<int> marcados;
int n,q;

bool valid(int &y) {
    if (plano[0][y] and plano[1][y]) return false;
    if (plano[0][y]) {
        if (y-1 >= 0 and plano[1][y-1]) return false;
        if (y+1 < n and plano[1][y+1]) return false;
    }
    if (plano[1][y]) {
        if (y-1 >= 0 and plano[0][y-1]) return false;
        if (y+1 < n and plano[0][y+1]) return false;
    }
    return true;
}

int main() {
    FAST_IO;

    cin >> n >> q;

    forn (i,q) {
        int x,y;
        bool posib = true;
        cin >> x >> y;
        x--; y--;
        plano[x][y] = !plano[x][y];
        if (plano[x][y]) marcados.insert(y);
        else marcados.erase(y);
        for (auto i : marcados)
            if (!valid(i)) {posib = false; break;}
        if (posib) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }

    return 0;
}