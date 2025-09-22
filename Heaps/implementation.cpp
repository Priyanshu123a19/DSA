#include <iostream>
using namespace std;


//now over here we make a new implemenetation of heap\

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0]=-1;
        size=0;
    }

    //now over here we make a new insert function

    void insert(int val){
        size=size+1;
        int index=size;
        arr[index]=val;
        
        while(index>1){
            int parent= index/2;

            //now inserting the elemnt in the correct posistion 
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }
    //remember the delete will always delete the root node


    //to delete from the heap
    //frist we will put the last element in the root node place
    //then we will take the root node to its correct posistion
    //the rules are simple just swap the root node to left or right child which is greater than the root node
    //then make the root node new index as the left or right child index
    //repeat this process until the root node is greater than both the child nodes or we reach or both the right and left child index are greater than the size of the heap
    void deleteFromHeap(){
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return;
        }
       //step 1 put the last element in the root node place
       
       arr[1]=arr[size];
       size--;
         //step 2 take the root node to its correct posistion
        int i=1;
         while(i<size){
            int leftIndex=2*i;
            int rightIndex=2*i+1;

            //check for the left and right child
            if(leftIndex<size && arr[i]<arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i=leftIndex;
            }
            else if(rightIndex<size && arr[i]<arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i=rightIndex;
            }
            else{
                return;
            }
         }
    }

    void heapify(int arr[],int n,int i){
        //now u have to know a single thing that leaf nodes are already heapified
        //the leaf nodes start from n/2+1 to n
        //and so we just have to heapify from 1 to n/2
        //in that also we start from n/2 to 1

        //this function takes the index of the element to be heapified and the size of the heap and the array

        int largest=i;
        int left=i*2;
        int right=i*2+1;

        if(left<=n && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<=n && arr[largest]<arr[right]){
            largest=right;
        }
            
        //now check if the largest is not the root node
        //remember taht we are calling out the recursive function in the end after updateing the largest instead of calling it in the if condition
        //because we have to check both the left and right child before calling the recursive function
        //the largest will be updated to the correct index before calling the recursive function
        //so u only have to update the largest and then call the recursive function
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }


    }
};


// REMEMBER WHAT IS A HEAP 
//A HEAP IS A COMPLETE BINARY TREE
//MAX HEAP AND MIN HEAP
//IN MAX HEAP THE PARENT NODE IS ALWAYS GREATER THAN THE CHILD NODES
//IN MIN HEAP THE PARENT NODE IS ALWAYS LESS THAN THE CHILD NODES
//THE ROOT NODE IS THE MAXIMUM ELEMENT IN THE MAX HEAP
//THE ROOT NODE IS THE MINIMUM ELEMENT IN THE MIN HEAP
//THE LEAF NODES ARE THE NODES WHICH DO NOT HAVE ANY CHILD NODES
//THE HEIGHT OF THE HEAP IS THE NUMBER OF EDGES ON THE LONGEST PATH FROM THE ROOT NODE TO A LEAF NODE
//THE HEIGHT OF THE HEAP IS LOG(N) WHERE N IS THE NUMBER OF NODES
//THE TIME COMPLEXITY OF INSERTION IN A HEAP IS O(LOG N)
//THE TIME COMPLEXITY OF DELETION IN A HEAP IS O(LOG N)
//THE TIME COMPLEXITY OF BUILDING A HEAP IS O(N)
//THE TIME COMPLEXITY OF HEAP SORT IS O(N LOG N)