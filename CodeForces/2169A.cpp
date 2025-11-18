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

int const MAXN = 3e5+5;

int arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n,a; cin >> n >> a;
        forn(i,n) cin >> arr[i];

        int s1 = 0, s2 = 0;
        forn(i,n) {
            if (arr[i] <= a) s1++;
            else s2++;
        }

        int s11 = 0, s12 = 0;
        forn(i,n) {
            if (arr[i] >= a) s11++;
            else s12++;
        }

        if (s2 > s12) cout << a+1 << '\n';
        else cout << a-1 << '\n';
    }
   
    return 0;

}
