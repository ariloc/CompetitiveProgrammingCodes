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

int let[MAXA];

int main() {
    FAST_IO;
    
    string s; cin >> s;
    int k; cin >> k;

    int maxi = 0;
    forn(i,MAXA) {
        cin >> let[i];
        maxi = max(maxi,let[i]);
    }

    ll acc = 0;
    forn(i,s.size()) acc += let[s[i]-'a'] * (ll)(i+1);
    forn(i,k) acc += maxi * (ll)(i+(int)s.size()+1);

    printf("%lld",acc);

    return 0;
}