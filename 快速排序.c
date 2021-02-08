#include<stdio.h>
int qsort(int* p,int length)
{
	if (length<=1)return 0;
	int* cur = p;
	int* bottom = p + length - 1;  
	for (; ; )
	{
		if (*cur > *(cur + 1))
		{
			int t = *cur;
			*cur = *(cur + 1);
			*(cur + 1) = t;
			cur++;
		}
		else
		{
			int t = *(cur+1);
			*(cur + 1) = *bottom;
			*bottom = t;
			bottom--;
		}
		if (cur + 1 > bottom)break;
	}	
	qsort(cur+1,length-(cur-p)-1);
	qsort(p,cur-p);//开头，长度
}
int main()
{
	int a[10] = { 10,9,8,7,1000,5,4,3,2,1 };
	qsort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", a[i]);
	}

}
