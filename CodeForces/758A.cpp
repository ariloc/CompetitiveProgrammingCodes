#include <bits/stdc++.h>

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forsn(i,s,n) for (int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for (int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 105;

int arr[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> arr[i];
    int maxi = -1;
    forn(i,n) maxi = max(maxi,arr[i]);
    
    ll acc = 0;
    forn(i,n) acc += maxi-arr[i];

    cout << acc;
    
    return 0;
}