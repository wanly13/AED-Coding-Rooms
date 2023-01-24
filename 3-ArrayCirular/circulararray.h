#include <iostream>
using namespace std;

template <class T>
class CircularArrayIterator{

};

template <class T>
class CircularArray{
 public:
    typedef CircularArrayIterator<T> iterator;
    iterator begin(){return CircularArrayIterator(front, this-> elements , tan);}
    iterator end(){return CircularArrayIterator(rear, this-> elements , tan);}

 private:
    T *array;
    int capacity, len = 0;
    int back, front;
    
 public:
    //CircularArray(int _capacity = 10){}
    //virtual ~CircularArray();
    CircularArray(int _capacity){
        this->capacity = _capacity;
        this->array = new T[_capacity];
        this->front = this->back = -1;//empty
    }
    

    void push_front(T data){
         if (is_full()) {
            return ;
        } else if (is_empty()) {
            front = back = 0;
        }
        front = prev(front);
        array[front] = data;
        len++;
    }
    
    void push_back(T data){
        is_empty() ? front=back=0 : back = next(back);
        array[back] = data; 
        len++;
    }
    
    void insert(T data, int pos);
    
    void pop_front(){
        if(is_empty()) back=front=0;
        front = next(front);
        len--;
        
    }
    
    void pop_back(){
        array[back] = array[back +1];
        back--;
        len--;
        
    }

    bool is_full(){
        return len == capacity ? true : false;
    }
    
    bool is_empty(){
        if(front == -1) return true;
        else return false;
    }
    
    void display() {
        if(is_empty()) return;
        int temp = front;
        while (front != back) {
            cout << array[front] << ' ';
            front = next(front);
        }
        cout << array[front] << '\n';
        front = temp;
    }

    int size(){
        int temp = front;
        int size=0;
        while(array[temp] != 0){
            temp = next(temp);
            size++;
        }
        return size;

    }
    
    void clear(){
         delete []array;
        back = front = -1;
        len = 0;
        new T[capacity];
    }
    
    T &operator[](int index){
		return array[(this->front + index) % this->capacity];
    }
    
    void sort(){
        for(int i = front; i != back - 1; i = next(i)){
		int min_idx = i;
		for (int j = next(i); j != next(back); j=next(j))
			if (array[j] < array[min_idx])
				min_idx = j;
        T temp = array[min_idx];
        array[min_idx]=array[i];
        array[i]= temp;
      }
    }
    
    bool is_sorted(){
        int* temp = new int(front);
        while (*temp != back) {
            if (array[*temp] > array[next(*temp)]) return false;
            *temp = next(*temp);
        }
        return true;
    }
    
    void reverse(){
        int * temp1=new int(front), * temp2=new int(back),* c=new int(len/2);
        while((*c)--){
            swap(array[back],array[front]);
            front = next(front);
            back = prev(back);
        }
        front = *temp1;
        back = *temp2;
        delete temp1;
        delete temp2;
        delete c;
    }
    
    string to_string(){
        string result = "";
         //if(is_empty()) return;
        int temp = front;
        while (front != back) {
            result += std::to_string(array[front])+ " ";
            front = next(front);
        }
        result += std::to_string(array[front]) + " ";
        front = temp;
        return result;
        
    }

private:
    int next(int index){
        return (index+1)%capacity;
    }
    int prev(int index){
        return (index == 0) ? capacity - 1 : index - 1;
    }
};
