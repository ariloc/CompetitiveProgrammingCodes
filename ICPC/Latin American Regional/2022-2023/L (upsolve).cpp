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

int const MAXN = 2e5+5;
int const MOD = 1e9+7;
int const P = 31;

int roll[MAXN];
int potp[MAXN];

int gethash (int l, int r) { // [l,r]
    return ((roll[r+1] - (roll[l] * (ll)potp[r-l+1])%MOD) + MOD)%MOD;
}

int main() {
    FAST_IO;

    potp[0] = 1;
    forsn(i,1,MAXN) potp[i] = (potp[i-1] * (ll)P)%MOD;

    string s; cin >> s;
    int d; cin >> d;

    int n = (int)s.size();
    forn(i,n) {
        roll[i+1] = (roll[i] * (ll)P + s[i]-'a')%MOD;
    }

    int r = 0, rta = 0;
    while (r < n) {
        int maxi = 0;
        forsn(i,1,min(d,n-r)+1) {
            int phash = gethash(r,r+i-1);
            int act = r+i-1;
            for (int j = r+i; j+i-1 < n; j += i) {
                int mhash = gethash(j,j+i-1);
                if (mhash != phash) break;
                act = j+i-1;
            }

            if (act+1 < n && s[act+1] == s[r]) {
                int low = 1, high = i;
                while (high - low > 1) {
                    int mid = (high+low)/2;
                    if (gethash(act+1,act+mid) != gethash(r,r+mid-1)) high = mid;
                    else low = mid;
                }
                act += low;
            }

            maxi = max(maxi,act);
        }
        ++rta, r = maxi+1;
    }

    cout << rta << '\n';

    return 0;
}
