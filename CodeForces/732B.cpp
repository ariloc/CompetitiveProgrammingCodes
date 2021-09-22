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

const int MAXN = 502;
const int INF = 1e9+2;

int aff[MAXN], cnt = 0;

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;

    forn (i,n) cin >> aff[i];

    forsn (i,1,n) {
        int calc = INF;
        calc = k-(aff[i-1]+aff[i]);
        if (calc < 0) calc = 0;
        aff[i] += calc;
        cnt += calc;
    }

    cout << cnt << '\n';
    forn (i,n) cout << aff[i] << ' ';

    return 0;
}