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

const int MAXN = 1e5+10;
const int INF = 1e9+5;
const int TOP = 9*MAXN;

int arr[MAXN],S[MAXN];

void solve (int l, int r) {
    int s = 1;
    forsn(j,l,r+1) s = min((ll)TOP,(ll)s*arr[j]);

    if (s == TOP) {
        vector<char> ops(r-l+1);
        string str;
        for (int j = l; arr[j] == 1 && j <= r; j++) ops[j-l] = '+';
        for (int j = r; j >= l && arr[j] == 1; j--) ops[j-1-l] = '+';
        forsn(j,l,r+1) str += to_string(arr[j])+(!ops[j-l] ? "*" : "+");
        str.pop_back(); cout << str;
        return;
    }

    vi ids;
    forsn(j,l,r+1) if (arr[j] > 1) ids.pb(j);

    vi dp(ids.size()+1,0);
    dforn(i,ids.size()) {
        int m = 1;
        forsn(j,i,ids.size()) {
            m *= arr[ids[j]];
            int v = dp[j+1]+m+((j+1 >= (int)ids.size() ? r+1 : ids[j+1])-ids[j]-1);
            if (v > dp[i]) dp[i] = v, S[ids[i]] = ids[j];
        }
    }

    forsn(j,l,r+1) {
        if (S[j] != -1) {
            forsn(k,j,S[j]+1) cout << arr[k] << (k+1 <= S[j] ? "*" : "");
            j = S[j]; cout << (j+1 <= r ? "+" : "");
        }
        else cout << arr[j] << (j+1 <= r ? "+" : "");
    }
}

int main() {
    memset(S,-1,sizeof(S));
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> arr[i];
    string s; cin >> s;
    set<char> sym; for (auto &i : s) sym.insert(i);

    if ((int)s.size() == 1) forn(j,n) {cout << arr[j]; if (j < n-1) cout << s[0];}
    else if (s.size() == 2) {
        if (sym.count('+') && sym.count('-'))
            forn(j,n) {cout << arr[j]; if (j < n-1) cout << '+';}
        else if (sym.count('*') && sym.count('-')) {
            forn(j,n) {
                cout << arr[j];
                if (j < n-1) {
                    if (!arr[j+1]) cout << '-';
                    else cout << '*';
                }
            }
        }
        else goto CASE_THREE;
    }
    else {
        CASE_THREE:

        int prev = -1;
        forn(j,n) {
            if (!arr[j]) {
                if (prev+1 != j) solve(prev+1,j-1);
                cout << (j ? "+" : "") << "0" << (j+1 < n && arr[j+1] ? "+" : "");
                prev = j;
            }
        }
        if (prev < n-1) solve(prev+1,n-1);
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
