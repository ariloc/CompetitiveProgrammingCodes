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

const int MAXN = 8002;

int arr[MAXN];

int main() {
    int t; scanf("%d",&t);

    forn (i,t) {
        int N; scanf("%d",&N);
        forn (j,N) scanf("%d",&arr[j]);

        if (N == 1) {printf("0\n"); continue;}

        int cnt = 0;
        forn (j,N) {
            int r = 1; int sum = arr[0];
            forn (k,N) {
                while (r < N and sum < arr[j]) {
                    sum += arr[r];
                    r++;
                }

                if (sum == arr[j] and r-k > 1) {cnt++; break;}
                sum -= arr[k];
            }
        }

        printf("%d\n",cnt);
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!