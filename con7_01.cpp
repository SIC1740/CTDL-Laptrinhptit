#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int val;
	stack<int>st;
	while(cin >> s){
		if(s == "push"){
			cin >> val;
			st.push(val);
		}
		else if(s == "pop"){
			if(!st.empty()){
				st.pop();
			}
		}
		else if(s == "show"){
			if(st.empty()){
				cout << "empty";
			}
			else{
				stack<int>tmp;
				while(!st.empty()){
					tmp.push(st.top());
					st.pop();
				}
				while(!tmp.empty()){
					cout << tmp.top() << " ";
					st.push(tmp.top());
					tmp.pop();
				}
			}
			cout << endl;
		}
	}
	return 0;
}