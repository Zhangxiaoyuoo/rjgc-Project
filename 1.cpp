#include "fstream.h"
#include "iostream.h"
#define MAXSIZE 50

//*****读取数组信息*****
void ReadArr(int arr[][MAXSIZE],int &len1,int &len2)
{
    ifstream infile("input.txt");
    if(!infile)
        cout<<"读取失败！"<<endl;
    else
    {
        infile>>len1>>len2;
        for(int i=0;i<len1;i++)
        {
            for(int j=0;j<len2;j++)
            {
                infile>>arr[i][j];
            }
        }
    }
}
//*****显示矩阵*****
void ShowArr(int arr[][MAXSIZE],int len1,int len2,int size1,int size2)
{
    for(int i=len1;i<=size1;i++)
    {
        for(int j=len2;j<=size2;j++)
        {
            cout<<arr[i][j]<<"   ";
        }
        cout<<endl;
    }
}
//*****求和公式*****
int GetSum(int arr[][MAXSIZE],int len1,int len2,int size1,int size2)
{
    int sum=0;
    for(int i=len1;i<=size1;i++)
    {
        for(int j=len2;j<=size2;j++)
        {
            sum+=arr[i][j];
        }
    }
    return sum;
}

int main(int argc, char* argv[])
{
    int len1,len2,max,sum;                        //len1是行数,len2是列数
    int line1,line2,row1,row2;                    //和最大的矩阵的两个坐标
    int arr[MAXSIZE][MAXSIZE];
    ReadArr(arr,len1,len2);
    cout<<"从input.txt中读取的二维数组为："<<endl;
    ShowArr(arr,0,0,len1-1,len2-1);
    cout<<endl;
    line1=0;
    line2=0;
    row1=0;
    row2=0;
    sum=0;
    max=arr[0][0];
    for(int i=0;i<len1;i++)                        //第一个数的行数
    {
        for(int j=0;j<len2;j++)                    //第一个数的列数
        {
            for(int m=i;m<len1;m++)                //第二个数的行数
            {
                for(int n=j;n<len2;n++)
                {                                //第二个数的列数
                    sum=GetSum(arr,i,j,m,n);    //求出这两个数构成的矩阵的和
                    if(sum>max)
                    {
                        max=sum;
                        line1=i;                //保存第一个数的行
                        line2=m;                //保存第二个数的行
                        row1=j;                    //保存第一个数的列
                        row2=n;                    //保存第二个数的列
                    }
                }
            }
        }
    }
    cout<<"和最大的子矩阵为："<<endl;
    ShowArr(arr,line1,row1,line2,row2);
    cout<<"\n最大子数组的和："<<max<<endl;
    return 0;
}