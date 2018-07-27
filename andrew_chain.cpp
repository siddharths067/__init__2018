#include <iostream>
typedef long long int ll;
using namespace std;

ll ccw(ll ax, ll ay, ll bx, ll by, ll cx, ll cy){
    return (bx-ax) * (cy-ay) - (cx-ax) * (by-ay);
}

ll x[1000000], y[1000000], cx[1000000], cy[1000000];
int main(){
    /*
https://ideone.com/J9o0mu


        4
0 0
5 0
5 5
10 0


8
0 3
1 1
2 2
4 4
0 0
1 2
3 1
3 3
    */
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
        cin>>x[i]>>y[i];
    for(ll i=0;i<n;i++)
        for(ll j=i+1;j<n;j++)
            if(x[i]>x[j]){
                swap(x[i], x[j]);
                swap(y[i], y[j]);
            }
            else if(x[i] == x[j] && y[i] > y[j]){
                swap(x[i], x[j]);
                swap(y[i], y[j]);
            }
    ll stp = 0;
    for(ll i=0;i<n;i++){
        while(stp >= 2 && ccw(cx[stp-2], cy[stp-2], cx[stp-1], cy[stp-1], x[i], y[i]) >=0)
            stp--;
        cx[stp] = x[i], cy[stp++] = y[i];
    }
    for(ll i=n-2, t = stp+1;i>=0;i--){
        while(stp >= t && ccw(cx[stp-2], cy[stp-2], cx[stp-1], cy[stp-1], x[i], y[i]) >=0)
            stp--;
        cx[stp] = x[i], cy[stp++] = y[i];
    }
    stp--;
    cout<<" The Hull is "<<endl;
    for(ll i=0;i<stp;i++)
        cout<<cx[i]<<" "<<cy[i]<<endl;

    return 0;

}