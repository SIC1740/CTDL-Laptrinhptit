//Sinh xâu nhị phân N bit
#include<bits/stdc++.h>
using namespace std;
#define int long long

void sinh(int n, string str, vector<string>&res){
	if(n == 0){
		res.push_back(str);
	}
	else{
		sinh(n-1,str+"0",res);
		sinh(n-1,str+"1",res);
	}
}
void implement(){
	int n;
	cin >> n;
	vector<string>res;
	sinh(n,"",res);
	for(auto &bin : res){
		for(auto &x : bin){
			cout << x << " ";
		}
		cout << endl;
	}
}
signed main(){
	int t;
	cin >> t;
	while(t--){
		implement();
	}
}