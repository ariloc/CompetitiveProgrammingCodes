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

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        string s; cin >> s; s += ','; // agrego dummy

        map<ll,map<ll,ll>> cnt; // por c/nivel, la cantidad de cierto número
        ll lvl = 0, num = 0, sum = 0;
        forn(j,s.size()) {
            if (s[j] >= '0' && s[j] <= '9') num = 10LL*num + s[j]-'0';
            else {
                if (num) cnt[lvl][num]++, num = 0, sum++;
                lvl += (s[j] == '[');
                lvl -= (s[j] == ']');
            }
        }

        ll mini = sum, lastLvl = (*cnt.rbegin()).fst, fstLvl = (*cnt.begin()).fst;
        for (auto &j : cnt) {
            for (auto &k : j.snd) { // para cada posible valor, contamos si lo dejamos fijo

                ll myLvl = j.fst, myVal = k.fst, cntEq = 0;
                while (myLvl <= lastLvl) {
                    if (cnt[myLvl].count(myVal)) cntEq += cnt[myLvl][myVal];
                    // sigue siendo posible, simplemente nos vamos porque como el input es entero, no hay nada que ver de acá en adelante
                    if (myLvl < lastLvl && (myVal&1)) break;
                    myLvl++, myVal >>= 1;
                }

                myLvl = j.fst-1LL, myVal = k.fst*2LL; // ya nos contamos antes, entonces ahora nos vamos directamente al lvl superior
                while (myLvl >= fstLvl) {
                    if (cnt[myLvl].count(myVal)) cntEq += cnt[myLvl][myVal];
                    myLvl--, myVal <<= 1;
                }

                mini = min(mini,sum-cntEq);
            }
        }

        cout << mini << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
