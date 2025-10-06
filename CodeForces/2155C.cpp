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

int const MOD = 676767677;
int const MAXN = 1e5+5;

int arr[MAXN];
int cap[MAXN]; // 0 l, 1 r 

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        forn(i,n) cin >> arr[i];

        forn(i,n) cap[i] = -1;
        
        bool anyi = false;
        forsn(i,1,n) {
            if (arr[i] != arr[i-1]) anyi = true;
        }

        if (!anyi) {
            bool ok = true;
            if (n&1) {
                forn(i,n) if (arr[i] != (n+1)/2) ok = false;
                if (ok) cout << "2\n";
            }
            else {
                forn(i,n) if (arr[i] != n/2 && arr[i] != (n/2)+1) ok = false;
                if (ok) cout << "1\n";
            }
            if (!ok) cout << "0\n";
            continue;
        }

        bool posib = true;
        forsn(i,1,n) {
            if (abs(arr[i]-arr[i-1]) > 1)
                posib = false;
        }
        /*
        forsn(i,1,n-1) {
            if (arr[i+1] > arr[i] && arr[i] < arr[i-1])
                posib = false;
            if (arr[i+1] < arr[i] && arr[i] > arr[i-1])
                posib = false;
        }
        */
        forsn(i,1,n) {
            if (arr[i] > arr[i-1]) {
                if (cap[i] == 1 || cap[i-1] == 1) posib = false;
                cap[i] = cap[i-1] = 0;
            }
            if (arr[i] < arr[i-1]) {
                if (!cap[i] || !cap[i-1]) posib = false;
                cap[i] = cap[i-1] = 1;
            }
        }
        auto check = [&](int i) {
            if (arr[i] == arr[i-1]) {
                if (cap[i-1] == 0) {
                    if (cap[i] == 0) posib = false;
                    cap[i] = 1;
                }
                if (cap[i-1] == 1) {
                    if (cap[i] == 1) posib = false;
                    cap[i] = 0;
                }
                if (cap[i] == 0) {
                    if (cap[i-1] == 0) posib = false;
                    cap[i-1] = 1;
                }
                if (cap[i] == 1) {
                    if (cap[i-1] == 1) posib = false;
                    cap[i-1] = 0;
                }
            }
        };
        forsn(i,1,n) check(i);
        dforsn(i,1,n) check(i);

        int accl = 0;
        forn(i,n) {
            accl += (cap[i] == 0);
        }
        int accr = 0;
        dforn(i,n) {
            accl -= (cap[i] == 0);
            if (arr[i] != accl+accr+1) posib = false;
            accr += (cap[i] == 1);
        }

        cout << (posib ? 1 : 0) << '\n';
    }

    return 0;
}
