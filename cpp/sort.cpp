#include<iostream> 
#include<cstdlib>
#include<ctime>
#include<time.h>
using namespace std;
template<class T>void MergeSort(T a[],int left,int right); 
template<class T>void Merge(T c[],T d[], int l,int m,int r); 
template<class T>void Copy(T a[],T b[],int l,int r); 
template<class T>void QuickSort(T a[],int p,int r); 
template<class T>int Partition(T a[],int p,int r); 
int main() 
{ 
       int a[1000]; 
       clock_t start,finish;
       std::cout<<"======MergeSort======"<<endl; 
       std::cout<<"array size "<<" | "<<" time(us)"<<endl; 
       for(int n =1;n<11;n++){
          start = clock();
          for(int k=0;k<100000;k++){
              srand(time(NULL));  
              for(int i=0;i<n*100;i++){ 
                  a[i] = rand(); 
              }
              MergeSort(a,0,n-1);
          } 
          finish = clock();
          std::cout<<"    "<<n*100<<"        "<<(float(finish-start)/100000)<<endl;
       }
/////////////////////////////////////////////////////////
       std::cout<<"======QuickSort======"<<endl; 
       std::cout<<"array size "<<" | "<<" time"<<endl; 
       for(int n =1;n<11;n++){
          start = clock();
          for(int k=0;k<100000;k++){
              srand(time(NULL));  
              for(int i=0;i<n*100;i++){ 
                  a[i] = rand(); 
              }
              QuickSort(a,0,n-1);
          } 
          finish = clock();
          std::cout<<"    "<<n*100<<"        "<<(float(finish-start)/100000)<<endl;
       }
       return 0;
} 
 
template<class T> 
void MergeSort(T a[],int left,int right) //   
{ 
       if(left<right) 
       { 
              int i=(left+right)/2; 
              T *b = new T[left+right];
              MergeSort(a,left,i); 
              MergeSort(a,i+1,right); 
              Merge(a,b,left,i,right); 
              Copy(a,b,left,right);  
	   }
} 
 
template<class T> 
void Merge(T c[],T d[],int l,int m,int r) 
{ 
       int i=l; 
       int j=m+1; 
       int k=l; 
       while((i<=m)&&(j<=r)) 
       { 
              if(c[i]<=c[j])d[k++]=c[i++]; 
              else d[k++]=c[j++]; 
       } 
       if(i>m) 
       { 
              for(int q=j;q<=r;q++) 
                     d[k++]=c[q]; 
       } 
       else   
              for(int q=i;q<=m;q++) 
                     d[k++]=c[q]; 
} 
 
template<class T> 
void Copy(T a[],T b[], int l,int r) 
{ 
       for(int i=l;i<=r;i++) 
              a[i]=b[i]; 
}

////////////////////////////////////////////////////////////////////
template<class T> 
void QuickSort(T a[],int p,int r) 
{ 
       if(p<r) 
       { 
              int q=Partition(a,p,r); 
              QuickSort(a,p,q-1); 
              QuickSort(a,q+1,r); 
       } 
} 
 
template<class T> 
int Partition(T a[],int p,int r) 
{ 
       int i=p,j=r+1; 
       T x=a[p]; 
       while(true) 
       { 
              while(a[++i]<x); 
              while(a[--j]>x); 
              if(i>=j)break; 
              Swap(a[i],a[j]); 
       } 
       a[p]=a[j]; 
       a[j]=x; 
       return j; 
} 
 
template<class T> 
inline void Swap(T &s,T &t) 
{ 
       T temp=s; 
       s=t; 
       t=temp; 
}







