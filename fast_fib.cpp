#include <iostream>
typedef long long int ll;
using namespace std;
ll tans[2][2];
void matmul(ll a[2][2], ll b[2][2], ll c[2][2], ll m, ll n, ll p){


    // initialize to zero matrix
    for(ll i=0;i<m;i++)
        for(ll j=0;j<p;j++)
            tans[i][j] = 0;
    // multiply matrix
    for(ll i=0;i<m;i++)
        for(ll j=0;j<p;j++)
            for(ll k=0;k<n;k++)
                tans[i][j] += a[i][k] * b[k][j];
    // Copy Matrix
    for(ll i=0;i<m;i++)
        for(ll j=0;j<p;j++)
            c[i][j] = tans[i][j];
}

int main(){
    ll fib[2][2] = {{1, 1}, {1, 0}}, c[2][2] = {{1,0},{0,0}}, temp[2][2], k, ans[2][2] = {{1, 0}, {0, 1}};
    cin>>k;
    k -= 1;
    while(k){
        if(k & 1){
            matmul(ans, fib, ans, 2, 2, 2);
        }
        matmul(fib, fib, fib, 2, 2, 2);
        k >>= 1;
    }
    matmul(ans, c, c, 2, 2, 1);
    cout<<c[0][0]<<endl;

}
