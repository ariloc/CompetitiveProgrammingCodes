#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)

using namespace std;
typedef long double ld;
typedef long long ll;

int const MAXN = 105;

int arr[MAXN];

int main(){
    int n; cin >> n;
    
    int mi; cin >> mi;
    forn(i,n-1) cin >> arr[i];

    sort(arr,arr+n-1);

    ll rem = mi;
    bool posib = true;
    forn(i,n-1) {
        ll mul = arr[i];
        if (!i) --mul;
        rem -= mul*(ll)(n-1-i);
        if (rem <= 0) posib = false;
    }

    cout << (posib ? "SI" : "NO") << '\n';

    return 0;
}
