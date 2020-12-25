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

const int MAXN = 55;

int arr[MAXN],n;

vector<vi> rta;
void swapR (int i, int j) {
    vi toPush,posic;
    if (i > 0) {toPush.pb(i); posic.pb(0);}
    int l = i, r = j, l1 = j-i, r1 = 1;
    dforsn(o,i+1,j) if (arr[o] == arr[o+1]-1) {r--; l1--; r1++;} else break;
    toPush.pb(l1); toPush.pb(r1); posic.pb(l); posic.pb(r);
    if (j < n-1) {toPush.pb(n-j-1); posic.pb(j+1);}
    rta.pb(toPush);

    int ind = 0,tmp[MAXN];
    dforn(k,posic.size())
        for (int o = posic[k]; o-posic[k] < toPush[k]; o++)
            tmp[ind++] = arr[o];

    forn(o,n) arr[o] = tmp[o];
}

int main() {
    FAST_IO;

    cin >> n;
    forn(i,n) cin >> arr[i];

    while (true) {
        forn(i,n) {
            bool swapped = false;
            if (arr[i] > 1 && (i-1 < 0 || arr[i-1] != arr[i]-1))
                forsn(j,i+1,n) if (arr[j] == arr[i]-1) {
                    swapR(i,j); swapped = true; break;
                }
            if (swapped) break;
        }
        bool sorted = true;
        forsn(i,1,n) if (arr[i] < arr[i-1]) {sorted = false; break;}
        if (sorted) break;
    }

    cout << rta.size() << '\n';
    for (auto &i : rta) {
        cout << i.size() << ' ';
        for (auto &j : i) cout << j << ' ';
        cout << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
