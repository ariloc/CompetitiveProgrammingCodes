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

int const INF = 2e9;

int query(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    int x; cin >> x;
    return x;
}

int main() {
    FAST_IO;

    string pass; cin >> pass;

    if (pass == "first") {
        int t; cin >> t;
        forn(_,t) {
            int n; cin >> n;
            
            int pmi = -1, pma = -1;
            int mini = INF, maxi = -INF;
            forn(i,n) {
                int x; cin >> x;
                if (x < mini) mini = x, pmi = i;
                if (x > maxi) maxi = x, pma = i;
            }

            cout << (int)(pmi < pma) << '\n';
        }
    }
    else {
        int t; cin >> t;
        forn(_,t) {
            int n,x; cin >> n >> x;

            if (x) {
                int lo = 1, hi = n;
                while (hi - lo > 1) {
                    int mid = (hi+lo)/2;
                    if (query(1,mid) == n-1) hi = mid;
                    else lo = mid;
                }
                cout << "! " << hi << endl;
            }
            else {
                int lo = 1, hi = n;
                while (hi - lo > 1) {
                    int mid = (hi+lo)/2;
                    if (query(mid,n) == n-1) lo = mid;
                    else hi = mid;
                }
                cout << "! " << lo << endl;
            }
        }
    }

    return 0;
}
