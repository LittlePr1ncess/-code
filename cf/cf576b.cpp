#include<bits/stdc++.h>
using namespace std;
double H,L,ans;
int main()
{
	cin>>H>>L;
	ans=(L*L/H-H)*0.5;
	printf("%.13lf",ans);
	return 0;
} 
