#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 2e5+5;
int const MAXK = 30;

int arr[MAXN];
int off;

void match(int l, int r) {
    if (r-l < 0) return;
    if (r-l == 0) {
        arr[l-off] = l;
        return;
    }

    int idx;
    dforn(k,MAXK+1) {
        if ((l & (1<<k)) != (r & (1<<k))) {
            idx = k;
            break;
        }
    }

    int cut;
    forsn(i,l,r+1) {
        if (i & (1<<idx)) {
            cut = i; break;
        }
    }

    if (cut-l < r-cut+1) {
        dforsn(i,l,cut) arr[i-off] = 2*cut-i-1, arr[2*cut-i-1-off] = i;
        match(2*cut-l,r);
    }
    else {
        forsn(i,cut,r+1) arr[i-off] = 2*cut-i-1, arr[2*cut-i-1-off] = i;
        match(l,r-2*(r-cut+1));
    }
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int l,r; cin >> l >> r;

        off = l;
        match(l,r);

        ll s = 0;
        forn(i,r-l+1) s += (arr[i] | (i+l));

        cout << s << '\n';
        forn(i,r-l+1) cout << arr[i] << ' ';
        cout << '\n';
    }

    return 0;
}
