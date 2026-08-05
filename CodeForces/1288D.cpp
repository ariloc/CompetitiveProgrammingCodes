#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define snd second
#define fst first
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

int const MAXN = 3e+5;
int const MAXM = 8;
int const MAXV = 1e9;
int const MAXP = (1<<MAXM) + 5;

int arr[MAXN][MAXM];
int records[MAXP];
int n,m;

ii can(int mid) {
    fill(records,records+MAXP,-1);
    forn(i,n) {
        int mk = 0;
        forn(j,m) if (arr[i][j] >= mid) mk |= (1<<j);
        records[mk] = i;
        if (mk == ((1<<m)-1)) return {i,i};
        int ot = ((1<<m)-1)^mk;
        forn(mk2,1<<m) {
            if ((ot & mk2) != ot) continue;
            if (records[mk2] != -1)
                return {i,records[mk2]};
        }
    }
    return {-1,-1};
}

int main() {
    FAST_IO;

    cin >> n >> m;

    forn(i,n) forn(j,m) cin >> arr[i][j];

    int lo = -1, hi = MAXV+1;
    while(hi-lo > 1) {
        int mid = (hi+lo)/2;
        if (can(mid).fst != -1) lo = mid;
        else hi = mid;
    }

    ii ret = can(lo);
    cout << ret.fst+1 << ' ' << ret.snd+1 << '\n';
}
