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

const int MAXA = 26;
const int MAXN = 1005;
const int MAXL = 102;
const int INF = 10000;

struct trie {
    map<int,trie> edges;
    int nd,cnt;
    trie(){nd = -1, cnt = 0;}

    void insert (vi &s, int id, int i = 0) {
        if ((int)s.size() != i) edges[s[i]].insert(s,id,i+1);
        else nd = id, cnt++;
    }

    ii find (vi &s, int i = 0) {
        if ((int)s.size() == i) return {nd,cnt};
        if (!edges.count(s[i])) return {-1,-1};
        else return edges[s[i]].find(s,i+1);
    }
};

int dp[MAXN];
ii P[MAXN];
vector<string> dict;
trie T[MAXA][MAXA];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        dict.clear(); // resets
        forn(j,MAXA) forn(k,MAXA) T[j][k].edges.clear(), T[j][k].nd = -1, T[j][k].cnt = 0;
        forn(j,MAXN) dp[j] = 0, P[j] = {-1,-1};

        string s; cin >> s;
        int n; cin >> n;
        forn(j,n) {
            string x; cin >> x;
            dict.pb(x);

            vi tmp(MAXA,0);
            forn(k,x.size()) tmp[x[k]-'a']++;
            T[x[0]-'a'][x.back()-'a'].insert(tmp,j);
        }

        int m = s.size();

        vi acc(MAXA,0);
        dp[0] = 1;
        forsn(j,1,m+1) {
            acc.assign(MAXA,0);
            dforsn(k,max(1,j-MAXL),j+1) {
                acc[s[k-1]-'a']++;
                ii v = T[s[k-1]-'a'][s[j-1]-'a'].find(acc);
                if (v.fst == -1 || !dp[k-1]) continue; // si no encontramos chau
                if (dp[k-1] > 1) dp[j] = 2;
                else dp[j] = min(2,dp[j]+min(2,v.snd));
                //cerr << s[k-1] << ' ' << s[j-1] << ' ' << v.fst << endl;

                P[j] = {k-1,v.fst};
            }
        }

        if (dp[m] == 1) {
            vector<string> rta;
            for (ii e = P[m]; e.fst != -1; e = P[e.fst])
                rta.pb(dict[e.snd]);
            dforn(j,rta.size()) cout << rta[j] << " \n"[j == 0];
        }
        else if (dp[m] > 1) cout << "ambiguous\n";
        else cout << "impossible\n"; // !dp[m]
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
