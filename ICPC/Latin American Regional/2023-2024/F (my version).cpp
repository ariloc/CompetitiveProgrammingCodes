#include<bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int main() {
    FAST_IO;

    ll n; cin >> n;

    ll maxi = -1;
    for (int b = 2; b*(ll)b <= n; b++) {
        vi auxi;
        ll cur = n;
        while(cur) auxi.pb(cur%b), cur /= b;
        bool posib = true;
        int m = (int)auxi.size();
        forn(i,m+1/2) if (auxi[i] != auxi[m-i-1]) posib = false;
        if (posib) cout << b << ' ', maxi = max(maxi, (ll)b);
    }

    vector<ll> rta;
    for (int r = 1; r*(ll)r <= n; r++) if (!(n%r)) {
        ll b = n/r - 1;
        if (b*r+r != n || r >= b) break;
        if (b >= 2 && b > maxi) rta.pb(b);
    }

    if (rta.empty() && maxi == -1) cout << "*\n";
    else {
        dforn(i,rta.size()) cout << rta[i] << ' ';
        cout << '\n';
    }
    
    return 0;
}
