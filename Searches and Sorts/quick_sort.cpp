#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> vec = {15, 1, 2 , 10, 8, 20, 25, 30, 8};

void mergesort(vector<int> &part){
    if (part.size() == 1) return;

    vector<int> first(part.begin(), part.begin()+part.size()/2), 
    second(part.begin()+part.size()/2, part.end());

    mergesort(first);
    mergesort(second);

    part = {};
    for (int i = 0; i < max(first.size(),second.size());++i){
        if (first[i] < second[i]){
            part.push_back(first[i]);
        }
    }
}

int main(){
    mergesort(vec);
    for (auto el:vec){
        cout << el << " ";
    }
}