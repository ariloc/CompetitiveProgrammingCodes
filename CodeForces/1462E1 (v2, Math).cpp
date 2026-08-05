#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define FAST_IO ios::sync_with_stdio(false);

using namespace std;
typedef long long ll;

int const MAXN = 2e5+5;

int arr[MAXN];

int main(){
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        forn(i,n) cin >> arr[i];

        sort(arr,arr+n);

        int l = 0;
        ll cnt = 0;
        forn(i,n) {
            while (l < i && arr[i]-arr[l] > 2) l++;
            ll dif = i-l;
            cnt += dif * (dif-1) / 2LL;
        }

        cout << cnt << '\n';
    }

    return 0;
}
