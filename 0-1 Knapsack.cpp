#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){

int n,w;
cin>>n>>w;
vector<int> weight(n) , value(n);

for(int i=0;i<n;i++){
	cin>>weight[i]>>value[i];
}

ll dp[n+1][w+1];
memset(dp, 0 ,sizeof(dp));

for(int i=1;i<=n;i++){
	ll cn = wt[i-1];
	for(int wt =1 ;wt<=w;wt++){
         if(wt>=cn){
         	dp[i][wt] = max( val[i-1]+ dp[i-1][wt-cn] , dp[i-1][wt]  );
         }
         else{
         	dp[i][wt] = dp[i-1][j];
         }
	}
}
cout<<dp[n][w];

}