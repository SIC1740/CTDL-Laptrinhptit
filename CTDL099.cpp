
/*Make it count*/
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define all(v) v.begin(),v.end()
#define f(i,a,b) for(ll i=a; i<=b; ++i)
#define fn(i,a,b) for(int i=a; i>=b; --i)
#define faster() ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
const int MOD=1e9+7;

using namespace std;

int main()
{
    faster();
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w", stdout);

    int t;
    cin >>t;
    while(t--){
        int n;
        cin >>n;
        int a[n+5];
        f(i,1,n) cin >>a[i];
        queue<int> q;
        f(i,1,n-1){
            int ok=0;
            f(j,i+1,n){
                if(a[i] < a[j]) {q.push(a[j]); ok =1 ;break;}
            }
            if(!ok) q.push(-1);
        }
        q.push(-1);
        while(!q.empty()){
            cout <<q.front() <<' ';
            q.pop();
        }
        cout <<'\n';
    }

   return 0;
}