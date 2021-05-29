/*
Program to find total number of integers divisible by, 2, 3, 5, or 7
less than given n.
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll; //64bit
typedef long double ld;  //80bit
#define endl "\n"
#define rep(i, end) for(ll i=0; i<end; i++)
#define repx(i, start, end) for(ll i=start; i<end; i++)
#define PB push_back
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(NULL)



void solve(){
    int count = 0, n;
    cin>>n;

    rep(i2, 2){
        rep(i3, 2){
            rep(i5, 2){
                rep(i7, 2){
                    int elemCount = 0, d = 1;
                    if(i2)  d *= 2, elemCount++;
                    if(i3)  d *= 3, elemCount++;
                    if(i5)  d *= 5, elemCount++;
                    if(i7)  d *= 7, elemCount++;

                    if(elemCount == 0)  continue;
                    int sign = -1;
                    if(elemCount & 1)   sign *= -1;
                    
                    count += sign * n / d; 
                    // cout<<elemCount<<" --> "<<sign<<" "<<d<<endl;
                }
            }
        }
    }
    cout<<count<<endl;
}


int main(){
    FASTIO;
    ll tt = 1;
    if(!tt) cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}
/*
g++ A/filename.cpp -o A/a.out && ./A/a.out
*/