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

bool posib(int mid, int h, int d) {
    int block = d / mid;
    int rest = d % mid;
    return (rest*(ll)(block+1)*(ll)(block+2)/2LL + (mid-rest)*(ll)block*(ll)(block+1)/2LL - mid + 1) < h;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int h,d; cin >> h >> d;

        bool ouch = false;
        if (h == 1) ouch = true, h++;

        int lo = 0, hi = d;
        while (hi-lo > 1) {
            int mid = (hi+lo)/2;
            if (posib(mid,h,d)) hi = mid;
            else lo = mid;
        }

        cout << d + hi - 1 + ouch << '\n';
    }

    return 0;
}
