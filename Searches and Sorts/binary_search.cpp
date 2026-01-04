#include <iostream>
using namespace std;

const int sizeOf = 5;
int myarray[sizeOf] = {12, 14, 18, 20, 21};

int binary_search_me(int target){
    int begin = 0;
    int end = sizeOf-1;
    int i = sizeOf/2;
    while (begin != end){
        if (target == myarray[i]){
            return i;
        }else if (target < myarray[i]){
            end = i;
            i = i/2;
        }else{
            begin = i;
            i += (sizeOf-i)/2;
        }
    }
    return -1;

}

int binary_search(int target){
    int begin = 0;
    int end = sizeOf-1;
    while (begin <= end){
        int mid = (begin+end)/2;
        if (target == myarray[mid]){
            return mid;
        }else if (target < myarray[mid]){
            begin = mid + 1;
        }else{
            end = mid -1;
        }
    }
    return -1;

}

int main(){
    int target;
    cin >> target;
    cout << binary_search(target);
    return 0;
}