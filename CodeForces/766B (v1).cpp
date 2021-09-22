#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define fst first
#define snd second

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

vi num;

bool valido(int &a, int &b, int &c) {
    if (a+b <= c) return false;
    if (a+c <= b) return false;
    if (c+b <= a) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    forn (i,N) {
        int x;
        cin >> x;
        num.push_back(x);
    }
    sort(num.begin(),num.end());

    for (int i = 2; i < num.size(); i++) {
        if (valido(num[i],num[i-1],num[i-2])) {
            cout << "YES"; return 0;
        }
    }
    cout << "NO";
    return 0;
}