#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int range(int x, int y, int z) {
    vi vec = {x,y,z};
    sort(all(vec));
    return vec.back()-vec[0];
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int a,b,c; cin >> a >> b >> c;
    
        int x,y,z;
        x = a, y = b, z = c;

        int rta = range(x,y,z);
        x = y+z;
        rta = min(rta,range(x,y,z));
        x = a, y = b, z = c;
        y = x+z;
        rta = min(rta,range(x,y,z));
        x = a, y = b, z = c;
        z = x+y;
        rta = min(rta,range(x,y,z));
        cout << rta << '\n';
    }

    return 0;
}
