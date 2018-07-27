#include <iostream>
using namespace std;
typedef long long int ll;

ll f(ll x){
    return (x < 2)? x : f(x - 1) + f(x - 2);
}

int main(){
    int n;
    cin>>n;
    cout<<f(n);
}
