#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
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

        int r = 0;
        int sqr = sqrt(n)+3;
        forn(i,n) {
            for (int j = i-arr[i], cnt = 1; j >= 0 && cnt <= min(sqr,arr[i]); j -= arr[i], cnt++)
                if (arr[i] >= arr[j] && arr[i] * (ll)arr[j] == i-j) ++r;
            for (int j = i+arr[i], cnt = 1; j < n && cnt <= min(sqr,arr[i]); j += arr[i], cnt++)
                if (arr[i] > arr[j] && arr[i] * (ll)arr[j] == j-i) ++r;
        }

        cout << r << '\n';
    }

    return 0;
}
