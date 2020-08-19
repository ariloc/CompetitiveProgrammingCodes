#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int INF = 1e9+5;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    forn (i,t) {
        int a;
        vi arr;
        cin >> a;

        forn (j,a) {
            ll x;
            cin >> x;
            arr.push_back(x);
        }
        int cnt = 0, maxDif = 0;
        vi posib;

        forn (j,a) {
            if (arr[j] == -1) {
                if (j-1 >= 0 and arr[j-1] != -1)
                    posib.push_back(arr[j-1]);
                if (j+1 < a and arr[j+1] != -1)
                    posib.push_back(arr[j+1]);
            }
            if (j and arr[j] != -1 and arr[j-1] != -1)
                maxDif = max(maxDif,abs(arr[j]-arr[j-1]));
        }
        sort(all(posib));
        if (!posib.size()) {cout << "0 0\n"; continue;}

        int mini = posib[0], maxi = posib.back();
        int chosen = (maxi+mini)/2;
        cout << max({(maxi-chosen),(chosen-mini),(maxDif)}) << ' ' << chosen << '\n';
    }

    return 0;
}