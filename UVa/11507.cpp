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

const int redir[6][4] = { // si estoy en... y hago cierto mov
    {5,4,0,0},
    {4,5,1,1},
    {2,2,5,4},
    {3,3,4,5},
    {0,1,2,3},
    {1,0,3,2}
};

map<string,int> ids;
map<int,string> revIds;

int main() {
    // relaciones
    ids["+y"] = 0, revIds[0] = "+y";
    ids["-y"] = 1, revIds[1] = "-y";
    ids["+z"] = 2, revIds[2] = "+z";
    ids["-z"] = 3, revIds[3] = "-z";
    ids["+x"] = 4, revIds[4] = "+x";
    ids["-x"] = 5, revIds[5] = "-x";

    int l;
    while (cin >> l) {
        if (!l) break;

        int point = 4;
        vector<string> ords;
        forn(i,l-1) {
            string aux; cin >> aux;
            if (aux != "No") point = redir[point][ids[aux]];
        }

        cout << revIds[point] << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
