#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 5005;

int arr[MAXN];
int n;

void quick(int l, int r) {
    if (r-l <= 1)
        return;
    int idx = l;
    forsn(i,l,r-1) {
        if (arr[i] < arr[r-1]) {
            swap(arr[i],arr[idx]);
            idx++;
        }
    }
    swap(arr[r-1],arr[idx]);
    forn(i,n) cout << arr[i] << ' ';
    cout << '\n';
    quick(l,idx);
    quick(idx+1,r);
}

int main() {
    FAST_IO;

    cin >> n;
    forn(i,n) cin >> arr[i];

    quick(0,n);

    return 0;
}
