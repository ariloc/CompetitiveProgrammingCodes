#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0 ; i < int(n); i++)

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,cnt=0;
    set<int> let;
    string x;

    cin >> N;
    cin >> x;
    for (auto i : x) {
        if (not let.count(tolower(i))) {
            let.insert(tolower(i));
        }
    }

    if (let.size() == 26) cout << "YES";
    else cout << "NO";
}