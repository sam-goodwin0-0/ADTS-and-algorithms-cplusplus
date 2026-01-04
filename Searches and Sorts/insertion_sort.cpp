using namespace std;

const int sizeOf = 5;
int myarray[sizeOf] = {9, 8 ,5, 3, 1};

void insertion_sort(){
    for (int i = 1; i < sizeOf; ++i){
        int j = i-1;
        while ((j >=0) && (myarray[j+1]<myarray[j])){
            int temp = myarray[j];
            myarray[j] = myarray[j+1];
            myarray[j+1] = temp;
            j--;
        }
    }
}

