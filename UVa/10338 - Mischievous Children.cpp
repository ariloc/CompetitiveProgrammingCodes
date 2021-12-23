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
typedef long double ld;

const int MAXF = 22;

ll fact[MAXF];

ll nCr (ll n, ll k) {
    return fact[n] / (fact[k] * fact[n-k]);
}

int main() {
    FAST_IO;

    fact[0] = 1;
    forsn(i,1,MAXF) fact[i] = fact[i-1] * i;

    int t; cin >> t;
    forn(o,t) {
        string s; cin >> s;

        map<char,int> lett;
        for (auto &i : s) lett[i]++;

        ll r = 1; int cnt = (int)s.size();
        for (auto &i : lett)
            r *= nCr(cnt,i.snd), cnt -= i.snd;
        
        cout << "Data set " << o+1 << ": " << r << '\n';
    }
    
    return 0;
}