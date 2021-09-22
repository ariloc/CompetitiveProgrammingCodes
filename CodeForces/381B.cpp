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

const int MAXN = 5001;

int cardCount[MAXN];

int main() {
    FAST_IO;

    int N; cin >> N;

    forn (i,N) {int x; cin >> x; cardCount[x]++;}

    int cnt = 0; vi rta;
    forn (i,MAXN)
        if (cardCount[i]) {rta.pb(i); cardCount[i]--; cnt++;}

    dforn (i,MAXN)
        if (cardCount[i] and rta.back() != i) {rta.pb(i); cardCount[i]--; cnt++;}

    cout << cnt << '\n';
    for (auto &i : rta) cout << i << ' ';

    return 0;
}