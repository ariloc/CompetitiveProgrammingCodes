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

int const MAXN = 2e5+5;
ll const INF = 1e13;

int n,b,x;
int pou[MAXN];

bool check(ll mid) {
    ll myb = b;
    forn(i,n) {
        myb -= (pou[i]*(ll)mid + x - 1)/x;
        if (myb < 0) return false;
    }
    return true;
}

int main() {
    FAST_IO;

    cin >> n >> b >> x;

    forn(i,n) cin >> pou[i];

    ll lo = 0, hi = INF;
    while (hi-lo > 1) {
        ll mid = (hi+lo)/2LL;
        if (check(mid)) lo = mid;
        else hi = mid;
    }

    cout << lo << '\n';

    return 0;
}
