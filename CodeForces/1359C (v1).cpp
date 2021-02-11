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

const int MAXN = 1000;

long double calc (long double &mid, long double &h, long double &c, long double &t) {
    return ((h*mid + c*(mid-1))/(double)(mid+mid-1));
}

int main() {
    FAST_IO;

    int T; cin >> T;

    forn (i,T) {
        long double h,c,t; cin >> h >> c >> t;

        long int cnt = 1;
        long double dif = abs(h-t);
        //cerr << ((h+c)/(double)2) << endl;
        if (abs(((h+c)/(long double)2) - t) < dif) {dif = abs(((h+c)/(long double)2) - t); cnt = 2;}

        //cerr << dif << endl;

        long double low = 0, high = 1000;
        while (high-low > 1) {
            long double mid = ll((low+high)/2);
            //cerr << (t-calc(mid,h,c,t)) << '!' << ' ' << mid << endl;
            if ((t-calc(mid,h,c,t)) >= 0) high = mid;
            else low = mid;
        }

        long double val;
        //cerr << abs(t-calc(high,h,c,t)) << ' ' << abs(t-calc(low,h,c,t)) << "!!" << endl;
        if (abs(t-calc(high,h,c,t)) < abs(t-calc(low,h,c,t))) val = high;
        else val = low;

        if (abs(t-calc(val,h,c,t)) < dif) {cnt = val+val-1;}

        cout << cnt << '\n';
    }



    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!