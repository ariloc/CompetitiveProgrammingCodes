#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n)-1; i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int MAXN = 5005;
const int MOD = 1e9+7;

struct trie {
    map<char,trie> edges;
    int cnt = 0;

    void insert (const string &s, int i = 0) {
        if ((int)s.size() == i) cnt++;
        else edges[s[i]].insert(s,i+1);
    }

    void find (int v_orig, int *DP, const string &s, int i) {
        if (i <= (int)s.size()) {
            DP[i] = (DP[i] + ((v_orig * (ll)cnt)%MOD))%MOD;
            if (edges.count(s[i])) edges[s[i]].find(v_orig,DP,s,i+1);
        }
    }
};

trie T;
int dp[MAXN];

int main() {
    FAST_IO;
    
    string s; cin >> s;
    int n = (int)s.size();

    int k; cin >> k;
    forn(i,k) {
        string x; cin >> x;
        T.insert(x);
    }

    dp[0] = 1;
    forn(i,n) T.find(dp[i],dp,s,i);
    
    cout << dp[n];

    return 0;
}