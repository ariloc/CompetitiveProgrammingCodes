#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i <= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) (int)c.size()
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef long double ld;

int const MAXN = 1e6+5;
ll const INF = 1e12;
ld const WORST = .3;
ld const BAD = .6;
ld const EPS = 1e-12;

int arr[MAXN];
int n,s;

bool posib (ld mid) {
    int worst = 0, bad = 0, good = 0;
    forn(i,n) {
        if (arr[i] - mid*WORST <= -EPS) worst++;
        else if (arr[i] - mid*BAD <= -EPS) bad++;
        else if (arr[i] - mid <= -EPS) good++;
        else return false;
    }

    int avail = s;
    int aloc = min(2,bad)+worst;
    avail -= aloc;
    bad -= min(2,bad);
    if (avail < 0) return false;

    avail -= bad + (bad+1)/2;
    if (avail < 0) return false;

    if (good && avail == s) ++avail;
    avail -= good*2;
    if (avail < 0) return false;

    return true;
}

int main() {
    FAST_IO;

    cin >> n >> s;
    forn(i,n) cin >> arr[i];

    sort(arr,arr+n);

    ld lo = 0, hi = INF;
    forn(i,300) {
        ld mid = (hi+lo)/2;
        if (posib(mid)) hi = mid;
        else lo = mid;
    }

    cout << fixed << setprecision(10) << hi << '\n';

    return 0;
}
