#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 2e5+10;
const ll INF = 1e18;

int chips[MAXN];
bitset<MAXN+1> done;

int N;

ll getAns (int x) {
    ll r = 0;
    for (int i = x; i <= MAXN; i += x) {
        done[i] = true;
        int l = lower_bound(chips,chips+N,i) - chips;
        int ri = lower_bound(chips,chips+N,i+x) - chips;
        r += (ri-l)*(ll)i;
    }
    return r;
}

int main() {
    FAST_IO;

    cin >> N;

    forn (i,N) cin >> chips[i];
    sort(chips,chips+N);

    ll rta = -INF;
    forn (i,N)
        if (!done[chips[i]])
            rta = max(rta,getAns(chips[i]));


    cout << rta;

    return 0;
}