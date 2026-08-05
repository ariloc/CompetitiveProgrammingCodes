#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

int main(){
    FAST_IO;

    int n; cin >> n;
    set<int> se;
    int maxi = 0;
    forn(i,n) {
        char c; int x;
        cin >> c >> x;
        if (c == '-') {
            if (!se.count(x)) {
                maxi++;
            }
            se.erase(x);
        }
        else {
            se.insert(x);
        }
        maxi = max(maxi, (int)se.size());
    }
    cout << maxi << '\n';

    return 0;
}
