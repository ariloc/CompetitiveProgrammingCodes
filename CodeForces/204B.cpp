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

const int MAXN = 1e5+2;

ii cards[MAXN];
vector< pair<int,bool> > col;

int main() {
    FAST_IO;

    int N; cin >> N;

    forn (i,N) {
        int a,b; cin >> a >> b;
        col.push_back({a,true});
        if (a != b) col.push_back({b,false});
    }

    sort(all(col));
    int half = (N+1)/2;

    int best = -1, upside = 0, cnt = 0;
    forn (i,col.size()) {
        if (i-1 >= 0 and col[i].fst != col[i-1].fst) {
            if (cnt >= half and upside > best) best = upside;
            cnt = 0;
            upside = 0;
        }
        cnt++; upside += col[i].snd;
    }
    if (cnt >= half and upside > best) best = upside;

    if (best == -1) cout << -1;
    else cout << (half-best < 0 ? 0 : half-best);

    return 0;
}