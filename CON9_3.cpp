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
	int n, x;
    cin >> n;
    vector<vector<int>> a(n + 1);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> x;
            if (x == 1){
                a[i].push_back(j);
                //a[j].push_back(i);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (auto j : a[i])
            cout << j << " ";
        cout << endl;
    }
	return 0;
}