//sg����
//f[m]:�ɸı䵱ǰ״̬�ķ�ʽ��NΪ��ʽ�����࣬Ҫ�ȴ�С����sort 
//sg[]:0~n��sg����ֵ
//flag[m]:Ϊx���״̬�ļ���

//sg�� 
int f[111],sg[MAX];
void SG(int n,int m)
{
	int i,j,flag[111];
	mem(sg,0);
	for(i=1;i<=n;i++)
	{
		mem(flag,0);
		for(j=0;f[j]<=i&&j<m;j++)
		{
			flag[sg[i-f[j]]]=1;
		}
		for(j=0;;j++)
		{
			if(!flag[j])
			{
				sg[i]=j;
				break;
			}
		}
	}
}

//���仯������sg��
int f[105],sg[MAX],m;
int dfs(int x)
{
	int i,j,flag[105];
	if(sg[x]!=-1) return sg[x];
	mem(flag,0);
	for(i=1;i<=m;i++)
	{
		if(x>=f[i])
		{
			dfs(x-f[i]);
			flag[sg[x-f[i]]]=1;
		}
	}
	for(i=0;;i++)
	{
		if(!flag[i])
		{
			j=i;
			break;
		}
	}
	return sg[x]=j;
}

