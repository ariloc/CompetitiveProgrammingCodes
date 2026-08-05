#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define snd second
#define fst first
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

int const MAXN = 5e5+5;
int const MAXB = 62;

ll basis[MAXB];
int szb = 0;

bool insvector(ll v){
    forn(d,MAXB) {
        if (!(v&(1LL<<d))) continue;

        if (!basis[d]) {
            szb++;
            basis[d] = v;
            return true;
        }

        v ^= basis[d];
    }
    return false;
}

int main() {
    FAST_IO;

    int n; cin >> n;

    ll sum = 0;
    forn(i,n) {
        ll a,b; cin >> a >> b;
        ll cur = a^b;
        sum ^= b;
        insvector(cur);
    }
    int dif = n-szb;

    if (!insvector(sum)) // exists solution for zero
        cout << (1LL<<szb)-1 << "/" << (1LL<<szb) << '\n';
    else cout << "1/1\n";

    return 0;
}
