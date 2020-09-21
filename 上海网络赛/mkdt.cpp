#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("in.txt","w",stdout);
	cout<<2<<endl;
	cout<<1000000<<" "<<999999<<endl;
	for(int i=1;i<=999999;i++)
	cout<<i<<" "<<(i+1)<<endl;
	cout<<1000000<<" "<<1010<<endl;
	int op=1;
	for(int i=1;i<=1000;i++)
	{
		cout<<op<<" "<<op+499<<endl; op+=500;
	}
	op=251;
	for(int i=1;i<=10;i++)
	{
		cout<<op<<" "<<op+999<<endl; op+=1000;
	}
	//for(int i=1;i<=10000;i++)
	//cout<<1000000<<" "<<2<<endl;
}
