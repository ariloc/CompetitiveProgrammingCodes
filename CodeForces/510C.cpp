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
typedef unsigned long long ull;
typedef pair<int,int> ii;

const int MAXA = 26;

vector<string> lst;
bool ady[MAXA][MAXA];
int inDeg[MAXA];

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) {
        string s; cin >> s;
        lst.pb(s);
    }

    forn(i,n) forsn(j,i+1,n) {
        bool broke = false;
        forn(k,min((int)lst[i].size(),(int)lst[j].size())) {
            if (lst[i][k] != lst[j][k]) {
                broke = true;
                if (!ady[lst[i][k]-'a'][lst[j][k]-'a']) inDeg[lst[j][k]-'a']++;
                ady[lst[i][k]-'a'][lst[j][k]-'a'] = true;
                break;
            }
        }
        if (!broke && (int)lst[i].size() > (int)lst[j].size())
            return cout << "Impossible", 0;
    }

    queue<int> Q;
    vi topSort;
    forn(i,MAXA) if (!inDeg[i]) Q.push(i);

    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();
        topSort.pb(e);
        forn(i,MAXA) {
            if (ady[e][i] && !(--inDeg[i])) Q.push(i);
        }
    }

    if ((int)topSort.size() != MAXA)
        cout << "Impossible";
    else for (auto &i : topSort) cout << (char)(i+'a');

    return 0;
}
 
/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!