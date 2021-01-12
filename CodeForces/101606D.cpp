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

    string s; cin >> s;
    string aux = s;

    sort(all(aux));

    int n = s.size(); bool passfst = false;
    forn(j,n) {
        if (aux[j] != s[j])
            forsn(k,j+1,n) if (aux[k] == s[j]) {
                int a = j, b = k;
                if (aux[a] < aux[b]) swap(a,b);
                swap(aux[a],aux[b]);
                if (passfst) cout << '\n';
                else passfst = true;
                cout << a+1 << ' ' << b+1;
                break;
            }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
