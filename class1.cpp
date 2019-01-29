#include <iostream>
#include <stdio.h>
using namespace std;

class Double_Vector
{
private:
    double *data;
    unsigned int size;
    unsigned capacity;
public:
  Double_Vector();
  Double_Vector(double mas[],unsigned int n);
  Double_Vector(const Double_Vector& A);
  ~Double_Vector();

  void get_Double_Vector();
  void set_Double_Vector(double* data, unsigned int size);

  const Double_Vector& operator=(const Double_Vector& A);
  double operator[](unsigned int n);
  const Double_Vector& operator+(const Double_Vector& A,const Double_Vector& B);

  void push_back1(double x);
  double pop_back1();

  void recize(int z);
  void push_front(double x);
  void push_back(double x);
  void insert(double x,int a);

  void eraze(int a);
  void eraze_interval(int a,int b);

  double find_element(double x);
  bool is_sort(const Double_Vector& A);
  double find_binary(double Arr[],double x,int l,int r);

  unsigned int size();
  unsigned int capacity();
};
unsigned int size()
{
    return size;
}
unsigned int capacity()
{
    return capacity;
}
const Double_Vector& operator=(const Double_Vector& A)
{
    swap(Double_Vector &A);
    return *this;
}
const Double_Vector& operator+(const Double_Vector& A,const Double_Vector& B)
{
    double* temp=new double[size_A+size_B];
    for (int i=0;i<size_A;i++)
        temp[i]=data_A[i];
    for (int k=size_A;k<size_B;k++)
        temp[k]=data_A[k-size_A];
     delete[]data;
     data=temp;

}
double operator[](unsigned int n)
{
    return data[n];
}
void push_back1(double x)
{
    if (size>=capacity)
    {
        capacity*=z;
        double* temp = new double[capacity];
        for (int i=0;i<size;i++)
            temp[i]=data[i];
        delete[]data;
        data=temp;
        data[size]=x;
        size++;
    }
}
double pop_back1()
{
    double f=data[size];
    double* temp=new double[size-1];
    for (int i=0;i<size-1;i++)
        temp[i]=data[i];
    return data[size];
}
void push_front(double x)
{
  double* temp = new double[size+1];
  temp[0]=x;
        for (int i=1;i<size+1;i++)
            temp[i]=data[i];
        delete[]data;
        data=temp;
}
void push_back(double x)
{
    double* temp = new double[size+1];
    temp[size+1]=x;
        for (int i=0;i<size;i++)
            temp[i]=data[i];
        delete[]data;
        data=temp;
}
void recize(double z)
{
        capacity*=z;
        double* temp = new double[capacity];
        for (int i=0;i<size;i++)
            temp[i]=data[i];
        delete[]data;
        data=temp;
}
void insert(double x,int a)
{
    double* temp = new double[size];
        for (int i=0;i<size;i++)
        {
            if (i!=a)
              temp[i]=data[i];
            else
               temp[i]=x;
        }
     delete[]data;
     data=temp;
}
void eraze(int a)
{
    double* temp = new double[size-1];
        for (int i=0;i<a;i++)
              temp[i]=data[i];
        for (int k=a;k<size-1;k++)
              temp[k]=data[k+1];
     delete[]data;
     data=temp;
}
void eraze_interval(int a,int b)
{
    int c=b-a;
    double* temp=new double[size-c];
     for (int i=0;i<a;i++)
          temp[i]=data[i];
     for (int k=a;k<size-c;k++)
          temp[k]=data[k+c];
     delete[]data;
     data=temp;
}

double find_element(double x)
{
    for (int i=0;i<size;i++)
    {
        if (data[i]==x)
            return i;
    }
}

bool is_sort(const double_vector& A)
{
    int k=0;
    int s=0;
    for (int i=0;i<size_A;i++)
    {
        if (data_A[i]<data_A[i+1])
            k++;
        else
            s++;

    }
    if ((s==size_A)||(k==size_A))
        return 1;
    else return 0;
}
template class <Double_Vector> double find_binary(double Arr[],double x,int l,int r)
{
    if (is_sort==true)
    {
    double mid=(l+r)/2;
         if (Arr[mid]==x)
            return mid;
         if (Arr[mid]<x)
            find_binary(Arr,x,mid+1,r);
         if (Arr[mid]>x)
            find_binary(Arr,x,l,mid-1);
    }
    else printf("array wasn't sorted :(((");
}
void get_Double_Vector()
{
    printf("enter size\n");
    scanf("%d",&size);
    printf("enter capacity\n");
    scanf("%d",&capacity);
    for (int i=0;i<size;i++)
        scanf("%f",&data[i]);
}
void set_Double_Vector(double* data_A,unsigned int size_A)
{
    for (int i=0;i<size_A;i++)
    printf("%f\n",data_A[i]);
}
Double_Vector::Double_Vector()
{
    size = 1;
    data=new double[1];
    data[0]=0;
}
Double_Vector::Double_Vector(unsigned int n)
{
    size = n;
    data=new double[n];
    for (int k=0;k<n;k++)
    {
        data[k]=0;
    }
}
Double_Vector::Double_Vector(double mas[],unsigned int n)
{
    size = n;
    data=new double[n];
    for (int k=0;k<n;k++)
        data[k]=mas[k];
}
Double_Vector::~Double_Vector()
{
    delete []data;
}
int main()
{
    set_Double_Vector();
    get_Double_Vector(&data,size);
    return 0;
}
