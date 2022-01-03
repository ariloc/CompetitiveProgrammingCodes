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

const int MAXN = 105;

bool canL[MAXN], canR[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        string s; cin >> s;

        forn(i,MAXN) canL[i] = canR[i] = 0;

        int n = (int)s.size();
        canL[0] = canR[n-1] = 1;
        forsn(i,1,n) {
            if (s[i] == s[i-1] && s[i] == '1') break;
            canL[i] = true;
        }
        dforn(i,n-1) {
            if (s[i] == s[i+1] && s[i] == '0') break;
            canR[i] = true;
        }
        bool posib = false;
        forn(i,n-1)
            if (canL[i] && canR[i+1] && 
                (s[i] == s[i+1] || s[i] == '0')) posib = true;
        posib |= (canL[n-1]), posib |= canR[0];

        printf("%s\n",(posib ? "YES" : "NO"));
    }

    return 0;
}