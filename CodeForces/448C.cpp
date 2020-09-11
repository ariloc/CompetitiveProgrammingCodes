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

const int MAXN = 5005;
const int INF = 1e9+2;

int fence[MAXN];
int rta = 0, n;

ll solve (int l, int r, int h) {
    int ind, mini = INF;
    bool same = true;
    forsn (i,l,r) {
        if (mini > fence[i]) {mini = fence[i]; ind = i;}
        if (i-1 >= l and fence[i-1] != fence[i]) same = false;
    }
    //cerr << mini << ' ' << ind << ' ' << l << ' ' << r << ' ' << h << ' ' << same << ' ' << max(0,min(r-l,fence[l]-h)) << endl;

    if (same) return max(0,min(r-l,fence[l]-h));
    return min(solve(l,ind,mini) + solve(ind+1,r,mini) + (mini-h),(ll)r-l);
    return r-l;
}

int main() {
    FAST_IO;

    cin >> n;

    forn (i,n) cin >> fence[i];

    cout << solve(0,n,0);

    return 0;
}
