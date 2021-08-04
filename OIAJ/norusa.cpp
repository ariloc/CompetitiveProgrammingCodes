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

const int INF = 1e9+5;

vector<ii> ptos;

int main() {
    FAST_IO;
    freopen("norusa.in","r",stdin);
    freopen("norusa.out","w",stdout);

    int N,posX,posY;
    cin >> N;

    forn (i,N) {
        int x,y;
        cin >> x >> y;
        ptos.push_back({x,y});
    }
    cin >> posX >> posY;

    int rta = 0,actV = 0;
    ii posAct = {posX,posY};
    forn (i,ptos.size()) {
        if (ptos[i].fst <= posAct.fst) continue;
        if (i%2) {
            actV += abs(ptos[i].snd - posAct.snd);
            posAct = {ptos[i].fst,ptos[i].snd};
        }
        else {
            actV -= abs(posAct.snd - ptos[i].snd);
            posAct = {ptos[i].fst,ptos[i].snd};
            if (actV < 0) break;
            else rta++;
        }
    }

    cout << rta;

    return 0;
}