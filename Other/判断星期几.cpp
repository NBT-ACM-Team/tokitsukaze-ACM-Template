//�ж����ڼ�
int judge(int y,int m,int d)
{
	int res;
	if(m==1||m==2) m+=12,y--;//1��2�µ���ǰһ���13,14��
	if((y<1752)||(y==1752&&m<9)||(y==1752&&m==9&&d<3)) res=(d+2*m+3*(m+1)/5+y+y/4+5)%7;
	else res=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
	return res+1;
} 
