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

const int MAXN = 105;
const int MAXS = 100100;

int arr[MAXN];
bool dp[MAXS];
vi sums;

int main() {
    FAST_IO;

    int N; cin >> N;
    forn (i,N) cin >> arr[i];
    dp[0] = true;
    forn (i,N) dforsn(j,arr[i],MAXS) dp[j] |= dp[j-arr[i]];

    forsn (i,1,MAXS) if (dp[i]) sums.pb(i);
    cout << sums.size() << '\n';
    for (auto &i : sums) cout << i << ' ';

    return 0;
}

/// ESCRIB� en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO B�SICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
