#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

struct punto {
    int x,y;
};

struct rectangulo {
    punto a,b;
};

int main() {
    FAST_IO;
    freopen("maniobra.in","r",stdin);
    freopen("maniobra.out","w",stdout);

    rectangulo a,b,c;
    cin >> a.a.y >> a.a.x >> a.b.y >> a.b.x;
    cin >> b.a.y >> b.a.x >> b.b.y >> b.b.x;

    if (a.a.x > a.b.x) swap(a.a.x,a.b.x);
    if (a.a.y > a.b.y) swap(a.a.y,a.b.y);
    if (b.a.x > b.b.x) swap(b.a.x,b.b.x);
    if (b.a.y > b.b.y) swap(b.a.y,b.b.y);

    c.a.x = max(a.a.x,b.a.x);
    c.a.y = max(a.a.y,b.a.y);
    c.b.x = min(a.b.x,b.b.x);
    c.b.y = min(a.b.y,b.b.y);

    int longX = abs(c.a.x-c.b.x)+1, longY = abs(c.a.y-c.b.y)+1;
    if (c.a.x > c.b.x or c.a.y > c.b.y) cout << 0;
    else cout << longX*longY;

    return 0;
}
