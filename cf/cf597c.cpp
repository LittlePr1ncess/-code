#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
const LL p = 1e9+7;
int n;LL ans=1,fib[100005],last=1;string s,S;
int main()
{
	//cout<<s[1]; 
	cin>>s; n=s.size();
	/*so(i,0,n,1) {
		s[i+1]=S[i];if(s[i+1]=='w'||s[i+1]=='m'){
			cout<<0<<endl; 
			return 0;
		}
	}n++;*/
	//n=100000;
	/*if(n>=100) {
		cout<<n<<endl;return 0;
	}*/
	//n= 100; 
	fib[1]=1,fib[2]=2,fib[3]=3;//n=1000;
	so(i,4,n+10,1) fib[i]=fib[i-1]+fib[i-2],fib[i]%=p;
	//so(i,1,n,1) cout<<fib[i]<<endl;
	//cout<<fib[n]<<endl;
	so(i,0,n-1,1)
	{
		if(s[i]=='w'||s[i]=='m') {
			cout<<0;return 0;
		}
		if(s[i]==s[i+1]) last++;
		else {
			if(s[i]=='u'||s[i]=='n') ans*=fib[last],ans%=p;  
			last=1;
		}
	}
	/*int j =0 ;
	for(int i = 0; i < n; i = j)
	{ 
		if(s[i]=='w'||s[i]=='m') {
			cout<<0;return 0;
		}
		while(j < n && s[j] == s[i]) j++; 	
		if(s[i] == 'n' || s[i] == 'u') 
		ans  *= fib[j - i],ans %= p; 
	} */ 
	cout<<ans;
}
