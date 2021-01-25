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

const int MAXN = 2005;
const int INF = 1e9+5;

int arr[MAXN];
map<int,int> num;
vector<ii> mov;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n; n *= 2;
        forn(j,n) cin >> arr[j];
        sort(arr,arr+n);

        // sucesión de los eventos si elimino el j-ésimo elemento
        bool flag = false;
        forn(j,n) {
            mov.clear(); num.clear();
            forn(k,n) if (j != k) num[arr[k]]++;

            int bigCh = (*num.rbegin()).fst;
            int last = max(bigCh,arr[j]);
            num[bigCh]--; if (!num[bigCh]) num.erase(bigCh);

            bool posib = true;
            while (!num.empty()) {
                auto itBig = prev(num.end());

                int v = last-(*itBig).fst;
                auto it2 = num.find(v);
                if (it2 == num.end()) {posib = false; break;}
                int a = (*itBig).fst, b = (*it2).fst;

                if (a == b && num[a] < 2) {posib = false; break;}
                int s = a+b;
                if (s != last) {posib = false; break;}

                last = max(a,b);
                mov.pb({a,b});
                num[a]--; num[b]--;
                if (!num[a]) num.erase(a);
                if (!num[b]) num.erase(b);
            }

            if (posib) {
                flag = true;
                cout << "YES\n";
                cout << bigCh+arr[j] << '\n';
                cout << bigCh << ' ' << arr[j] << '\n';
                for (auto &o : mov) cout << o.fst << ' ' << o.snd << '\n';
                break;
            }
        }

        if (!flag) cout << "NO\n";
    }
    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
