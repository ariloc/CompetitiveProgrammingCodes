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

const int MAXN = 2e5+2;

int cit[MAXN];
int lastDone[MAXN];
vector<ii> rangeUpd;

int main() {
    FAST_IO;

    int n; cin >> n;
    forn (i,n) cin >> cit[i];

    int q; cin >> q;
    forn (i,q) {
        int typ,p,x;
        cin >> typ;
        if (typ == 1) {
            cin >> p >> x;
            p--;
            cit[p] = x;
            lastDone[p] = i;
        }
        else {
            cin >> x;
            rangeUpd.push_back({x,i});
        }
    }

    int accum = -1;
    dforn (i,rangeUpd.size()) {
        accum = max(accum,rangeUpd[i].fst);
        rangeUpd[i].fst = accum;
    }

    forn (i,n) {
        int ind = lower_bound(all(rangeUpd),lastDone[i],[](const ii &a, const int &b){return a.snd < b;}) - rangeUpd.begin();
        //cerr << ind << ' ' << lastDone[i] << ' ';
        if (ind >= (int)(rangeUpd.size())) continue;
        if (rangeUpd[ind].fst > cit[i]) cit[i] = rangeUpd[ind].fst;
    }

    forn (i,n) cout << cit[i] << ' ';

    return 0;
}