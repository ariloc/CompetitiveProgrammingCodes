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

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        int l,r,d,u; cin >> l >> r >> d >> u;
        int x,y,x1,x2,y1,y2; cin >> x >> y >> x1 >> y1 >> x2 >> y2;

        bool posib = true;
        int X = r-l, Y = u-d;

        if (x+X > x2 or x+X < x1) posib = false;
        if (!X and l and x+1 > x2 and x-1 < x1) posib = false;

        if (y+Y > y2 or y+Y < y1) posib = false;
        if (!Y and u and y+1 > y2 and y-1 < y1) posib = false;

        if (posib) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}