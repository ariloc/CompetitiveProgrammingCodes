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

const int MAXN = 505;

int arr[MAXN];
vi ones;
vector<ii> ot,rta;

int main() {
    FAST_IO;

    int n; cin >> n;
    int availDeg = 0;
    forn(i,n) {
        int x; cin >> x;
        if (x > 1) ot.pb({x,i}), availDeg += x;
        else ones.pb(i);
    }

    // meto un par en los extremos de los de unos, si tengo
    if (!ones.empty()) ot.insert(ot.begin(),{1,ones.back()}), ones.pop_back(), availDeg++;
    if (!ones.empty()) ot.pb({1,ones.back()}), ones.pop_back(), availDeg++;

    forn(i,ot.size()-1) rta.pb({ot[i].snd,ot[i+1].snd});
    forn(i,ot.size()) ot[i].fst -= 2, availDeg -= 2;
    ot[0].fst++, ot.back().fst++; // los extremos solo uno
    availDeg += 2;

    if (availDeg < (int)ones.size()) return cout << "NO", 0;

    int idx = 0;
    forn(i,ot.size()) {
        while (ot[i].fst > 0 && idx < (int)ones.size())
            rta.pb({ot[i].snd,ones[idx++]}), ot[i].fst--;
    }

    cout << "YES " << ot.size()-1 << '\n' << rta.size() << '\n';
    for (auto &i : rta) cout << i.fst+1 << ' ' << i.snd+1 << '\n';

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
