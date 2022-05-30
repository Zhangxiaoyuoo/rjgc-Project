#include "fstream.h"
#include "iostream.h"
#define MAXSIZE 50

//*****��ȡ������Ϣ*****
void ReadArr(int arr[][MAXSIZE],int &len1,int &len2)
{
    ifstream infile("input.txt");
    if(!infile)
        cout<<"��ȡʧ�ܣ�"<<endl;
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
//*****��ʾ����*****
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
//*****��͹�ʽ*****
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
    int len1,len2,max,sum;                        //len1������,len2������
    int line1,line2,row1,row2;                    //�����ľ������������
    int arr[MAXSIZE][MAXSIZE];
    ReadArr(arr,len1,len2);
    cout<<"��input.txt�ж�ȡ�Ķ�ά����Ϊ��"<<endl;
    ShowArr(arr,0,0,len1-1,len2-1);
    cout<<endl;
    line1=0;
    line2=0;
    row1=0;
    row2=0;
    sum=0;
    max=arr[0][0];
    for(int i=0;i<len1;i++)                        //��һ����������
    {
        for(int j=0;j<len2;j++)                    //��һ����������
        {
            for(int m=i;m<len1;m++)                //�ڶ�����������
            {
                for(int n=j;n<len2;n++)
                {                                //�ڶ�����������
                    sum=GetSum(arr,i,j,m,n);    //��������������ɵľ���ĺ�
                    if(sum>max)
                    {
                        max=sum;
                        line1=i;                //�����һ��������
                        line2=m;                //����ڶ���������
                        row1=j;                    //�����һ��������
                        row2=n;                    //����ڶ���������
                    }
                }
            }
        }
    }
    cout<<"�������Ӿ���Ϊ��"<<endl;
    ShowArr(arr,line1,row1,line2,row2);
    cout<<"\n���������ĺͣ�"<<max<<endl;
    return 0;
}