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

int const MAXN = 3e5+5;

int mini[MAXN], maxi[MAXN];
int lastm[MAXN], arr[MAXN];
bitset<MAXN> seen;
int FT[MAXN];
map<int,vi> ap;

void setFT(int p, int v) {
    p += 2;
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

int getFT(int p) {
    p += 2;
    int ret = 0;
    for (int i = p; i; i -= i & -i)
        ret += FT[i];
    return ret;
}

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,n) mini[i] = maxi[i] = i, lastm[i] = -1;

    forn(i,m) cin >> arr[i], --arr[i];

    forn(i,m) {
        if (!seen[arr[i]]) {
            seen[arr[i]] = true;
            int prev = getFT(n)-getFT(arr[i]);
            maxi[arr[i]] = max(maxi[arr[i]], arr[i]+prev);
            setFT(arr[i],1);
        }
    }

    forn(i,n) if (!seen[i]) {
        maxi[i] = max(maxi[i], i+getFT(n)-getFT(i));
    }

    forn(i,MAXN) FT[i] = 0;

    vector<pair<ii,int>> queries; // [a,b)
    forn(i,m) {
        int x = arr[i];
        if (lastm[x] == -1) {
            mini[x] = 0;
        }
        else {
            queries.pb({{lastm[x]+1,i},x});
        }
        lastm[x] = i;
    }
    forn(i,n) {
        if (lastm[i] != -1) queries.pb({{lastm[i]+1,m},i});
    }

    sort(all(queries));

    dforn(i,m) {
        auto it = ap.find(arr[i]);
        if (it == ap.end()) ap[arr[i]] = {};
        ap[arr[i]].pb(i);
    }

    for (auto &i : ap) {
        setFT(i.snd.back(),1);
    }

    int prv = 0;
    for (auto &i : queries) {
        while (prv < i.fst.fst && prv < m) {
            //cerr  << prv << '!' << endl;
            if (getFT(prv)-getFT(prv-1)) {
                setFT(prv,-1);
                auto &vec = ap[arr[prv]];
                vec.pop_back();
                if (!vec.empty()) {
                    setFT(vec.back(),1);
                }
            }
            prv++;
        }
        int val = getFT(i.fst.snd-1)-getFT(i.fst.fst-1);
        maxi[i.snd] = max(maxi[i.snd], val);
        //cerr << val << ' ' << prv << ' ' << i.fst.fst << ' ' << i.fst.snd << ' ' << i.snd << endl;
    }

    forn(i,n) cout << mini[i]+1 << ' ' << maxi[i]+1 << '\n';

    return 0;
}
