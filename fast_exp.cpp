#include <iostream>
using namespace std;
typedef long long int ll;

int main(){
    ll a, n, mod = 1000000+7, ans = 1;
    cin>>a>>n;
    while(n){
        if(n&1){
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
        n >>= 1;
    }
    cout<<ans;
}