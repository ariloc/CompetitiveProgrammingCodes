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

map<int,int> boxes;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        boxes.clear();

        int n,w; cin >> n >> w;
        forn(i,n) {
            int x; cin >> x;
            boxes[x]++;
        }

        int r = 0;
        while (!boxes.empty()) {
            int w_aux = w;
            auto it = boxes.end();
            vi toDel;
            do {
                it--;

                int sz = (*it).fst;
                while (w_aux >= sz && (*it).snd > 0) 
                    w_aux -= sz, (*it).snd--;
                if (!(*it).snd) toDel.pb(sz);
                
            } while(it != boxes.begin());

            for (auto &i : toDel) boxes.erase(i);

            r++;
        }

        cout << r << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!