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

int main() {
    FAST_IO;

    int N; cin >> N;

    forn (i,N) {
        int n,k; cin >> n >> k;

        int sum = 0, cnt = 0;
        while (sum < k)
            {cnt++; sum+= cnt;}

        string r = string(n,'a');
        r[r.size()-1-cnt] = 'b';
        r[r.size()-1-cnt+(sum-k+1)] = 'b';

        cout << r << '\n';
    }

    return 0;
}