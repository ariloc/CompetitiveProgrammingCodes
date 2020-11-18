// https://www.hackerrank.com/contests/simulacro-3-oia-2020/challenges/problem-1-overplanting
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

const int ADD = 10000;
const int MAXN = 2*(ADD+2);
const int MAXST = (1<<(32-__builtin_clz(MAXN)));

ii operator+ (const ii &a, const ii &b) {
    if (a.fst == b.fst) return {a.fst,a.snd+b.snd};
    return min(a,b);
}

ii ST[2*MAXST];
int lazy[2*MAXST];

void build() {
    forn(i,MAXST) ST[i+MAXST] = {0,1};
    dforsn(i,1,MAXST) ST[i] = ST[2*i] + ST[2*i+1];
}

void passLazy (int i) {
    ST[i].fst += lazy[i];
    if (2*i+1 < 2*MAXST) {
        lazy[2*i] += lazy[i];
        lazy[2*i+1] += lazy[i];
    }
    lazy[i] = 0;
}

void update(int i, int tl, int tr, int bl, int br, bool op) {
    passLazy(i);
    if (bl >= br) return;
    if (tl == bl && tr == br) {
        int delta = (op ? 1 : -1);
        lazy[i] += delta;
        passLazy(i);
    }
    else {
        int mid = (tl+tr)/2;
        update(2*i,tl,mid,bl,min(br,mid),op);
        update(2*i+1,mid,tr,max(bl,mid),br,op);
        ST[i] = ST[2*i]+ST[2*i+1];
    }
}

struct query {
    int y1,y2; // low,top
    bool op; // suma true, resta false
};

vector<query> entries[MAXN];

int overplanting(vector <int> x1, vector <int> y1, vector <int> x2, vector <int> y2) {
    build();
    int vSt = ST[1].snd;
    forn(i,x1.size()) {
        x1[i] += ADD; x2[i] += ADD;
        y1[i] += ADD; y2[i] += ADD;

        entries[x1[i]].pb({y2[i],y1[i],1});
        entries[x2[i]].pb({y2[i],y1[i],0});
    }
    int cnt = 0;
    forn(i,MAXN) {
        for (auto &k : entries[i])
            update(1,0,MAXST,k.y1,k.y2,k.op);

        if (!ST[1].fst) cnt += vSt-ST[1].snd;
        else cnt += vSt;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector <int> x1(N), y1(N), x2(N), y2(N);
    for(int i=0; i<N; i++)
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

    cout << overplanting(x1, y1, x2, y2) << endl;

    return 0;
}
