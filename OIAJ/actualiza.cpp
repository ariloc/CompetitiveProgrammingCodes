#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int MAXN = 2e5+5;
const int MAXST = (1<<(32-__builtin_clz(MAXN)));
const int INF = 2e9;

struct STree {
    int mini,maxi;

    STree operator+ (const STree &o) const {
        return {min(mini,o.mini),max(maxi,o.maxi)};
    }
};

STree ST[2*MAXST];
int FT[2*MAXN],cnt_each[2*MAXN];
vi lst;
int N;

void update (int p, int v) {
    p += N; ST[p].mini = ST[p].maxi = v;
    while (p > 1) p /= 2, ST[p] = ST[2*p] + ST[2*p+1];
}

STree query (int i, int tl, int tr, int bl, int br) {
    if (tl >= br || tr <= bl) return {INF,-INF};
    if (tl >= bl && tr <= br) return ST[i];

    int mid = (tl+tr)/2;
    return query(2*i,tl,mid,bl,br) + query(2*i+1,mid,tr,bl,br);
}

void update_compression (int &x, vi &arr) {
    x = lower_bound(all(lst),x)-lst.begin()+2; // seguridad por FT
}

void setFT (int p, int v) {
    for (int i = p; i < 2*MAXN; i += i & -i)
        FT[i] += v;
}

int getFT (int p) {
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

void actualiza(vector<int> &hilera, vector<int> &t, vector<int> &L, vector<int> &R, vector<int> &K, vector<int> &diferencia, vector<int> &distintosMenorK) {
    int q = t.size(), n = hilera.size();
    N = (1<<(32-__builtin_clz(n)));

    forn(i,2*MAXST) ST[i] = {INF,-INF};
    forn(i,n) ST[i+N].mini = ST[i+N].maxi = hilera[i];
    dforsn(i,1,N) ST[i] = ST[2*i] + ST[2*i+1];

    forn(i,q) {
        if (t[i] == 1) update(L[i]-1,K[i]);
        else {
            STree minimax = query(1,0,N,L[i]-1,R[i]);
            //cerr << minimax.maxi << ' ' << minimax.mini << ' ' << L[i] << ' ' << R[i] << endl;
            diferencia.pb(minimax.maxi-minimax.mini);
        }
    }

    forn(i,n) lst.pb(hilera[i]);
    forn(i,q) if (t[i] == 1) lst.pb(K[i]);

    sort(all(lst));
    lst.erase(unique(all(lst)),lst.end());
    forn(i,n) update_compression(hilera[i],lst);
    forn(i,q) if (t[i] == 1) update_compression(K[i],lst);

    forn(i,n) {
        if (!cnt_each[hilera[i]]) setFT(hilera[i],1);
        cnt_each[hilera[i]]++;
    }

    forn(i,q) {
        if (t[i] == 2) {
            int ind = lower_bound(all(lst),K[i])-lst.begin()-1;
            distintosMenorK.pb(getFT(ind+2)); // seguridad FT
        }
        else {
            int v_old = hilera[L[i]-1], v_new = K[i];

            cnt_each[v_old]--;
            if (!cnt_each[v_old]) setFT(v_old,-1);

            if (!cnt_each[v_new]) setFT(v_new,1);
            cnt_each[v_new]++;

            hilera[L[i]-1] = v_new;
        }
    }
}
