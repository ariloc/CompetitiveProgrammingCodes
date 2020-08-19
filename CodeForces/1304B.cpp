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

vector<string> arr;
bitset<100> done;

int main() {
    FAST_IO;

    int n,m;
    cin >> n >> m;

    forn (i,n) {
        string s;
        cin >> s;
        arr.push_back(s);
    }

    sort(all(arr));

    vector<string> st, nd, middle;
    string r;
    forn(i,n) {
        if (done[i]) continue;
        string a = arr[i];
        reverse(all(a));
        auto it = lower_bound(arr.begin()+i+1,arr.end(),a);
        if (it == arr.end()) {
            if (a == arr[i] and middle.empty()) middle.push_back(arr[i]);
            continue;
        }
        int indB = it - arr.begin();
        if (arr[indB] == a) {
            st.push_back(arr[i]);
            nd.push_back(arr[indB]);
            done[indB] = true;
            done[i] = true;
        }
        else if (a == arr[i] and middle.empty()) middle.push_back(arr[i]);
    }
    cout << st.size()*m+nd.size()*m+middle.size()*m << '\n';
    for (auto &i : st) cout << i;
    for (auto &i : middle) cout << i;
    dforn (i,nd.size()) cout << nd[i];

    return 0;
}