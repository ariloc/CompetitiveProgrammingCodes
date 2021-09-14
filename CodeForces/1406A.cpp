#include <bits/stdc++.h>

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forsn(i,s,n) for (int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for (int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 105;

int arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int n; cin >> n;
        forn(i,n) cin >> arr[i];
        sort(arr,arr+n);

        int miss1 = 0, miss2 = 0;
        forn(i,n) {
            if (arr[i] == miss1) miss1++;
            else if (arr[i] == miss2) miss2++;
        }

        cout << miss1 + miss2 << '\n';
    }
    
    return 0;
}