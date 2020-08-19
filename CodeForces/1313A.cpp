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

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        int arr[3],r = 0;
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr,arr+3);

        if (arr[2]) {arr[2]--; r++;}
        if (arr[1]) {arr[1]--; r++;}
        if (arr[0]) {arr[0]--; r++;}

        if (arr[2] and arr[1]) {arr[2]--; arr[1]--; r++;}
        if (arr[1] and arr[0]) {arr[1]--; arr[0]--; r++;}
        if (arr[2] and arr[0]) {arr[2]--; arr[0]--; r++;}

        if (arr[2] and arr[1] and arr[0]) {arr[2]--; arr[1]--; arr[0]--; r++;}

        cout << r << '\n';
    }

    return 0;
}