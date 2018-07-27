#include <iostream>
using namespace std;

typedef long long int ll;

int arr[1000000+10];
int main(){
    int n, l, r, ans=0;
    cin>>n;
    for(ll i=0;i<n;i++){
        arr[i] = i+1; // taking input here
        arr[i] += arr[i-1];
        arr[i] %= (1000000+7);
    }
    cin>>l>>r;
    ll q = 1000000;
    while(q--)
        ans = arr[r-1] - arr[l-2];
    cout<<ans<<endl;

}