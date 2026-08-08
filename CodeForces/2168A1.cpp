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

int const MAXN = 1e4+5;

int arr[MAXN];

int main() {
    FAST_IO;

    string mode; cin >> mode;

    if (mode == "first") {
        int n; cin >> n;
        forn(i,n) cin >> arr[i];
        string s;
        forn(i,n) s.pb(arr[i]+'a'-1);
        cout << s << '\n';
    }
    else {
        string val; cin >> val;
        cout << sz(val) << '\n';
        for (auto &i : val) cout << i-'a'+1 << ' ';
    }

    return 0;
}
