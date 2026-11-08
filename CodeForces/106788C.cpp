#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)c.size()
#define FAST_IO ios::sync_with_stdio(false);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

int main() {
    FAST_IO;

    int xs,ys; cin >> xs >> ys;
    int xt,yt; cin >> xt >> yt;


    int dx = xt - xs, dy = yt - ys;
    int mini = min(abs(dx),abs(dy));

    if (dx < 0 && dy < 0) cout << "SW\n";
    else if (dx < 0 && dy > 0) cout << "NW\n";
    else if (dx > 0 && dy < 0) cout << "SE\n";
    else if (dx > 0 && dy > 0) cout << "NE\n";

    if (dx < 0) dx += mini; else dx -= mini;
    if (dy < 0) dy += mini; else dy -= mini;

    if (!dx && !dy) return 0;

    if (dx < 0) cout << "W\n";
    else if (dx > 0) cout << "E\n";
    else if (dy < 0) cout << "S\n";
    else if (dy > 0) cout << "N\n";

    return 0;
}
