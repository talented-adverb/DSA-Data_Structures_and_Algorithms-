#include<iostream>
#include<climits>
using namespace std;

class heap {
public:
    int A[100];
    int size;

    heap() {
        A[0] = INT_MIN;  
        size = 0;
    }

    int heap_max(){
        return A[1];
    }

    void max_heapify(int arr[],int index){
        int lar;
        int left=index-1;
        int right=index+1;
        if(left<size  && arr[left]>arr[index]) lar=left;
        else lar=index;
        if(right<size && arr[right]>arr[index]) lar=right;
        if(lar!=index){
            swap(arr[index],arr[lar]);
            max_heapify(arr,lar);
        }
    }

    int extract_max(){
        if (size<1) cout<<"heap underflow";
        int max=A[1];
        A[1]=A[size];
        size=size-1;
        max_heapify(A,1);
        return max;
    }

    void heap_increase_key(int arr[], int index, int key) {
        if (key < arr[index]) {
            cout << "Error: Key is smaller" << endl;
        }
        A[index] = key;
        while (index > 1 && A[index / 2] < A[index]) {
            swap(A[index], A[index/2]);
            index = index / 2;
        }
    }

    void max_heap_insert(int val) {
        size = size + 1;
        A[size] = INT_MIN; 
        heap_increase_key(A, size, val);
    }

    void display() {
        for (int i = 1; i <=size; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    heap h1;
    h1.max_heap_insert(2);
    h1.max_heap_insert(4);
    h1.max_heap_insert(3);
    h1.display();
    cout<<h1.extract_max()<<"\n";
    h1.display();
    cout<<h1.heap_max();
    return 0;
}
