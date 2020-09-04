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

const int MAXST = (1<<17)+5;

int ST[2*MAXST];
int N;

void build(int i, int tl, int tr, bool op) {
    if (tr-tl > 1) {
        int mid = (tl+tr)/2;
        build(2*i,tl,mid,!op);
        build(2*i+1,mid,tr,!op);
        if (op) ST[i] = (ST[2*i]|ST[2*i+1]);
        else ST[i] = (ST[2*i]^ST[2*i+1]);
    }
}

void update(int i, int tl, int tr, int pos, int val, bool op) {
    if (tr <= tl) return;
    if (tr-tl == 1) ST[i] = val;
    else {
        int mid = (tl+tr)/2;
        if (pos >= mid) update(2*i+1,mid,tr,pos,val,!op);
        else update(2*i,tl,mid,pos,val,!op);

        if (op) ST[i] = (ST[2*i]|ST[2*i+1]);
        else ST[i] = (ST[2*i]^ST[2*i+1]);
    }
}

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    N = (1<<n);
    forn(i,N) cin >> ST[i+N];
    build(1,0,N,(n&1)); // si es impar soy OR, else XOR
    cerr << ST[1] << endl;

    forn(i,m) {
        int p,b; cin >> p >> b;
        update(1,0,N,p-1,b,(n&1));
        cout << ST[1] << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
