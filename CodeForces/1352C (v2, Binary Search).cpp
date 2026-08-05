#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define FAST_IO ios::sync_with_stdio(false);

using namespace std;
typedef long long ll;

int const INF = 2e9+100;

int main(){
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n,k; cin >> n >> k;

        int lo = 0, hi = INF;
        while (hi-lo > 1) {
            int mid = (int)(((ll)lo+hi)/2LL);
            if ((mid - mid/n) >= k) hi = mid;
            else lo = mid;
        }

        cout << hi << '\n';
    }

    return 0;
}
