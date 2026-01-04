#include <iostream>
using namespace std;

const int sizeOf = 5;
int myarray[sizeOf] = {9, 8 ,5, 3, 1};

void bubble_sort(){
    int sorted = sizeOf;
    bool swap = true;
    while (swap){
        swap = false;
        for (int i = 0; i < sorted -1; i++){
            if (myarray[i] > myarray[i+1]){
                swap = true;
                int temp = myarray[i];
                myarray[i] = myarray[i+1];
                myarray[i+1] = temp;
            }
        }
        sorted--;
    }
}

int main(){
    bubble_sort();
    for (auto el:myarray){
        cout << el << " ";
    }
}