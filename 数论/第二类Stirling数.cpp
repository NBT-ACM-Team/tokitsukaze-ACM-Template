//�ڶ���Stirling��
//dp[i][j]��ʾi��Ԫ�ػ��ֵ�k���������ֵķǿպ�����ķ�������
ll dp[MAX][MAX];
void init()
{
	ll i,j;
	mem(dp,0);
	dp[1][1]=1;
	for(i=2;i<MAX;i++)
	{
		for(j=1;j<=i;j++)
		{
			dp[i][j]=(dp[i-1][j-1]+j*dp[i-1][j])%mod;
		}
	}
}

