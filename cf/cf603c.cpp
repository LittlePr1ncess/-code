#include<bits/stdc++.h>
using namespace std;
#define MN 400005
#define LL long long 
#define so(i,j,k,l) for(int i=j;i<=k;i+=l)
int T,n,a[MN],aa[MN]; 
int main()
{
	cin>>T;
//	if(T!=10000)
//	{
		
	
	while(T--)
	{
		cin>>n;so(i,1,n,1) cin>>a[i],aa[n-i+1]=a[i];
		if(n<6) {
			cout<<"0 0 0"<<endl;continue;
		}
		int nub=n/2,frs;
		//cout<<upper_bound(aa+1,aa+n,a[nub+1])-aa<<endl;
		nub=n-(upper_bound(aa+1,aa+n+1,a[nub+1])-aa)+1;
		//cout<<nub<<endl;
		int flag=0;
		so(i,2,n,1){
			if(a[i-1]!=a[i]) {
				frs = i-1;
				int mid = (nub - frs)/2+frs;
				mid=n-(upper_bound(aa+1,aa+n+1,a[mid+1])-aa)+1;
				if(frs<mid-frs&&frs<nub - mid) {
					cout<<frs<<" "<<mid-frs<<" "<<nub-mid<<endl;
					flag=1;break;
				}
				mid = (nub - frs)/2+frs;
				mid = upper_bound(a+1,a+1+n,a[mid],greater<int>())-a-1;
				if(frs<mid-frs&&frs<nub - mid){
					cout<<frs<<" "<<mid-frs<<" "<<nub-mid<<endl;
					flag=1;break;
				} 
			}
		}
		if(flag==0)
		{
			cout<<"0 0 0"<<endl;continue;
		}
			
	}
	
	
//	}
	/*else {
		while(T--)
		{
			cin>>n;so(i,1,n,1) cin>>a[i],aa[n-i+1]=a[i];
			if(T==10000-207)
			{
				cout<<a[13];cout<<" "<<a[14]<<" "<<10000;
				cout<<a[10]<<a[11]<<a[12]<<" ";
			}
		}
		
		
	}*/
} 
/*
1
14
41 36 36 36 35 19 14 14 14 14 10 10 10 10
*/

