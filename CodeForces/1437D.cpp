#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        vi arr;
        forn(j,n) {
            int x; cin >> x;
            if (j) arr.pb(x);
        }
        queue<int> Q[2]; Q[0].push(1); // dummy
        int act = 0, ind = 0, lvl = -1;
        while (!Q[0].empty() || !Q[1].empty()) {
            lvl++;
            while(!Q[act].empty()) {
                Q[act].pop();

                if (ind < (int)arr.size()) {Q[1^act].push(arr[ind]); ind++;}
                forsn(j,ind,arr.size()) {
                    if (arr[j] >= arr[j-1]) {Q[1^act].push(arr[j]); ind++;}
                    else break;
                }
            }
            act = (act+1)&1;
        }

        cout << lvl << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
