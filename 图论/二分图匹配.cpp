//����ͼƥ��
/*
��С�㸲�ǵĵ���=���ƥ����
��С·�����ǵı���=������n-���ƥ����
��������=��С·������=������n-���ƥ����
*/
//1.�������㷨 �����ƥ�� O(n*m)
vector<int> mp[MAX];
int link[MAX],used[MAX];
int dfs(int x)
{
	int i,to;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(!used[to])
		{
			used[to]=1;
			if(link[to]==-1||dfs(link[to]))
			{
				link[to]=x;
				return 1;
			}
		}
	}
	return 0;
}
int hungary(int n)//�������ƥ���� 
{
	mem(link,-1);
	int i,res=0;
	for(i=1;i<=n;i++)
	{
		mem(used,0);
		if(dfs(i)) res++;
	}
	return res;
}

