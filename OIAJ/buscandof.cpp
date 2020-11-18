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

const ll INF = 3e18+5;

struct pt {
    ll x,y;
    pt(){};
    pt(ll x, ll y) : x(x),y(y){};

    pt operator- (const pt &o) const {return {x-o.x,y-o.y};}
    pt operator+ (const pt &o) const {return {x+o.x,y+o.y};}
    pt operator* (const ll &o) const {return {x*o,y*o};}
    ll operator* (const pt &o) const {return x*o.x + y*o.y;} // producto escalar
    ll operator% (const pt &o) const {return x*o.y - y*o.x;} // cross

    bool operator< (const pt &o) const {
        if (o.x == x) return y < o.y;
        return x < o.x;
    }
    bool operator!= (const pt &o) const {
        return (x != o.x || y != o.y);
    }
};

struct ln {
    pt a,ab; // point p in the line and pq line direction vector
    ln(){};
    ln(pt a, pt b) : a(a),ab(b-a){};

    bool sent (const pt &x) {return ((ab%(x-a)) >= 0);}
    bool onLine (const pt &x) {return (!(ab%(x-a)));} // si está en la línea, da 0
    /*long double proy(pt x) {
        if (!ab.len()) return INF;
        return (ab*(x-a))/ab.len(); // a x b / |a| -> proyección
    }*/

    bool operator< (const ln &o) const {
        if (ab != o.ab) return ab < o.ab;
        return a < o.a;
    }
};

int buscandof(int N, vector<int> x, vector<int> y)
{
    int maxi = 2;

    vector<ln> cand;
    forn(i,N) forn(j,N) {
        if (i == j) continue;
        pt a = {x[i],y[i]}, b = {x[j],y[j]};
        ln me = {a,b};
        cand.pb(me);

        pt chose = {INF,INF}; ll mini = -INF;
        forn(k,N) {
            pt act = {x[k],y[k]};
            if (!me.sent(act) && !(me.onLine(act))) continue;
            if (((me.ab)*(act-me.a)) > mini) {mini = ((me.ab)*(act-me.a)); chose = act;}
        }
        if (mini == -INF) continue;
        //cerr << "OKK" <<endl;
        pt perp = {me.ab.y*(-1),me.ab.x};
        //cerr << chose.x << ' ' << chose.y << ' ' << perp.x << ' ' << perp.y << "!!!!!!" << endl;
        ln toPush; toPush.a = chose; toPush.ab = perp;
        cand.pb(toPush);
    }
    for (auto &i : cand) {
        ln me = i;

        auto comp = [](const pair<ll,bool> &a, const pair<ll,bool> &b){if (a.fst == b.fst) return a.snd > b.snd; return a.fst > b.fst;};

        map<pair<ll,bool>,int,decltype(comp)> proys(comp);
        forn(k,N) {
            pt act = {x[k],y[k]};
            if (!me.sent(act) && !(me.onLine(act))) continue;
            ll actProy = me.ab*(act-me.a);
            if (me.onLine(act)) proys[{actProy,1}]++;
            else proys[{actProy,0}]++; // si no están en recta, vale para orden mayor

            //cerr << me.a.x << ' ' << me.a.y << ' ' << me.ab.x << ' ' << me.ab.y << ' ' << act.x << ' ' << act.y << ' ' << ' ' << (act-me.a).x << ' ' << (act-me.a).y << ' ' << proys[actProy] << ' ' << actProy << endl;

        }

        int maxi1 = 0, maxi2 = 0;
        int cntEnRecta = 0;
        for (auto &k : proys) { // recorremos al revés así revisamos desde aquellos más abajo
            if (k.fst.snd) {cntEnRecta++; maxi = max(maxi,cntEnRecta+maxi1); continue;}
            bool enh = false;
            if (k.snd > maxi1) {swap(maxi1,maxi2); maxi1 = k.snd; enh = true;}
            else if (k.snd > maxi2) {maxi2 = k.snd; enh = true;}
            if (enh) maxi = max(maxi,maxi1+maxi2+cntEnRecta);
        }

        //cerr << "OKK" << ' ' << a.x << ' ' << a.y << ' ' << b.x << ' ' << b.y << ' ' << sum << endl;
    }

    return maxi;
}
