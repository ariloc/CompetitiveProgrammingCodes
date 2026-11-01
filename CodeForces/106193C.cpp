#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define sz(c) (int)(c).size()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;

int main(){
    FAST_IO;

    int n; cin >> n;

    if (n == 0) return cout << "0\n", 0;

    vi nums;
    while (n > 0) {
        int auxi = n & ((1<<7) - 1);
        //cerr << bitset<32>(n) << ' ' << bitset<32>(auxi) << endl;
        n >>= 7;
        //if (n) auxi |= (1<<7);
        //cerr << bitset<32>(auxi) << endl;
        nums.pb(auxi);
    }

    reverse(all(nums));
    forn(i,sz(nums)-1) nums[i] |= (1<<7);


    for (auto &i : nums) cout << i << ' ';
    cout << '\n';

    return 0;
}
