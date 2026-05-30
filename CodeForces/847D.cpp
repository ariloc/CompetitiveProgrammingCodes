#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= 0; i--)
#define forsn(i,s,n) for(int i = 0; i < int(n); i++)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 2e5+5;

vi pts;
int times[MAXN];
int FT[MAXN];

void setFT(int p, int v) {
    p += 2;
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

int getFT(int p) {
    p += 2;
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

int main() {
    int n,t; cin >> n >> t;

    forn(i,n) cin >> times[i];

    forn(i,n) pts.pb(times[i]-i-1);

    sort(all(pts));
    pts.erase(unique(all(pts)),pts.end());

    int maxi = 0;
    forn(i,n) {
        int reach = max(times[i],i+1);
        if (reach >= t) continue;

        int marg = (t-1) - (i+1);
        int auxi = upper_bound(all(pts),marg)-pts.begin()-1;
        maxi = max(maxi, getFT(auxi)+1);
        
        int val = times[i]-i-1;
        auxi = lower_bound(all(pts),val)-pts.begin();
        setFT(auxi, 1);
    }

    cout << maxi << '\n';
    
    return 0;
}
