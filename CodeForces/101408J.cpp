#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 1e5+5;

bool validWin[MAXN],dpL[MAXN],dpR[MAXN];
int songs[MAXN],aparic[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int s,n; cin >> s >> n;
        forn(j,n) cin >> songs[j];

        // reset
        forn(j,max(n,s)+1) aparic[j] = 0, validWin[j] = dpL[j] = dpR[j] = 0;

        int cantRep = 0;
        forn(j,min(s,n)) aparic[songs[j]]++, cantRep += (aparic[songs[j]] > 1);
        if (!cantRep) validWin[0] = true;
        forsn(j,1,n) {
            if (j+s-1 < n) aparic[songs[j+s-1]]++, cantRep += (aparic[songs[j+s-1]] == 2);
            cantRep -= (aparic[songs[j-1]] == 2), aparic[songs[j-1]]--;
            if (!cantRep) validWin[j] = true;
        }

        forn(j,s+1) aparic[j] = 0; // tmp reset
        forn(j,n) {
            if (!aparic[songs[j]]) dpL[j] = true; else break;
            aparic[songs[j]]++;
        }
        forn(j,s+1) aparic[j] = 0; // 2nd tmp reset
        dforn(j,n) {
            if (!aparic[songs[j]]) dpR[j] = true; else break;
            aparic[songs[j]]++;
        }

        forsn(j,n,s) dpL[j] |= dpL[j-1];

        int cnt = 0;
        forn(j,s) {
            if (j >= n) if (dpL[j-1]) {cnt++; continue;}

            bool posib = true;
            int k;
            for (k = j; k < n; k += s) if (!validWin[k]) {posib = false; break;}
            //cerr << k << ' ' << s << endl;
            if (k >= n) k -= s; // por las dudas
            if (!posib || (j && !dpL[j-1]) || (k < n-1 && !dpR[k+1])) continue;
            cnt++;
        }

        cout << cnt << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
