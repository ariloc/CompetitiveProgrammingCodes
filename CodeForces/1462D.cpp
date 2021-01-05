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

const int MAXN = 3002;
const int INF = 1e9+5;

int arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        map<int,ii> sums; set<int> inhab;
        forn(j,n) cin >> arr[j];
        forsn(j,1,n) arr[j] += arr[j-1]; // TAd
        forn(j,n) forsn(k,j,n) {
            int s = arr[k]-(j-1 >= 0 ? arr[j-1] : 0);
            auto it = sums.find(s);
            if (it == sums.end() && !j) sums[s] = {1,k+1};
            else {
                if ((*it).snd.snd > j) continue;
                if ((*it).snd.snd != j) {inhab.insert(s); continue;}
                sums[s] = {(*it).snd.fst+1,k+1};
            }
        }
        int mini = n-1;
        for (auto &j : sums) {
            if (inhab.count(j.fst) || j.snd.snd != n) continue;
            mini = min(mini,n-j.snd.fst);
        }
        cout << mini << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
