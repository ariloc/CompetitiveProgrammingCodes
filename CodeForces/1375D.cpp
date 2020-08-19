#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 1005;

int arr[MAXN];
bool mark[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;

    forn(i,t) {
        int N; cin >> N;

        multiset<int> tot;
        memset(mark,0,sizeof(mark));

        forn(j,N) {
            int x; cin >> x;
            tot.insert(x);
            arr[j] = x;
        }

        vi moves;

        int cnt = 0;
        while (cnt < N) {
            int act = -1; // get MEX
            bool broken = false;
            for (auto &o : tot) {if (o == act+1) act++; if (o > act+1) {act++; broken = true; break;}}
            if (!broken) act++;

            int ind = act; if (ind >= N) forn(j,N) if (!mark[j]) {ind = j; break;}
            tot.erase(tot.find(arr[ind]));
            tot.insert(act);
            arr[ind] = act;
            moves.pb(ind+1);
            mark[ind] = true;
            if (ind == act) cnt++;
        }

        cout << moves.size() << '\n';
        for (auto &o : moves) cout << o << ' ';
        cout << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!