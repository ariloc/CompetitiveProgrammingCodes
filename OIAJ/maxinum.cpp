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

const int MAXN = 2e6+11;

int num[MAXN];
int mult[MAXN];
ii dp[MAXN]; // sum || nonUsed

int main() {
    freopen("maxinum.in","r",stdin);
    freopen("maxinum.out","w",stdout);

    int N;
    scanf("%d",&N);

    forn (i,N) {
        int x; scanf("%d",&x);
        num[i+10] = x;
        mult[i-2+10] = num[i+10]*num[i-2+10];
    }

    forsn (i,10,N+11) {
        ii case1 = {dp[i-1].fst, dp[i-1].snd + num[i]};
        ii case2 = {dp[i-3].fst + mult[i-2], dp[i-3].snd + num[i-1]};
        ii case3 = {dp[i-4].fst + mult[i-3] + mult[i-2], dp[i-4].snd};
        dp[i] = max({case1,case2,case3});
    }

    printf("%d\n%d",dp[N+10].fst,dp[N+10].snd);

    return 0;
}
