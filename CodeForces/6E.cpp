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

ii books[MAXN];

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;

    forn (i,n) {cin >> books[i].fst; books[i].snd = i+1;}

    int j = 0;
    int difBst = 0;
    multiset<int> minMax; minMax.insert(books[0].fst);
    vector<ii> trueP;

    forn (i,n) {
        while (j < n and (*prev(minMax.end())-*minMax.begin()) <= k) {
            j++;
            minMax.insert(books[j].fst);
        }

        if (difBst < j-i) {
            difBst = j-i;
            trueP.clear();
        }

        if (j-i == difBst) trueP.pb({i,j-1});

        minMax.erase(minMax.find(books[i].fst));
        if (j >= n) break;
    }

    cout << difBst << ' ';

    cout << trueP.size() << '\n';
    for (auto &i : trueP) cout << i.fst+1 << ' ' << i.snd+1 << '\n';

    return 0;
}