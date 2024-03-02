/*Make it count*/
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define all(v) v.begin(),v.end()
#define f(i,a,b) for(int i=a; i<=b; ++i)
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
	cin >> t;
	while(t--){
        ll a, b, n, m, x;
        cin >>a >>b;
        while (b % a != 0){
            n = a;
            m = b;
            x = b / a;
            cout << 1 << "/" << x + 1 << " + ";
            a = (x + 1) * n - m;
            b = (x + 1) * b;
           
        }
        cout << 1 << "/" << b / a;
        cout <<'\n';
	}

   return 0;
}