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

const int MAXN = 2e5+5;

int arr[MAXN];//TAd[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        int n,k,z; cin >> n >> k >> z;

        //forn(j,n) TAd[j] = 0; // reset

        int sum = 0;
        forn(j,n) {
            int x; cin >> x; arr[j] = x;
            //TAd[j] = x;
            if (j <= k) sum += x;
        }

        //forsn(j,1,n) TAd[j] += TAd[j-1]; // dp

        int maxi = sum;
        forsn (j,1,k) {
            int mySum = sum, ind = k;
            forsn(l,1,z+1) {
                if ((ind-1) < 0 or (ind-1) <= j) {
                    if (ind >= 0 and ind > j) maxi = max(maxi,mySum+arr[j-1]-arr[ind]);
                    break;
                }

                mySum -= arr[ind--]; mySum -= arr[ind--];
                mySum += (arr[j]+arr[j-1]);

                maxi = max(maxi,mySum);
            }
        }

        cout << maxi << '\n';

    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!