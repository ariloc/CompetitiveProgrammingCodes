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

const int MAXN = 1005;

int subsets[MAXN][MAXN], subSize[MAXN];

int main() {
    int t; scanf("%d",&t);

    forn(i,t) {
        int n,k; scanf("%d %d",&n,&k);
        forn (j,k) {
            int m; scanf("%d",&m);
            subSize[j] = m;
            forn (o,m) scanf("%d",&subsets[j][o]);
        }

        printf("? %d ",n);
        forn (j,n) printf("%d ",j+1); printf("\n");
        fflush(stdout);
        int maxiArr; scanf("%d",&maxiArr);

        int l = 1, r = n;
        while (r != l) {
            int mid = (l+r)/2;

            printf("? %d ",mid-l+1);
            forsn (j,l-1,mid) printf("%d ",j+1); printf("\n");
            fflush(stdout);
            int maxiHalf; scanf("%d",&maxiHalf);

            if (maxiHalf == maxiArr) r = mid;
            else l = mid+1;
        }

        int ind = -1, maxiInd;
        forn (j,k) forn (o,subSize[j])
            if (subsets[j][o] == r) {
                printf("? %d ",n-subSize[j]);
                sort(subsets[j],subsets[j]+subSize[j]);
                int actI = 0;
                forn (h,n)
                    if (actI < subSize[j] and h+1 == subsets[j][actI])
                        actI++;
                    else printf("%d ",h+1);
                printf("\n");
                fflush(stdout);

                ind = j; scanf("%d",&maxiInd);
                goto OUT;
            }

        OUT:
        printf("! ");
        forn (j,k)
            if (j == ind) printf("%d ",maxiInd);
            else printf("%d ",maxiArr);
        printf("\n");
        fflush(stdout);

        char resp[25];
        scanf("%s",resp);
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!