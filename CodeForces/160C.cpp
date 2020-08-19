#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

vector< pair<ll,ll> > num;
const int INF = 1e9+5;

int main() {
    FAST_IO;

    ll n,k;
    cin >> n >> k;

    forn (i,n) {
        ll x;
        cin >> x;
        num.push_back({x,1});
    }
    sort(all(num));
    ll ind = 0;
    vi toCh;
    forsn (i,1,num.size()) {
        if (num[i].fst != num[i-1].fst) ind = i;
        else {num[ind].snd++; toCh.push_back(i);}
    }
    for (auto &i : toCh) num[i].fst = -INF;
    sort(all(num));

    num.erase(unique(all(num)),num.end());
    if (num[0].fst == -INF) num.erase(num.begin());

    ll primN = -1, segN = -1;
    forn (i,num.size()) {
        ll kBef = k;
        k -= (num[i].snd*n);
        primN = i;
        if (k <= 0) {k = kBef; break;}
    }
    forn (i,num.size()) {
        k -= (num[primN].snd*num[i].snd);
        segN = i;
        if (k <= 0) break;
    }

    cout << num[primN].fst << ' ' << num[segN].fst;

    return 0;
}