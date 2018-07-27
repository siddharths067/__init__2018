#include <iostream>
#include <random>
using namespace std;

typedef long long int ll;

int arr[1000000+10];
int main(){
    ll n, l, r, ans = 0;
    cin>>n;
    for(ll i=0;i<n;i++)
        arr[i] = i+1; // taking input here
    cin>>l>>r;
    ll q = 1000000;
    while(q--){
        ans = 0;
        for(ll i=l-1; i<r;i++)
            ans += arr[i], ans%=(1000000+7);
    }
    cout<<"Sum : "<<ans<<endl;
    return 0;
}