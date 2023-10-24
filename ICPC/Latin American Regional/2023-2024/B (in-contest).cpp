#include <iostream>
#include <vector>
#include <set>
#include <stack>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int,int> ii;

int const MAXN = 3005;
int const MAXNUM = 1e6;
int const SHIFT = 1e5;

int arr[MAXN];
int histo[MAXNUM];

int main() {
    int n; cin >> n;
    forn(i,3*n) cin >> arr[i], histo[arr[i]+SHIFT]++;

    bool isn = true;
    forn(i,MAXNUM) if (histo[i]%3 != 0) isn = false;

    if (isn) {
        cout << "N\n";
    }
    else {
        cout << "Y\n";
    }
    
    return 0;
}
