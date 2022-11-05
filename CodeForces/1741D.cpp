#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int MAXN = 3e5+5;

int arr[MAXN];
int mini[MAXN], maxi[MAXN];

int main() {
    int t; scanf("%d",&t);

    forn(_,t) {
        int n; scanf("%d",&n);

        forn(i,n) scanf("%d",&arr[i]);
        forn(i,n) mini[i] = maxi[i] = arr[i];

        int pot = 1, op = 0;
        bool posib = true;
        while (pot < n) {
            for (int i = 0; i < n; i += pot*2) {
                if (mini[i] > mini[i+pot]) op++;
                mini[i] = min(mini[i], mini[i+pot]);
                maxi[i] = max(maxi[i], maxi[i+pot]);

                if (maxi[i] - mini[i] >= pot*2) posib = false;
            }
            pot <<= 1;
        }

        if (posib) printf("%d\n",op);
        else printf("-1\n");
    }

    return 0;
}
