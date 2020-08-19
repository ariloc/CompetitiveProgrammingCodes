#include<bits/stdc++.h>
#define forn(i,s) for(int i = 0; i < int(s); i++)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

int main() {
    FAST_IO;
    int t;
    cin >> t;
    
    forn(i,t) {
        int a,b;
        cin >> a >> b;

        if (b == a) cout << 0;
        else if (b > a) 
            if (a%2 == b%2) cout << 2;
            else cout << 1;
        else 
           if (a%2 == b%2) cout << 1;
           else cout << 2;
        cout << '\n';
    }
    
    return 0;
}