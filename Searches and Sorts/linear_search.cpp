#include <iostream>
using namespace std;

const int sizeOf = 5;
int myarray[sizeOf] = {12, 14, 18, 20, 21};

int linear_search(int target){
    for(int i=0; i < sizeOf; ++i){
        if (myarray[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){
    int target;
    cin >> target;
    cout << linear_search(target);
    return 0;
}