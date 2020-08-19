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

int main() {
    FAST_IO;

    ll x,y,z; cin >> x >> y >> z;

    ll rest = 0, coconut = 0, extra = 0;
    rest += (x%z); coconut += (x/z);
    rest += (y%z); coconut += (y/z);
    extra += (rest/z);

    cout << coconut+extra << ' ' << max((ll)0,(z*extra)-max((x%z),(y%z)));

    return 0;
}