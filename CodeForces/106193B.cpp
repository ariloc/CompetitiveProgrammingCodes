#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;

int const INF = 2e9;

int main(){
    FAST_IO;

    int n; cin >> n;

    vi comp(3,INF);
    forn(i,n) {
        vi auxi(3);
        forn(k,3) cin >> auxi[k];
        sort(all(auxi));
        forn(k,3) comp[k] = min(comp[k],auxi[k]);
    }

    cout << comp[0] * comp[1] * comp[2] << '\n';

    return 0;
}
