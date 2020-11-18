// https://www.hackerrank.com/contests/simulacro-3-oia-2020/challenges/problem-3-symmetry/problem
#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

struct pt {
    int x,y;

    pt operator- (const pt &o) const {return {x-o.x,y-o.y};}
    void normalize() {
        int dcm = __gcd((int)x,(int)y);
        x /= dcm; y /= dcm;
        if (x < 0 || (!x && y < 0)) x=-x, y=-y;
    }

    bool operator< (const pt &o) const {
        if (o.x == x) return y < o.y;
        return x < o.x;
    }

    bool operator== (const pt &o) const {
        return (o.x == x && o.y == y);
    }
};

struct ln {
    pt ab; int c; // ax+by+c = 0, n vector = (a,b) es perp a la recta
    ln(){};
    ln(pt p0, pt p, bool literal = false) {
        if (literal) ab = p0;
        else { // supongo que u = (a,b) paralelo a la recta
            pt v = p-p0;
            v = {-v.y,v.x}; // saco el vector n perpendicular
            ab = v;
        }
        ((*this).ab).normalize();
        c = -(ab.y*p.y)-(ab.x*p.x); // c = -b.y-a.x
    };

    bool onLine (pt p) {
        return (!(ab.x*p.x + ab.y*p.y + c)); // si ax + by + c == 0, cumple?
    }

    bool operator< (const ln &o) const {
        if (c == o.c) return ab < o.ab;
        return c < o.c;
    }

    bool operator== (const ln &o) const {
        return (ab == o.ab && c == o.c);
    }
};

pt midPoint (pt a, pt b) {
    return (pt){(a.x+b.x)/2,(a.y+b.y)/2};
}

int symmetry(vector <int> X, vector <int> Y) {
    vector<pt> lst;
    forn(i,X.size()) lst.pb({X[i]*2,Y[i]*2}); // duplico coords así no me dan los ptos medios con coma

    set<ln> rectas,rectas2,active; // rectas activas
    forsn(i,1,lst.size()) { // saco las rectas iniciales
        pt mid = midPoint(lst[0],lst[i]), vec = lst[i]-lst[0];
        ln tmp = ln(vec,mid,true); // vec es perpendicular a la recta perpendicular que busco, así que lo mando nomás. Tiene que pasar por mid.
        rectas.insert(tmp);
    }

    forn(i,lst.size()) { // saco las rectas correpsondientes al segundo punto
        if (i == 1) continue; // no hago recta conmigo mismo
        pt mid = midPoint(lst[1],lst[i]), vec = lst[i]-lst[1];
        ln tmp = ln(vec,mid,true);
        rectas2.insert(tmp);
    }
    for (auto &i : rectas2) {
        ln me = i;
        if (rectas.count(i)) active.insert(i); // verifico que rectas están compartidas en ambos conjuntos
        else if (me.onLine(lst[0])) active.insert(i); // verifico qué rectas hay en el segundo que no están en el primero y son válidas
    }
    for (auto &i : rectas) {
        ln me = i;
        if (!rectas2.count(i) && me.onLine(lst[1])) active.insert(i); // verifico qué rectas están en el primero y no en el segundo, y si son válidas
    }

    ln rectaPts = ln(lst[0],lst[1]); // recta formada por los pts anteriores
    bool rectaValid = true; // si la recta anterior cumple, es decir, que todos los puntos pasados están sobre ella
    // ahora si podemos empezar
    forsn(i,2,lst.size()) {
        set<ln> tmpLn;
        forn(j,lst.size()) {
            if (i == j) continue;
            pt mid = midPoint(lst[i],lst[j]), vec = lst[j]-lst[i];
            ln tmp = ln(vec,mid,true);
            tmpLn.insert(tmp);
        }
        for (auto &j : tmpLn) // rectas nuevas tienen que el resto de puntos pertenecer, implica es igual a rectaPts si es válida aún
            if (!active.count(j) && rectaValid && j == rectaPts) {active.insert(j); break;} // es la misma recta, una vez basta
        vector<ln> toDel;
        for (auto &j : active) {
            ln me = j;
            if (!tmpLn.count(j) && !me.onLine(lst[i])) toDel.pb(j);
        }
        for (auto &j : toDel) active.erase(j);
        if (!rectaPts.onLine(lst[i])) rectaValid = false; // invalido la recta de los anteriores corresp.
    }
    if (rectaValid) active.insert(rectaPts);

    return (int)active.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector <int> X(N), Y(N);
    for(int i=0; i<N; i++)
        cin >> X[i] >> Y[i];

    cout << symmetry(X, Y) << endl;

    return 0;
}
