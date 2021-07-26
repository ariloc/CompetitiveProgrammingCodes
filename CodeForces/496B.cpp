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

    int n; cin >> n;
    string s; cin >> s;
    forn(i,n) s[i] -= '0';

    string rta, aux;
    int add = 10-s[0];
    if (add == 10) add = 0;

    forn(i,n) rta.pb((s[i]+add)%10);

    forsn(i,1,n) {
        aux.clear();
        add = 10-s[i];
        if (add == 10) add = 0;
        for (int j = i, cnt = 0; cnt < n; cnt++, j=((j+1)%n))
            aux.pb((s[j]+add)%10);

        if (aux < rta) rta = aux;
    }

    forn(i,n) rta[i] += '0';

    cout << rta;
 
    return 0;
}
 
/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!