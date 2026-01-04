#include <vector>
using namespace std;

class maxHeap{
    vector<int> heap;

public:
    void percolateUp(){
        int i = heap.size() - 1;
        while (heap[i] > heap[(i-1)/2]){
            int temp = heap[(i-1)/2];
            heap[(i-1)/2] = heap[i];
            heap[i] = temp;
            i = (i-1)/2;
        }
    }

    void percolateDown(){
        int i = 0;
        bool notMax = true;
        while (notMax){
            if (i >= heap.size()){
                notMax = false;
            }else if(2*i+1 < heap.size() && 2*i+2 < heap.size()){
                if (heap[i] < heap[2*i+1] || heap[i] < heap[2*i+2]){ // not Max
                    if (heap[2*i+1] > heap[2*i+2]){
                        int temp = heap[2*i+1];
                        heap[2*i+1] = heap[i];
                        heap[i] = heap[2*i+1];
                        i = 2*i+1;
                    }else{
                        int temp = heap[2*i+2];
                        heap[2*i+2] = heap[i];
                        heap[i] = heap[2*i+2];
                        i = 2*i+2;
                    }
                }else{
                    notMax = false;
                }
            }else if(2*i+1 < heap.size()){
                if (heap[i] < heap[2*i+1]){
                    int temp = heap[2*i+1];
                    heap[2*i+1] = heap[i];
                    heap[i] = heap[2*i+1];
                    i = 2*i+1;
                }else{
                    notMax = false;
                }
            }else{
                notMax = false;
            }
        }
    }

    void insert(int v){
        heap.push_back(v);
        if (heap.size() > 1) percolateUp();
    }

    int remove(){
        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        percolateDown();
        return max;
    }

    int findMax(){
        return heap[0];
    }
};

class minHeap{
    vector<int> heap;

public:
    void percolateUp(){
        int i = heap.size() - 1;
        while(heap[i] < heap[(i-1/2)]){
            int temp = heap[(i-1)/2];
            heap[(i-1)/2] = heap[i];
            heap[i] = temp;
            i = (i-1)/2;
        }
    }

    void percolateDown(){
        int i = 0;
        bool notMin = true;
        while (notMin){
            if (i > heap.size()){
                notMin = false;
            }else if (2*i+1 < heap.size() && 2*i+2 < heap.size()){
                if (heap[i] > heap[2*i+1] || heap[i] > heap[2*i+2]){
                    if (heap[2*i+1] < heap[2*i+2]){
                        int temp = heap[2*i+1];
                        heap[2*i+1] = heap[i];
                        heap[i] = temp;
                        i = 2*i+1;
                    }else{
                        int temp = heap[2*i+2];
                        heap[2*i+2] = heap[i];
                        heap[i] = temp;
                        i = 2*i+2;
                    }
                }else{
                    notMin = false;
                }
            }else if (2*i+1 < heap.size()){
                if (heap[i] > heap[2*i+1]){
                    int temp = heap[2*i+1];
                    heap[2*i+1] = heap[i];
                    heap[i] = temp;
                    i = 2*i+1;
                }else{
                    notMin = false;
                }
            }else{
                notMin = false;
            }
        }
    }

    void insert(int v){
        heap.push_back(v);
        if (heap.size() > 1) percolateUp();
    }

    int remove(){
        int min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        percolateDown();
        return min;
    }

    int findMin(){
        return heap[0];
    }
};
