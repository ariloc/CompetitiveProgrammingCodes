#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define snd second
#define fst first
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

int const MOD = 1e6+3;

int binExp(int a, int k) {
    int r = 1;
    while (k) {
        if (k&1) r = (r*(ll)a)%MOD;
        a = (a*(ll)a)%MOD;
        k >>= 1;
    }
    return r;
}

typedef int tp;
template<class T=tp>
struct poly {
    vector<T> c;
    T& operator[](int k){return c[k];}
    poly(vector<T>& c):c(c){}
    poly(initializer_list<T> c):c(c){}
    poly(int k):c(k){}
    poly(){}
    poly operator+(poly<T> o){
        int m=c.size(),n=o.c.size();
        poly res(max(m,n));
        forn(i,m)res[i]=(res[i]+c[i])%MOD;
        forn(i,n)res[i]=(res[i]+o.c[i])%MOD;
        return res;
    }
    poly operator*(tp k){
        poly res(c.size());
        forn(i,c.size())res[i]=(c[i]*(ll)k)%MOD;
        return res;
    }
    poly operator*(poly o){
        int m=c.size(),n=o.c.size();
        poly res(m+n-1);
        forn(i,m)forn(j,n)res[i+j]=(res[i+j]+(c[i]*(ll)o.c[j])%MOD)%MOD;
        return res;
    }
    T operator()(tp v){
        T sum(0);
        for(int i=c.size()-1;i>=0;--i)sum=((sum*(ll)v)%MOD+c[i])%MOD;
        return sum;
    }
};

pair<poly<>,tp> ruffini(poly<> p, tp r) {
    int n=p.c.size()-1;
    vector<tp> b(n);
    b[n-1]=p[n];
    for(int k=n-2;k>=0;--k)b[k]=(p[k+1]+(r*(ll)b[k+1])%MOD)%MOD;
    return {poly<>(b),(p[0]+(r*(ll)b[0])%MOD)%MOD};
}

poly<> interpolate(vector<tp> x, vector<tp> y) {
    poly<> q={1},S={0};
    for (tp a:x)q=poly<>({(-a+MOD)%MOD,1})*q;
    forn(i,x.size()){
        poly<> Li=ruffini(q,x[i]).fst;
        Li = Li * binExp(Li(x[i]), MOD-2);
        S=S+Li*y[i];
    }
    return S;
}

int main() {
    FAST_IO;

    vector<tp> xs,ys;
    forn(i,11) {
        cout << "? " << i << endl;
        int auxi; cin >> auxi;
        xs.pb(i), ys.pb(auxi);

        auto p = interpolate(xs,ys);

        forn(x,MOD) {
            if (!p(x)) {
                cout << "? " << x << endl;
                int aux2; cin >> aux2;
                if (!aux2) {
                    cout << "! " << x << endl;
                    return 0;
                }
                else {
                    break;
                }
            }
        }
    }

    cout << "! -1" << endl;

    return 0;
}
