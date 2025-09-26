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

int const MAXN = 2e5+5;

map<int,int> nums1, nums2;
int arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n,k,l,r; cin >> n >> k >> l >> r;
        forn(i,n) cin >> arr[i];

        nums1.clear();
        nums2.clear();

        int idx = 0, may = 0;
        ll cnt = 0;
        forn(i,n) {
            nums1[arr[i]]++;
            nums2[arr[i]]++;
            while (((int)nums1.size() > k || ((int)nums1.size() == k && nums1[arr[idx]] > 1)) && idx < i) {
                auto it = nums1.find(arr[idx]);
                if ((*it).snd == 1) {
                    nums1.erase(it);
                }
                else {
                    (*it).snd--;
                }
                idx++;
            }
            while ((int)nums2.size() > k && may < idx) {
                auto it = nums2.find(arr[may]);
                if ((*it).snd == 1) {
                    nums2.erase(it);
                }
                else {
                    (*it).snd--;
                }
                may++;
            }
            if ((int)nums1.size() == k) {
                int bl = (i-r+1), br = (i-l+1);
                cnt += max(0, min(idx,br) - max(may,bl) + 1);
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
