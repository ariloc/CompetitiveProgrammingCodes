#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 1e5+5;
int const MAXL = 100;
int const INF = 1e9;

int dp[MAXN];

struct trie {
    map<char, trie> edges;
    bool ok; 
    trie(){ok = false;};

    void insert(const string &s, int i = 0) {
        if (i == (int)s.size()) ok = true;
        else edges[s[i]].insert(s,i+1);
    }

    void propagate(const string &s, const int orig, const int idx, int i = 0) {
        if (i && ok) dp[idx+i-1] = min(dp[idx+i-1],orig);
        if (i < (int)s.size()) {
            auto it = edges.find(s[i]);
            if (it != edges.end())
                (*it).snd.propagate(s, orig, idx, i+1);
        }
    }
};

trie T;

int cubrecadena(string &S, vector<string> &t) {
    for (auto &s : t) T.insert(s);
    int n = (int)S.size();
    dp[0] = 0;
    forsn(i,1,n+1) dp[i] = INF;
    forsn(i,1,n+1) {
        string aux;
        for (int j = i; j <= min(n,i+MAXL); j++) aux.pb(S[j-1]);
        dp[i] = min(dp[i], dp[i-1]+1);
        T.propagate(aux, dp[i-1], i);
    }
    return dp[n];
}
