#include<stdio.h>
#include<stddef.h>

void MaxSum(int array[],int len)
{
	if(NULL==array||len<=0)
	{
		return;
	}
	int curSum = 0, maxSum = 0;
	int i=0;
	for(i=0;i<len;i++)
	{
		curSum += array[i];
		{
		if(curSum<0)
			curSum = 0;
		}
		if(curSum>maxSum)
		{
			maxSum=curSum;
		}
	}
	if(maxSum == 0)
	{
		maxSum = array[0];
		for(i=1; i<len; i++)
		{
			if(array[i]>maxSum)
			{
				maxSum = array[i];
			}
		}
	}
	printf("最大子数组和maxSum为: %d\n", maxSum);
}

void main()
{
	int i;
	int a[6];
	FILE *fp;
	if((fp=fopen("input1.txt","r"))==NULL)
	{
		printf("can't open file\n");
		return;
	}
	for(i=0;i<6;i++)
	{
		fscanf(fp,"%d",&a[i]);
		fscanf(fp,"\n");
	}
	fclose(fp);
	printf("从input.txt中读取的数据为：");
	for(i=0;i<6;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	MaxSum(a,6);
}