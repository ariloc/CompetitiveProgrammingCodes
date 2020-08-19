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

vector<ll> stones, orderedStones;

int main() {
    FAST_IO;

    int N;
    cin >> N;

    ll accum = 0;
    forn (i,N) {
        int x;
        cin >> x;
        accum += x;
        stones.push_back(accum);
        orderedStones.push_back(x);
    }

    sort(all(orderedStones));

    accum = 0;
    forn (i,N) {
        accum += orderedStones[i];
        orderedStones[i] = accum;
    }

    int M;
    cin >> M;

    forn (i,M) {
        int typ,l,r;
        cin >> typ >> l >> r;
        l-=2; r--;

        if (typ == 1)
            cout << stones[r]-(l < 0 ? 0 : stones[l]) << '\n';
        else cout << orderedStones[r]-(l < 0 ? 0 :orderedStones[l]) << '\n';
    }

    return 0;
}