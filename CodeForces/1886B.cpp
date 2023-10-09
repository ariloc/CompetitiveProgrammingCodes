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

ld const EPS = 1e-8;
ld const INF = 1e4;

struct pt {
    ld x,y;

    pt(){}
    pt(ld a, ld b) : x(a),y(b){}
    pt operator- (const pt &o) const { return pt(x-o.x,y-o.y);}
    ld sqr() {
        return sqrt(x*x + y*y);
    }
};

bool inCircle (pt circ, ld r, pt p) {
    p.x -= circ.x, p.y -= circ.y;
    if (p.sqr()-r <= EPS) return true;
    return false;
}

bool posib (pt p, pt a, pt b, ld mid) {
    if (inCircle(a,mid,p) && inCircle(a,mid,pt(0,0))) return true;
    if (inCircle(b,mid,p) && inCircle(b,mid,pt(0,0))) return true;
    if (inCircle(a,mid,p) && inCircle(b,mid,pt(0,0)) && 
            (b-a).sqr()-2*mid <= EPS) return true;
    if (inCircle(b,mid,p) && inCircle(a,mid,pt(0,0)) && 
            (b-a).sqr()-2*mid <= EPS) return true;
    return false;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        pt p,a,b;
        cin >> p.x >> p.y;
        cin >> a.x >> a.y;
        cin >> b.x >> b.y;
        
        ld low = 0, high = INF;
        while (high - low > EPS) {
            ld mid = (high+low)/2;
            if (posib(p,a,b,mid)) high = mid;
            else low = mid;
        }

        cout << fixed << setprecision(15) << high << '\n';
    }

     return 0;
}
