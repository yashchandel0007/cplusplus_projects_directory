#include <iostream>

using namespace std;

int pivot_partition(int a[], int low, int high){
    int i = low-1;
    int pivot = a[high];

    for(int j=low;j<high;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[++i],a[high]);
    return i;
}
void quicksort(int a[], int low, int high){
    if(low<high){
       int pivot = pivot_partition(a,low,high);
       quicksort(a,low,pivot-1);
       quicksort(a,pivot+1,high);
    }
}
int main()
{
    cout << "quicksort" << endl;

    int a[10] = {3,4,5,6,2,1,7,8,9,10};
    cout<<"Before quicksorting: ";

    for(int i = 0; i <10; i++)
        cout<<a[i]<<" ";
    cout<<endl;

    quicksort(a,0,9);

    cout<<"After quicksorting: ";
    for(int i = 0; i <10; i++)
        cout<<a[i]<<" ";
    return 0;
}
