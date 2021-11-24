#include <bits/stdc++.h>
    
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
    
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);
    
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 50;
const int INF = 2e9;
const int ADD = 1e7;

int arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int n; cin >> n;

        forn(i,n) cin >> arr[i], arr[i] += ADD;
        int mini = INF;
        forn(i,n) mini = min(mini,arr[i]);
        
        vi difs;
        forn(i,n) {
            int aux = arr[i]-mini;
            if (aux) difs.pb(aux);
        }

        int dcm = -1;
        if (!difs.empty()) dcm = difs[0];
        forsn(i,1,difs.size()) dcm = __gcd(dcm,difs[i]);

        cout << dcm << '\n';
    }

    return 0;
}