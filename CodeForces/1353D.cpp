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

struct rango{
    int l,r;

    bool operator< (const rango &o) const{
        if ((o.r-o.l) == (r-l)) return o.l < l;
        return (o.r-o.l) > (r-l);
    }
};

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        int n; cin >> n;
        vi arr(n+1);

        priority_queue<rango> Q;
        Q.push({1,n}); int cnt = 1;
        while (not Q.empty()) {
            auto e = Q.top(); Q.pop();
            //cerr << e.l << ' ' << e.r << endl;
            int r = e.r, l = e.l;

            int half = -1;
            if ((r-l+1) & 1) {
                arr[(l+r)/2] = cnt++;
                half = (l+r)/2;
            }
            else {arr[(l+r-1)/2] = cnt++; half = (l+r-1)/2;}
            //cerr << half << ' ' << cnt-1 << endl;

            if (r != l){
                if (half-1 > 0 and l <= half-1) Q.push({l,half-1});
                if (half+1 <= n and half+1 <= r) Q.push({half+1,r});
            }
        }

        forsn (j,1,n+1) cout << arr[j] << ' ';
        cout << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!