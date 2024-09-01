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

int n,x;
vi arr;

void solve() {
    int ind = -1;
    forn(i,n-1) 
        if (arr[i] + arr[i+1] == x)
            ind = i;

    if (ind != -1) {
        if ((arr[ind] + arr[0] != x) && (arr[0] + arr[ind+1] != x)) {
            forsn(i,1,ind+1) cout << arr[i] << ' ';
            cout << arr[0] << ' ';
            forsn(i,ind+1,n) cout << arr[i] << ' ';
        }
        else if (arr[ind] + arr[n-1] != x && arr[ind+1] + arr[n-1] != x) {
            forn(i,ind+1) cout << arr[i] << ' ';
            cout << arr[n-1] << ' ';
            forsn(i,ind+1,n-1) cout << arr[i] << ' ';
        }
        else cout << "*\n";
    }
    else {
        forn(i,n) cout << arr[i] << ' ';
    }
}

int main() {
    FAST_IO;

    cin >> n >> x;
    forn(i,n) {
        int a; cin >> a;
        arr.pb(a);
    }

    sort(all(arr));

    if(!(x&1)) {
        int half = x/2;
        vi l,e,r;
        forn(i,n) {
            if (arr[i] < half) l.pb(arr[i]);
            else if (arr[i] == half) e.pb(arr[i]);
            else r.pb(arr[i]);
        }

        if (!e.empty()) {
            deque<int> ret;
            ret.pb(e.back()); e.pop_back();
            dforn(i,l.size()) {
                ret.push_front(l[i]);
                if (!e.empty())
                    ret.push_front(e.back()), e.pop_back();
            }
            forn(i,r.size()) {
                ret.pb(r[i]);
                if (!e.empty())
                    ret.pb(e.back()), e.pop_back();
            }
            if (!e.empty())
                return cout << "*\n", 0;
            
            while(!ret.empty())
                cout << ret.front() << ' ', ret.pop_front();
        }
        else {
            solve();
        }
    }
    else {
        solve();
    }

    return 0;
}
