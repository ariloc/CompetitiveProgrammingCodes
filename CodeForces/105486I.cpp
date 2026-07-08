#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 2e5+5;
int const MAXST = 1<<(32-__builtin_clz(MAXN));

int arr[MAXN], spf[MAXN];
bitset<MAXN> done;

void criba() {
    forn(i,MAXN) spf[i] = i;
    done[0] = done[1] = true;
    for (int i = 4; i < MAXN; i += 2) done[i] = true, spf[i] = 2;
    for (int i = 3; i*i <= MAXN; i += 2)
        if (!done[i])
            for (int j = i+i; j < MAXN; j += i) {
                if (!done[j]) {
                    done[j] = true;
                    spf[j] = i;
                }
            }
}

struct mon {
    int v,cnt;
    mon(){v = -1; cnt = 0;}
    mon(int x, int c) : v(x),cnt(c){}

    mon operator+(const mon &o) const {
        if (v == -1) return o;
        if (o.v == -1) return *this;
        return mon(__gcd(v,o.v),-1);
    }
};

mon ST[2*MAXST];
int N;
set<int> cuts;
int n,q;

void update(int p, int v) {
    p += N;
    if (v == -1) {
        ST[p].cnt--;
        if (!ST[p].cnt) ST[p].v = -1;
    }
    else {
        ST[p].v = v;
        ST[p].cnt++;
    }
    while (p > 1) p /= 2, ST[p] = ST[2*p] + ST[2*p+1];
}

void add(int len) {
    update(len,len);
}

void del(int len) {
    update(len,-1);
}

map<int,int> fact(int x) {
    map<int,int> f;
    while (x > 1) {
        f[spf[x]]++;
        x /= spf[x];
    }
    return f;
}

void printposib() {
    mon val = ST[1];
    if (val.v == -1) {
        cout << n << '\n';
        return;
    }
    map<int,int> f = fact(val.v);
    ll divs = 1;
    for (auto &i : f)
        divs *= (i.snd+1);
    cout << divs << '\n';
}

int main() {
    FAST_IO;

    criba();

    int t; cin >> t;
    forn(_,t) {
        cin >> n >> q;
        forn(i,n) cin >> arr[i];

        N = 1<<(32-__builtin_clz(n));
        forn(i,2*N+5) ST[i] = mon();
        cuts.clear();

        int prv = 0;
        cuts.insert(0);
        forsn(i,1,n) {
            if (arr[i] < arr[i-1]) {
                add(i-prv);
                cuts.insert(i); 
                prv = i;
            }
        }

        printposib();

        forn(i,q) {
            int pos,v; cin >> pos >> v; --pos;
            vi toCheck = {pos};
            if (pos < n-1) toCheck.pb(pos+1);

            arr[pos] = v;

            for (auto &p : toCheck) {
                if (p && arr[p] < arr[p-1] && !cuts.count(p)) {
                    auto nxtit = cuts.upper_bound(p);
                    auto prvit = prev(nxtit);
                    if (nxtit != cuts.end()) {
                        del(*nxtit-*prvit);
                        add(*nxtit-p);
                    }
                    add(p-*prvit);
                    cuts.insert(p);
                }
                if (p && arr[p] >= arr[p-1] && cuts.count(p)) {
                    auto nxtit = cuts.find(p);
                    auto prvit = prev(nxtit);
                    nxtit = next(nxtit);
                    del(p-*prvit);
                    if (nxtit != cuts.end()) {
                        del(*nxtit-p);
                        add(*nxtit-*prvit);
                    }
                    cuts.erase(p);
                }
            }

            printposib();
        }
    }

    return 0;
}
