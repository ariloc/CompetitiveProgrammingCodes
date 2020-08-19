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
int n,q;
map< ii, set<ii> > conflictos;
int conflictoTot = 0;

void addConflicto(int &x1, int y1, int &x2, int &y2) {
    ii a = {x1,y1}, b = {x2,y2};
    conflictos[a].insert(b);
    conflictos[b].insert(a);
    conflictoTot++;
}

void deleteConflictos(int &x, int &y) {
    ii a = {x,y};
    for (auto &i : conflictos[a]) {
        conflictos[i].erase(a);
        conflictoTot--;
    }
    conflictos.erase(a);
}

int main() {
    FAST_IO;
    //freopen("tester.out","w",stdout);

    cin >> n >> q;

    forn (i,q) {
        int x,y;
        bool posib = true;
        cin >> x >> y;
        x--; y--;
        plano[x][y] = !plano[x][y];

        if (plano[x][y]) {
            int newX = (x == 1 ? 0 : 1);
            if (plano[newX][y]) addConflicto(newX,y,x,y);
            if (y-1 >= 0 and plano[newX][y-1]) addConflicto(newX,y-1,x,y);
            if (y+1 >= 0 and plano[newX][y+1]) addConflicto(newX,y+1,x,y);
        }
        else deleteConflictos(x,y);

        if (conflictoTot) cout << "No" << '\n';
        else cout << "Yes" << '\n';
    }

    return 0;
}