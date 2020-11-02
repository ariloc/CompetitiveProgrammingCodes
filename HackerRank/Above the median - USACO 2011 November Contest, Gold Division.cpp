// https://www.hackerrank.com/contests/simulacro-1-oia-2020/challenges/p5-above-the-median/problem
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

const int MAXN = 2e5+5;
const int ADD = 1e5+1;

int FT[MAXN];

void setFT (int p, int v) {
    for(int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

int getFT (int p) {
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

ll above_median(int X, vector <int> H)
{
    vi toSort = H;
    toSort.pb(X);

    // compression
    sort(all(toSort));
    toSort.erase(unique(all(toSort)),toSort.end());
    forn(i,H.size()) H[i] = lower_bound(all(toSort),H[i]) - toSort.begin();
    X = lower_bound(all(toSort),X) - toSort.begin();

    ll rta = 0; int bal = 0;
    setFT(ADD,1); // marco prefijo sin nada
    forn(i,H.size()) {
        if (H[i] < X) bal--; else bal++;
        rta += getFT(bal+ADD);
        setFT(bal+ADD,1);
    }

    return rta;
}

int main()
{
    //freopen("entrada.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X;
    cin >> N >> X;

    vector <int> H(N);
    for(int i=0; i<N; i++)
        cin >> H[i];

    cout << above_median(X, H) << endl;

    return 0;
}
