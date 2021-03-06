#include<vector>
#include<iostream>

using namespace std;

// Class to Create and Implement the Functionality of an Heap //
template<class Datatype>
class MyHeap{

    private:
        
        // Declaration of Private Data Members //
        vector<Datatype> heap;
        int length=0;
        char heaptype;

        // Declaration of Public Member Functions //
        void heapify(int index);
        void balance_heap();
    
    public:
        
        // Declaration of Public Members Functions//
        MyHeap(char type='>');
        void push(Datatype data);
        bool pop();
        int size();
        int search_data(Datatype data);
        Datatype top();
        Datatype child_of(Datatype child);
        Datatype get_child(Datatype parent, string child_name="left");

};


// Start of Class MyHepa's Member Functions Definition //



// Class Constructor //
template<class Datatype>
MyHeap<Datatype>::MyHeap(char type){

    heaptype = type;
}



// Member Funtion to push data in the heap //
template<class Datatype>
void MyHeap<Datatype>::push(Datatype data){

    heap.push_back(data);
    length+=1;
    heapify(length-1);
}



// Member Funtion to heapify(balance) the heap after insertion //
template<class Datatype>
void MyHeap<Datatype>::heapify(int child_index){

    int parent_index,temp;
    while(true){

        parent_index = (child_index-1)/2;

        // If it's a Max Heap //
        if( heaptype == '>' ){
        
            if( heap[parent_index] < heap[child_index] ){

                temp = heap[parent_index];
                heap[parent_index] = heap[child_index];
                heap[child_index] = temp; 
            }  
            else
                return;
        }

        // If it's a Min Heap //
        else if( heaptype == '<' ){
            
            if( heap[parent_index] > heap[child_index] ){

                temp = heap[parent_index];
                heap[parent_index] = heap[child_index];
                heap[child_index] = temp;
            }
            else
                return;
        }

        child_index = parent_index;

        if( child_index==0 )
            break;

    }
    
}



// Member Function to pop data from the heap //
template<class Datatype>
bool MyHeap<Datatype>::pop(){

    if( length == 0 ){

        return false;
    }
    heap[0] = heap[length-1];
    heap.pop_back();
    length-=1;
    balance_heap();
    return true;
}



// Member Function to balance the heap after deletion //
template<class Datatype>
void MyHeap<Datatype>::balance_heap(){

    int current_index = 0, left_child, right_child, temp;

    while(true){

        left_child = ( (current_index*2) + 1 );
        right_child = ( (current_index*2) + 2 );

        // If we have only left child of the current node in the heap //
        if( left_child < length && right_child >= length ){

            if( ( heaptype == '>' && heap[current_index] < heap[left_child] ) || ( heaptype == '<' && heap[current_index] > heap[left_child] ) ){

                temp = heap[current_index];
                heap[current_index] = heap[left_child];
                heap[left_child] = temp;
            }
            else{
                
                return;
            }

        }
        // If we have only right child of the current node in the heap //
        else if( left_child >= length && right_child < length ){

            if( ( heaptype == '>' && heap[current_index] < heap[right_child] ) || ( heaptype == '<' && heap[current_index] > heap[right_child] ) ){

                temp = heap[current_index];
                heap[current_index] = heap[right_child];
                heap[right_child] = temp;
            }
            else{
                
                return;
            }

        }
        // If we have both childs of the current node in the heap //
        else{

            // If left child is greater than current node as well as right child //
            if( ( heaptype == '>' && heap[left_child] >= heap[right_child] && heap[left_child] > heap[current_index] ) || ( heaptype == '<' && heap[left_child] <= heap[right_child] && heap[left_child] < heap[current_index] )){

                temp = heap[current_index];
                heap[current_index] = heap[left_child];
                heap[left_child] = temp;

                current_index = left_child;
            }
            // If right child is greater than current node as well as left child //
            else if( ( heaptype == '>' && heap[left_child] <= heap[right_child] && heap[right_child] > heap[current_index] ) || ( heaptype == '<' && heap[left_child] > heap[right_child] && heap[right_child] < heap[current_index] ) ){

                temp = heap[current_index];
                heap[current_index] = heap[right_child];
                heap[right_child] = temp;

                current_index = right_child;
            }
            else{

                return;
            }
        }

    }
    
} 



// Member Function to get the top/first element of the heap //
template<class Datatype>
Datatype MyHeap<Datatype>::top(){

    Datatype temp;

    if( length > 0 ){

        temp = heap[0];
    }

    return temp;
}



// Member Function to get the total length/size of the heap //
template<class Datatype>
int MyHeap<Datatype>::size(){

    return length;
}



// Member Function to search return the index of an particular data //
template<class Datatype>
int MyHeap<Datatype>::search_data(Datatype data){

    for(int i=0; i<size(); i++){

        if( heap[i] == data )
            return i;
    }
    return -1;
}



// Member Function to get the parent data of a particular child in the heap //
template<class Datatype>
Datatype MyHeap<Datatype>::child_of(Datatype child){

    int index_of_child = search_data(child);
    
    return( heap[((index_of_child-1)/2)] );
}



// Member Function to get the data of child node of a particular node //
template<class Datatype>
Datatype MyHeap<Datatype>::get_child(Datatype parent, string child_name){

    int index_of_parent = search_data(parent);
    
    if( child_name == "left" )
        return( heap[ ( ( index_of_parent*2 ) + 1 ) ] );
    
    return( heap[ ( ( index_of_parent*2 ) + 2 ) ] );
} 



// End of Class MyHepa's Member Functions Definition //



// Demontrating the use of the above data structure //
int main(){

    MyHeap<int> heap('>');

    heap.push(10);
    heap.push(20);
    heap.push(30);
    heap.push(5);
    heap.push(50);

    cout<<"Top Element -> "<<heap.top()<<endl;
    heap.pop();
    cout<<"Top Element after Pop Operation -> "<<heap.top()<<endl;

    cout<<"Data 10 is the child of -> Data "<<heap.child_of(10)<<endl;
    cout<<"Data 30's left child -> "<<heap.get_child(30,"left")<<endl;
    cout<<"Data 30's right child -> "<<heap.get_child(30,"right")<<endl;
    
    return 0;
}


