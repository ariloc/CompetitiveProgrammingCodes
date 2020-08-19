#include <bits/stdc++.h>

#define forn(i,n) for(ll i = 0; i < ll(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

ll func(long double x, long double &d) {return x + (d+x)/(x+1); } // floor((a+b-1)/b) = ceil(a/b)

ll TSD(long double &n, long double &d){
    int cnt = 200; // Ajustable si estás jugado con el tiempo
    long double l = 0, r = n;

    while(cnt--){
        long double tl = (2*l + r)/3, tr = (l + 2*r)/3;
        if(func(tl,d) < func(tr,d))r = tr;
        else l = tl;
    }
    r = floor(r);
    return (func(r,d) <= n ? r : -1);
}

int main() {
    FAST_IO;

    int T;
    cin >> T;

    forn (i,T) {
        long double n,d;
        cin >> n >> d;
        if (TSD(n,d) == -1)
            cout << "NO";
        else cout << "YES";
        cout << '\n';
    }

    return 0;
}