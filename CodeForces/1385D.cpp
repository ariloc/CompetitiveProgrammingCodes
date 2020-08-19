#include <bits/stdc++.h>

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

const int MAXN = 2e5+2;

int getCost(string &s, int l, int r, char c) {
    if (r-l <= 1) return (s[l] != c);

    int mid = (l+r)/2;

    int cnt1 = 0, cnt2 = 0;
    forsn (i,l,mid) if (s[i] != c) cnt1++;
    forsn (i,mid,r) if (s[i] != c) cnt2++;

    //cerr << s << ' ' << l << ' ' << r << ' ' << c << ' ' << cnt1 << ' ' << cnt2 << ' ' << mid << endl;

    return min(cnt1+getCost(s,mid,r,c+1),cnt2+getCost(s,l,mid,c+1));
}

int main() {
    FAST_IO;

    int t; cin >> t;

    forn(i,t) {
        int n; cin >> n;
        string s; cin >> s;

        cout << getCost(s,0,n,'a') << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!