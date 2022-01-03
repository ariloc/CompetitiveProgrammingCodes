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

const int INF = 2e9;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int n,k; cin >> n >> k;
        string s; cin >> s;
        
        int block_st = -1, block_nd = -1;
        if (s[0] == 'L') {
            block_st = 0;
            forn(i,n) if (s[i] == 'W') break;
                      else block_st++;
        }

        if (block_st == n) {
            if (!k) {puts("0"); continue;}
            int cnt = min(k,n);
            printf("%d\n",cnt*2 - 1);
            continue;
        }

        if (s[n-1] == 'L') {
            block_nd = 0;
            dforn(i,n) if (s[i] == 'W') break;
                       else block_nd++;
        }

        vector<ii> blocks;
        int st = -1, cnt = 0;
        forsn(i, (block_st == -1 ? 0 : block_st), (block_nd == -1 ? n : n-block_nd)) {
            if (s[i] == 'W' && st != -1)
                blocks.pb({cnt,st}), cnt = 0, st = -1;
            if (s[i] == 'L') {
                if (st == -1) st = i;
                cnt++;
            }
        }
        
        sort(all(blocks));
        for (auto &i : blocks) {
            if (k <= 0) break;
            forn(j,min(k,i.fst))
                s[i.snd+j] = 'W';
            k -= i.fst;
        }

        if (k > 0 && block_nd != -1) {
            forn(i,min(block_nd,k))
                s[n-block_nd+i] = 'W';
            k -= block_nd;
        }

        if (k > 0 && block_st != -1) {
            forn(i,min(block_st,k))
                s[block_st-1-i] = 'W';
        }

        int score = 0;
        forn(i,n)
            score += (s[i] == 'W') + (i-1 >= 0 && s[i] == s[i-1] && s[i] == 'W');

        printf("%d\n",score);
    }

    return 0;
}