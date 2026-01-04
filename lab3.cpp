#include <iostream>
using namespace std;

class myQueue{
public:
    int* data;
    int n_items;
    int n_allocated;
    int idx_front;

    myQueue(){
        data = nullptr;
        n_items = 0;
        n_allocated = 0;
        idx_front = 0;
    }

    int size() const{
        return n_items;
    }

    int capacity() const{
        return n_allocated;
    }

    int index(int i){
        return (idx_front+i)%n_allocated;
    }

    int& front(){
        if (n_items == 0) throw std::runtime_error("queue is empty");
        return data[idx_front];
    }

    void enqueue(const int& v){
        if (n_allocated == 0){
            reallocate(1);
            data[0] = v;
        }else{
            if (n_items >= n_allocated){
                reallocate(2*n_allocated);
            }
            int back = index(n_items);
            data[back] = v;
        }
        ++n_items;
    }

    void dequeue(){
        if (n_items == 0) return;
        n_items--;
        idx_front = index(1);
        if (n_items < n_allocated/4){
            reallocate(n_allocated/2);
        }
    }

    void reallocate(int new_size){
        int* new_buffer = new int[new_size];
        for (int i = 0; i < n_items; i++){
            int idx = index(i);
            new_buffer[i] = data[idx];
        }
        idx_front = 0;
        n_allocated = new_size;
        delete [] data;
        data = new_buffer;
    }

};
