//�����������(>)nlogn ���س��� 
//��½�������(<) ��ԭ����ȡ���� 
int a[MAX],b[MAX],n;
int LIS()
{
	int i;
	mem(b,0x3f);
	for(i=0;i<n;i++)
	{
		*lower_bound(b,b+n,a[i])=a[i];//����½�������(>=)��Ϊupper_bound 
	}
	return lower_bound(b,b+n,INF)-b;
}
