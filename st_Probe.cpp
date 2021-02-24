//Тестовое задание для поступающих в школу разработки Heads x IMPROVE.
//Задача
//На входе функция получает параметр n - натуральное число. Необходимо сгенерировать n-массивов, заполнить их случайными числами, каждый массив имеет случайный размер. Размеры массивов не должны совпадать. Далее необходимо отсортировать массивы. Массивы с четным порядковым номером отсортировать по возрастанию, с нечетным порядковым номером - по убыванию. На выходе функция должна вернуть массив с отсортированными массивами.

//Поскольку в условии задачи сказано, что размер массива может быть любым, оставил возможность массива размером от 0 до RAND_MAX-1 элементов.

#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;

double **f(unsigned );

unsigned *s;//Массив размеров.

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
 double **arr; //Требуемый массив массивов.
 srand(time(0));

 //Создание массива размеров.
 s= new unsigned[n];
 unsigned t=RAND_MAX;//Максимальный допустимый размер массива. //=10;
 unsigned *s_a=new unsigned[t];//Массив допустимых неповторяющихся размеров. 
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
 //Конец создания массива размеров. 

 //Генерация несортированного массива массивов.
 arr = new double * [n];
 for(unsigned i=0;i<n;i++)
 {
  arr[i] = new double[s[i]];
  for(unsigned j=0;j<s[i];j++)
   arr[i][j]=rand();
 }
 //Конец генерации несортированного массива массивов.

 //Сортировка массива массивов.
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
 //Конец сортировки массива массивов.
 }
 return arr;
}