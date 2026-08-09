#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)

using namespace std;
typedef long double ld;
typedef long long ll;

int main(){
    int n,m; cin >> n >> m;
    int x,y; cin >> x >> y;

    ll ra = (n+m)*(ll)x*m + (n+m)*(ll)y*n;
    ll rb = 2*(x+y)*(ll)n*m;

    if (ra > rb) cout << "A\n";
    else if (ra < rb) cout << "B\n";
    else cout << "C\n";

    return 0;
}
