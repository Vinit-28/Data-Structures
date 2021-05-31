#include<iostream>

using namespace std;

// Class to implement the Functionality of Double Ended Queue //
template<class Datatype>
class DoubleEndedQueue{

    
    private:
    
        // Declaration of Private Data Members //
        int front=-1,rear=-1,total_length=0;
        Datatype *queue;
    
        // Declaration of Private Member Functions //
        Datatype *resize_queue(int startfrom=0);

    public:

        // Declaration of Public Member Functions //

        void push_front(Datatype data);
        void push_back(Datatype data);
        bool pop_front();
        bool pop_back();
        int size();
        Datatype& operator[](int index);
        Datatype at(int index);
        Datatype front_element();
        Datatype back_element();

};




// Class MyQueue's Member Functions Definitions //



// Member Function to resize the queue //
template<class Datatype>
Datatype* DoubleEndedQueue<Datatype>::resize_queue(int startfrom){

    Datatype *new_pointer = new Datatype[total_length];

    int index = front;
    for(index; index<=rear; index+=1, startfrom+=1){

        new_pointer[startfrom] = queue[index];
    }
    return new_pointer;
}



// Member Function to Push data from front //
template<class Datatype>
void DoubleEndedQueue<Datatype>::push_front(Datatype data){

    if( front == -1 ){
        
        front += 1;
        total_length += 1;
        queue = resize_queue();
        rear += 1;
    }
    else{

        total_length += 1;
        queue = resize_queue(1);
        rear+=1;
    }

    queue[front] = data;
}



// Member Function to Push data from back //
template<class Datatype>
void DoubleEndedQueue<Datatype>::push_back(Datatype data){

    if( rear == -1 ){
        
        front += 1;
        total_length += 1;
        queue = resize_queue();
        rear += 1;
    }
    else{

        total_length += 1;
        queue = resize_queue();
        rear+=1;
    }

    queue[rear] = data;
}



// Member Function to Pop data from front //
template<class Datatype>
bool DoubleEndedQueue<Datatype>::pop_front(){

    if( front == -1 ){

        return false;
    }
    else if ( front == rear ){
        
        rear = -1;
        total_length -= 1;
        queue = resize_queue();
        front = -1;
    }
    else{

        total_length -= 1;
        front += 1;
        queue = resize_queue();
        front -= 1; // front = 0;
        rear -= 1;
    }

    return true;

}



// Member Function to Pop data from back //
template<class Datatype>
bool DoubleEndedQueue<Datatype>::pop_back(){

    if( rear == -1 ){

        return false;
    }
    else if ( front == rear ){
        
        rear = -1;
        total_length -= 1;
        queue = resize_queue();
        front = -1;
    }
    else{

        total_length -= 1;
        rear -= 1;
        queue = resize_queue();
        front = 0;
    }

    return true;

}



// Member Function to Overload the Subscript Operator //
template<class Datatype>
Datatype& DoubleEndedQueue<Datatype>::operator[](int index){

    return queue[index];
}



// Member Function to return the total length of the queue //
template<class Datatype>
int DoubleEndedQueue<Datatype>::size(){

    return total_length;
}



// Member Function to return the total length of the queue //
template<class Datatype>
Datatype DoubleEndedQueue<Datatype>::at(int index){

    return queue[index];
}



// Member Function to return the total length of the queue //
template<class Datatype>
Datatype DoubleEndedQueue<Datatype>::front_element(){

    return queue[front];
}



// Member Function to return the total length of the queue //
template<class Datatype>
Datatype DoubleEndedQueue<Datatype>::back_element(){

    return queue[rear];
}



// End of Class MyQueue's Member Functions Definitions //



// Demonstration //
int main(){

	DoubleEndedQueue<string> q1;

	q1.push_back("Vinit");
	q1.push_back("Yashwant");
	q1.push_back("Kunal");
	q1.push_back("Sandeep");
	q1.push_front("Aman");

	cout<<q1.front_element()<<endl;
	q1.pop_front();
	cout<<q1.front_element()<<endl;

	cout<<q1.back_element()<<endl;
	q1.pop_back();
	cout<<q1.back_element()<<endl;

	return 0;
}