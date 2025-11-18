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

int const MAXN = 2e5+5;

int arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        forn(i,n) cin >> arr[i];
        
        ll rsum = 0;
        forn(i,n) rsum += arr[i];

        ll lmaxi = 0, sum = 0, maxi = rsum;
        forn(i,n) {
            rsum -= arr[i];
            maxi = max(maxi, lmaxi + (i+1)*(ll)(i+1) + i+1 + rsum);

            sum += arr[i];
            lmaxi = max(lmaxi, sum-(i+2)*(ll)(i+2)+i+2);
        }

        cout << maxi << '\n';
    }
   
    return 0;

}
