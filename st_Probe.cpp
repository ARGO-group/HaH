//�������� ������� ��� ����������� � ����� ���������� Heads x IMPROVE.
//������
//�� ����� ������� �������� �������� n - ����������� �����. ���������� ������������� n-��������, ��������� �� ���������� �������, ������ ������ ����� ��������� ������. ������� �������� �� ������ ���������. ����� ���������� ������������� �������. ������� � ������ ���������� ������� ������������� �� �����������, � �������� ���������� ������� - �� ��������. �� ������ ������� ������ ������� ������ � ���������������� ���������.

//��������� � ������� ������ �������, ��� ������ ������� ����� ���� �����, ������� ����������� ������� �������� �� 0 �� RAND_MAX-1 ���������.

#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;

double **f(unsigned );

unsigned *s;//������ ��������.

int main(int argc, char** argv) 
{
 unsigned n=10;
 double **arr;
 arr=f(n);

 for(unsigned i=0;i<n;i++)
 {
  for(unsigned j=0;j<s[i];j++)
   cout<<arr[i][j]<<' ';
  cout<<endl;
 }
 cout<<endl;

return(0);
}

double **f(unsigned n)
{
 double **arr; //��������� ������ ��������.
 srand(time(0));

 //�������� ������� ��������.
 s= new unsigned[n];
 unsigned t=RAND_MAX;//������������ ���������� ������ �������. //=10;
 unsigned *s_a=new unsigned[t];//������ ���������� ��������������� ��������. 
 for(unsigned i=0;i<t;i++)
  s_a[i]=i;

 for(unsigned i=0;i<n;i++)
 {
  unsigned tmp=rand()%t;
  s[i]=s_a[tmp];
  for(unsigned j=tmp;j<t-1;j++)
   s_a[j]=s_a[j+1];
  t--;
 }
 //����� �������� ������� ��������. 

 //��������� ���������������� ������� ��������.
 arr = new double * [n];
 for(unsigned i=0;i<n;i++)
 {
  arr[i] = new double[s[i]];
  for(unsigned j=0;j<s[i];j++)
   arr[i][j]=rand();
 }
 //����� ��������� ���������������� ������� ��������.

 //���������� ������� ��������.
 for(unsigned i=0;i<n;i++)
 {
  for(unsigned j=0;j<s[i];j++)
   for(unsigned k=0;k<s[i];k++)
	if((arr[i][j]>arr[i][k] && i%2==0)||(arr[i][j]<arr[i][k] && i%2!=0))
	{
	 double tmp=arr[i][j];
     arr[i][j]=arr[i][k];
	 arr[i][k]=tmp;
	}
 //����� ���������� ������� ��������.
 }
 return arr;
}