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

const int MAXN = 2e5+2;

int arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn (i,t) {
        int N; cin >> N;
        forn (j,N) cin >> arr[j];
        if (N < 2) {cout << "0\n"; continue;}
        sort(arr,arr+N);
        int dif = 0, same = 0;
        int sameCnt = 0;
        forsn (j,1,N)
            if (arr[j] == arr[j-1]) sameCnt++;
            else {dif++; same = max(same,sameCnt); sameCnt = 0;}
        same = max(sameCnt,same);

        if (!same or !dif) cout << "1\n";
        else cout << min(same+1-(same == dif ? 1 : 0),dif+1) << '\n';
    }

    return 0;
}