#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 1e5+2;

int arr[MAXN];

int main() {
    FAST_IO;

    int N; cin >> N;

    forn (i,N) cin >> arr[i];

    sort(arr,arr+N);

    dforsn (i,2,N) {
        if ((arr[i] + arr[i-1]) <= arr[i-2]) continue;
        if ((arr[i] + arr[i-1]) <= arr[i-1]) continue;
        if ((arr[i-1] + arr[i-2]) <= arr[i]) continue;
        cout << "YES"; return 0;
    }

    cout << "NO";
    return 0;
}