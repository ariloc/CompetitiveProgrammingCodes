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

        int maxi = 0;
        forn(i,n) forn(j,n) {
            int s = i*n + (j+1);
            if (i < n-1) {
                s += (i+1)*n + (j+1);
            }
            if (j < n-1) {
                s += i*n + (j+2);
            }
            if (j > 0) {
                s += i*n + j;
            }
            if (i > 0) {
                s += (i-1)*n + (j+1);
            }
            maxi = max(maxi,s);
        }
        cout << maxi << '\n';
    }

    return 0;
}
