#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const int MAXN = 2e5+5;

int arr[MAXN];

int main() {
    int t; scanf("%d",&t);
    forn(o,t) {
        int n; scanf("%d",&n);
        forn(i,n) scanf("%d",&arr[i]);

        sort(arr,arr+n);
        ll s1 = arr[0]+arr[1], s2 = arr[n-1];

        if (s1 < s2) {puts("YES"); continue;}

        int l = 1, r = n-2;
        bool ch = 1, posib = 0;
        while (l < r) {
            if (ch) s2 += arr[r], l++;
            else {
                s1 += arr[l], r--;
                if (s1 < s2) {posib = 1; break;}
            }
            ch ^= 1;
        }
        printf("%s\n",(posib ? "YES" : "NO"));
    }

    return 0;
}