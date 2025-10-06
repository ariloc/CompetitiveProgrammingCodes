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

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        
        bool ok = false;
        forsn(off,1,n)
            if (!ok)
                forn(i,n) {
                    int a = i+1, b = (i+off)%n+1;
                    if (b < a) swap(a,b);
                    cout << a << ' ' << b << endl;
                    int r; cin >> r;
                    if (r == 1) {ok = true; break;}
                    if (r == -1) return 0;
                }
    }

    return 0;
}
