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

const int MAXN = 1e6+5;
const int MAXA = 26;

string book[MAXN];
int inDegree[MAXA];
bitset<MAXN> exists;
bool ady[MAXA][MAXA]; // 1 es a->b

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;
    forn(i,n) {
        int p; cin >> p;
        forn(j,k) cin >> book[k*p+j];
    }

    int cntLet = 0;

    forn(i,n*k) forn(j,book[i].size()) if (!exists[book[i][j]-'a']) exists[book[i][j]-'a'] = true, cntLet++;
    forsn(i,1,n*k) {
        bool broke = false;
        forn(j,min(book[i].size(),book[i-1].size())) {
            if (book[i-1][j] != book[i][j]) {
                if (!ady[book[i-1][j]-'a'][book[i][j]-'a']) inDegree[book[i][j]-'a']++;
                ady[book[i-1][j]-'a'][book[i][j]-'a'] = true; broke = true; break;
            }
        }
        if (!broke && book[i].size() < book[i-1].size()) return cout << "IMPOSSIBLE", 0;
    }

    vi topSort;
    queue<int> Q;
    forn(i,MAXA) if (!inDegree[i] && exists[i]) Q.push(i);
    while (!Q.empty()) {
        int e = Q.front(); Q.pop();
        topSort.pb(e);

        forn(i,MAXA) {if (ady[e][i])
            if (!(--inDegree[i])) Q.push(i);
        }
    }

    if ((int)topSort.size() < cntLet) cout << "IMPOSSIBLE";
    else {
        string s;
        for (auto &i : topSort) s += (char)(i+'a');
        cout << s;
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
