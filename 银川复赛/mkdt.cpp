#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout<<16<<endl;
	srand((unsigned)time(0));
	for(int i=1;i<=16;i++)
	cout<<rand()%10+1<<" "<<rand()%10+1<<endl;
	cout<<0<<endl;
}
