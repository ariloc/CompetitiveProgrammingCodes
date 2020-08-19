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

int send(int x1, int y1, int x2, int y2) {
    int res;
    printf("? %d %d %d %d\n",x1,y1,x2,y2);
    fflush(stdout);
    scanf("%d",&res);
    return res;
}

int main() {
    int n;
    scanf("%d",&n);

    int x1,x2,y1,y2;
    x1 = x2 = y1 = y2 = -1;
    forn (i,n-1) {
        int r = send(1,1,n,i+1);
        if (r%2 and y1 == -1) y1 = i+1;
        else if (!(r%2) and y1 != -1)
            {y2 = i+1; break;}
    }
    if (y1 != -1 and y2 == -1) y2 = n;

    forn (i,n-1) {
        int r = send(1,1,i+1,n);
        if (r%2 and x1 == -1) x1 = i+1;
        else if (!(r%2) and x1 != -1)
        {x2 = i+1; break;}
    }
    if (x1 != -1 and x2 == -1) x2 = n;

    //printf ("%d %d %d %d\n",x1,y1,x2,y2);

    if (y1 == -1) {
        int low = 0;
        int high = n;
        while((high-low)>1) {
            int mid = low + (high-low)/2;
            int r = send(x1,1,x1,mid);
            if (r%2) high = mid;
            else low = mid;
        }
        y1 = y2 = high;
    }
    if (x1 == -1) {
        int low = 0;
        int high = n;
        while((high-low)>1) {
            int mid = low + (high-low)/2;
            int r = send(1,y1,mid,y1);
            if (r%2) high = mid;
            else low = mid;
        }
        x1 = x2 = high;
    }

    int finalR = send(x1,y1,x1,y1);
    if (!(finalR % 2)) swap(y1,y2);

    printf ("! %d %d %d %d",x1,y1,x2,y2);

    return 0;
}