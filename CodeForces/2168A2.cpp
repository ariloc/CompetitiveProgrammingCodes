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
int const MAXPOT = 10;

int arr[MAXN];
ll pot[MAXPOT];

int main() {
    FAST_IO;

    pot[0] = 1;
    forsn(i,1,MAXPOT) pot[i] = pot[i-1] * 10LL;

    string mode; cin >> mode;

    if (mode == "first") {
        int n; cin >> n;
        forn(i,n) cin >> arr[i];
        string s;
        forn(i,n) {
            forn(k,10) {
                int auxi = arr[i]/pot[k];
                s.pb(auxi%10+'a');
            }
        }
        cout << s << '\n';
    }
    else {
        string val; cin >> val;
        for (int i = 0; i < sz(val); i += 10) {
            int auxi = 0;
            forn(k,10) auxi += (val[i+k]-'a')*pot[k];
            arr[i/10] = auxi;
        }
        cout << sz(val)/10 << '\n';
        forn(i,sz(val)/10) cout << arr[i] << ' ';
    }

    return 0;
}
