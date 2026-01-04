#include <iostream>
using namespace std;

int *myVec = new int[5];

int main(){

    cout << myVec[0];

    delete [] myVec;
}