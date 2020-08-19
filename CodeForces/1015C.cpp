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

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;

    vector<ii> compressRate;
    ll bytes = 0;
    forn (i,n) {
        int a,b; cin >> a >> b;
        compressRate.pb({a-b,b});
        bytes += a;
    }

    sort(all(compressRate));

    int compressed = 0;
    dforn (i,compressRate.size()) {
        if (bytes <= m) break;
        bytes -= (compressRate[i].fst+compressRate[i].snd);
        bytes += compressRate[i].snd;
        compressed++;
    }

    cout << (bytes <= m ? compressed : -1);

    return 0;
}