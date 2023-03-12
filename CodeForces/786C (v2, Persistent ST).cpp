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

const int MAXN = 1e5+5;
const int MAXB = 1e7;

struct mon {
    int l,r,sum;

    mon(){l = r = -1; sum = 0;}
};

int arr[MAXN], aparic[MAXN], nxt[MAXN], n;
vector<mon> bag;

vi versions = {-1};

int newNode (int i) {
    bag.pb(i == -1 ? mon() : bag[i]);
    return (int)bag.size() - 1;
}

int update (int i, int p, int v, int tl = 0, int tr = MAXN) {
    i = newNode(i);
    if (tr-tl <= 1) {
        bag[i].sum = v;
        return i;
    }

    int mid = (tl+tr)/2;
    if (p >= mid) bag[i].r = update(bag[i].r, p, v, mid, tr);
    else bag[i].l = update(bag[i].l, p, v, tl, mid);

    bag[i].sum = (bag[i].l == -1 ? 0 : bag[bag[i].l].sum) + (bag[i].r == -1 ? 0 : bag[bag[i].r].sum);

    return i;
}

int query (int i, int v, int acc = 0, int tl = 0, int tr = MAXN) {
    if (i == -1) return 0;
    if (tr-tl <= 1) return tl;

    int mid = (tl+tr)/2;

    int pref = bag[i].l == -1 ? 0 : bag[bag[i].l].sum;
    if (acc+pref < v) return bag[i].r == -1 ? -1 : query(bag[i].r, v, acc+pref, mid, tr);
    return bag[i].l == -1 ? -1 : query(bag[i].l, v, acc, tl, mid);
}

int main() {
    scanf("%d",&n);
    forn(i,n) scanf("%d",&arr[i]);

    bag.reserve(MAXB);

    forn(i,MAXN) aparic[i] = nxt[i] = -1;
    forn(i,n) {
        if (aparic[arr[i]] == -1) {
            int aux = update(versions.back(), i, 1);
            versions.pop_back();
            versions.pb(aux);
        }
        else nxt[aparic[arr[i]]] = i;
        aparic[arr[i]] = i;
    }

    forn(i,n-1) {
        versions.pb(update(versions.back(), i, 0));
        if (nxt[i] == -1) continue;
        versions.back() = update(versions.back(), nxt[i], 1);
    }

    forn(i,n) {
        int k = i+1;
        int ind = 0, rta = 0;
        while (ind != -1) {
            rta++;
            ind = query(versions[ind], k+1);
        }
        printf("%d ",rta);
    }

    return 0;
}
