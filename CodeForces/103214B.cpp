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

vector<string> dict;
string act;

int main() {
    FAST_IO;
    
    int n; cin >> n;
    forn(i,n) {string s; cin >> s; dict.pb(s);}
    forn(j,7) {string s; cin >> s; act.pb(s[0]);}

    sort(all(act));

    int maxi = 0;
    do {
        forn(i,n) {
            bool posib = 1;
            int m = (int)dict[i].size();
            forn(j,m) if (act[j] != dict[i][j]) posib = 0;
            if (posib) maxi = max(maxi, (m > 3 ? m*2 : m));
        }
    } while(next_permutation(all(act)));

    cout << maxi;

    return 0;
}
 
/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!