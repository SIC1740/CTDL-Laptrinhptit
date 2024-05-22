#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int t = 1;
	cin >> t;
	while(t--){
		int k;
		cin >> k;
		string s;
		cin >> s;
		map<char,int>mp;
		priority_queue<int>qe;
		long long res = 0;
		for(int i = 0; i < s.length(); ++i){
			mp[s[i]]++;
		}
		for(int i = 'A' ; i <= 'Z'; ++i){
			if(mp[i]){
				qe.push(mp[i]);
			}
		}
		while(k--){
			long long x = qe.top(); qe.pop();
			x--;
			qe.push(x);
		}
		while(!qe.empty()){
			long long t = qe.top();
			qe.pop();
			res += t*t;
		}
		cout << res << endl;
	}
}