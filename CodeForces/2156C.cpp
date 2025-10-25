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

int arr[MAXN],ap[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n,k; cin >> n >> k;
        forn(i,n+1) ap[i] = 0;
        forn(i,n) cin >> arr[i], ap[arr[i]]++;

        sort(arr,arr+n);

        int maxi = 1;
        forsn(i,1,n+1) {
            int cnt = 0;
            for (int j = i; j <= min(n,4*i); j += i) {
                if (j <= 4*i) cnt += ap[j];
            }
            int ind = upper_bound(arr,arr+n,4*i)-arr;
            cnt += (n-ind);
            if (n-cnt <= k)
                maxi = max(maxi,i);
        }
        cout << maxi << '\n';
    }

    return 0;
}
