#include <algorithm>
#include <bits/stdc++.h>
 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);
 
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

int const MAXN = 1e5+5;
int const MAXD = 4e5+5;

struct rect {
    int u,d;
};

struct oper {
    bool query; // 0 -> set, 1 -> query
    int u,d;
    int v;
};

void fs (int &x) {
    x = 0;
    char c = getchar();
    if (c > '9' || c < '0') c = getchar();
    for (; c >= '0' && c <= '9'; c = getchar())
        x = 10*x + c-'0';
}

unordered_map<int,int> FT[MAXD];
vector<rect> images;
vector<pair<int,vector<oper>>> que;
vector<ii> rta;

void setFT (int y, int x, int v) {
    y += 2, x += 2;
    for (int i = y; i < MAXD; i += i & -i)
        for (int j = x; j < MAXD; j += j & -j)
            FT[i][j] += v;
}

int getFT (int y, int x) {
    y += 2, x += 2;
    int r = 0;
    for (int i = y; i; i -= i & -i)
        for (int j = x; j; j -= j & -j)
            r += FT[i][j];
    return r;
}

int desp = 0;

int main() {
    int n,q,h1,h2,w; fs(n); fs(q); fs(h1); fs(h2); fs(w);
    forn(i,n) {
        int u,d,l,r; fs(u); fs(d); fs(l); fs(r);
        --d;
        images.pb({u,d});
    
        vector<oper> vecaux;
        vecaux.pb({false,u,h2-d,1});
        que.pb({-1,vecaux});
    }

    forn(i,q) {
        char typ = getchar();
        while(typ != 'A' && typ != 'D' && typ != 'M') typ = getchar();
        if (typ == 'A') {
            int j,u,d,l,r; fs(j); fs(u); fs(d); fs(l); fs(r);
            --d, --j;
            images.pb({u,d});

            vector<oper> vecaux;
            vecaux.pb({false,u,h2-d,1});
            que.pb({(int)rta.size(),vecaux});

            int aux; 
            if (u <= desp+h1-1 && d >= desp) aux = 1;
            else aux = 0;
            rta.pb({aux,0});
        }
        else if (typ == 'D') {
            int j; fs(j); --j;
            rect aux = images[j];

            vector<oper> vecaux;
            vecaux.pb({false,aux.u,h2-aux.d,-1});
            que.pb({(int)rta.size(),vecaux});
            
            int auxi;
            if (aux.u <= desp+h1-1 && aux.d >= desp) auxi = 1;
            else auxi = 0;
            rta.pb({0,auxi});
        }
        else {
            int x; fs(x);

            vector<oper> vecaux;

            if (x > desp) {
                int u1 = desp+h1, u2 = x+h1-1;
                int d1, d2 = h2-x;
                vecaux.pb({true,u2,d2,-1});
                vecaux.pb({true,u1-1,d2,-1});

                u1 = 0, u2 = desp+h1-1;
                d1 = h2-(x-1), d2 = h2-desp;
                vecaux.pb({true,u2,d2,-1});
                vecaux.pb({true,u2,d1-1,-1});
            }
            else {
                int u1 = 0, u2 = x+h1-1;
                int d1 = h2-(desp-1), d2 = h2-x;
                vecaux.pb({true,u2,d2,-1});
                vecaux.pb({true,u2,d1-1,-1});

                u1 = x+h1, u2 = desp+h1-1;
                d2 = h2-desp;
                vecaux.pb({true,u2,d2,-1});
                vecaux.pb({true,u1-1,d2,-1});
            }

            que.pb({(int)rta.size(),vecaux});
            rta.pb({-1,-1});

            desp = x;
        }
    }

    vi pts;
    for (auto &i : que) {
        for (auto &j : i.snd) {
            pts.pb(j.u);
            pts.pb(j.d);
        }
    }
    sort(all(pts));
    pts.erase(unique(all(pts)),pts.end());

    for (auto &i : que) {
        for (auto &j : i.snd) {
            j.u = lower_bound(all(pts),j.u)-pts.begin();
            j.d = lower_bound(all(pts),j.d)-pts.begin();
        }
    }

    for (auto &i : que) {
        if ((int)i.snd.size() == 1) {
            auto e = i.snd.back();
            setFT(e.u,e.d,e.v);
        }
        else {
            oper a = i.snd[0], b = i.snd[1], c = i.snd[2], d = i.snd[3];
            rta[i.fst] = {getFT(a.u,a.d)-getFT(b.u,b.d),getFT(c.u,c.d)-getFT(d.u,d.d)};
        }
    }

    for (auto &i : rta) printf("%d %d\n",i.fst,i.snd);

    return 0;
}
