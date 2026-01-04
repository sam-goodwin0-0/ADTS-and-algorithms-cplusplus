#include <iostream>
using namespace std;

const int sizeOf = 5;
int myarray[sizeOf] = {9, 8 ,5, 3, 1};

void my_selection_sort(){
    int sorted = 0;
    while (sorted < sizeOf){
        /*finding minimum in unsorted list*/
        int minIndex = sorted;
        for (int i = sorted; i < sizeOf; i++){
            if (myarray[i] < myarray[minIndex]){
                minIndex = i;
            }
        }
        /*swopping elements*/
        int temp = myarray[sorted];
        myarray[sorted] = myarray[minIndex];
        myarray[minIndex] = temp;
        for (auto el:myarray){
            cout << el << " ";
        }cout << endl;
        sorted++;
    }
}

void selection_sort(){
    for (int i = 0; i < sizeOf -1; i++){
        int minIndex = i;
        for (int j = i+1; j < sizeOf; j++){
            if (myarray[j] < myarray[minIndex]){
                minIndex = j;
            }
        }
        int temp = myarray[minIndex];
        myarray[minIndex] = myarray[i];
        myarray[i] = myarray[minIndex];
    }
}

int main(){
    selection_sort();
    for (auto el:myarray){
        cout << el << " ";
    }
}