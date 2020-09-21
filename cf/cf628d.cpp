#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long x,y;
	cin>>x>>y;
	if(x==0&&y==0) {
		cout<<0;return 0;
	}
	if(x==y)
	{
		cout<<1<<endl;
		cout<<x;
		return 0;
	}
	if(x>y) {
		cout<<-1;
		return 0;
	}
	else 
	{
		if((y-x)%2){
			cout<<-1;
			return 0;
		}
		else {
			long long rwz=(y-x)/2;
			if((x+rwz)==(x^rwz)){
				cout<<2<<endl;
				cout<<x+rwz<<" "<<rwz;
			}		
			else{
				cout<<3<<endl;
				cout<<x<<" "<<rwz<<" "<<rwz;
			}
		}
	}
} 
