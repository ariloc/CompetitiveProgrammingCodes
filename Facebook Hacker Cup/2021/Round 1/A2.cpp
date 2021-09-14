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

const int MAXN = 8e5+5;
const int INF = 1e9+5;
const int MOD = 1e9+7;

int main() {
    FAST_IO;

    freopen("weak_typing_chapter_2_input.txt","r",stdin);
    freopen("salida.txt","w",stdout);

    int t; cin >> t;
    forn(o,t) {
        int n; cin >> n;
        string s; cin >> s;

        char last = 'F'; int ind = -1;
        ll r = 0;
        forn(i,n) if (s[i] == 'X' || s[i] == 'O') {ind = i, last = s[i]; break;}
        forsn(i,ind+1,n) {
            if (s[i] == 'X' || s[i] == 'O') {
                if (s[i] != last) r = (r + (ind+1)*(ll)(n-i)) % MOD;
                ind = i, last = s[i];
            }
        }

        cout << "Case #" << o+1 << ": " << r << '\n';
    }

    return 0;
}