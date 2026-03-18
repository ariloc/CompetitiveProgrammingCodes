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

int const MAXN = 5005;
int const INF = 2e9;

int arr[MAXN],auxi[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n,x; cin >> n >> x;
        forn(i,n) cin >> arr[i];
        forn(i,n+1) auxi[i] = -INF;

        forn(i,n) {
            int s = 0;
            forsn(j,i,n) {
                s += arr[j];
                auxi[j-i+1] = max(auxi[j-i+1], s);
            }
        }

        dforn(i,n) auxi[i] = max(auxi[i],auxi[i+1]);

        ll r = 0;
        forn(i,n+1) {
            r = max(r, auxi[i] + (ll)x*i);
            cout << r << ' ';
        }
        cout << '\n';
    }

    return 0;
}
