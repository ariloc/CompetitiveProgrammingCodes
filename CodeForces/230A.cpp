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

    vector<ii> drag;
    int s,n; cin >> s >> n;
    forn(i,n) {
        int x,y; cin >> x >> y;
        drag.pb({x,-y});
    }
    sort(all(drag));

    bool posib = true;
    forn(i,n) {
        if (s <= drag[i].fst)
            posib = false;
        s += -drag[i].snd;
    }

    cout << (posib ? "YES" : "NO");

    return 0;
}
