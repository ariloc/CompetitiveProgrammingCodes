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

map<string,int> cant;
int arr[MAXN],val[MAXN],ind = 0;

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;

    forn (i,n) cin >> arr[i];

    forn (i,m) {
        string s; cin >> s;
        cant[s]++;
    }

    for (auto &i : cant) val[ind++] = i.snd;

    sort(val,val+ind);
    sort(arr,arr+n);

    int indP = 0, rtaS = 0, rtaH = 0;
    dforn (i,ind) {
        rtaS += val[i]*arr[indP++];
    }
    indP = n-1;
    dforn(i,ind) {
        rtaH += val[i]*arr[indP--];
    }

    cout << rtaS << ' ' << rtaH;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!