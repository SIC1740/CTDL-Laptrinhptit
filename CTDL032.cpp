#include <bits/stdc++.h>
//#include <conio.h>
#define ep 0.00001
#define oo 1000000010
#define mod 1000000000
double const PI=4*atan(1);

int f[1111111],n,k;

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
   // freopen("A.in","r",stdin);
    // freopen("A.out","w",stdout);
     scanf("%d %d",&n,&k);
     f[0] = 2; f[1] = 2;
     for(int i = 2;i<=n;i++){
          if(i<=k) f[i] = (f[i-1]*2)%mod;
          else f[i] = (f[i-1]*2-f[i-k-1])%mod;
          if(f[i]<0) f[i]+=mod;
     }
     printf("%d\n",f[n]);
    }
  //  getch();
}