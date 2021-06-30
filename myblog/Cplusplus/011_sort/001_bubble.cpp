#include <iostream>

using namespace std;

int main(){
    int arr[] = {12,13,25,1,23,54,24,67,15,16,46};
    int len = sizeof(arr)/sizeof(int);

    for(int i = 0; i < len -1; i++){
        for (int j = 0; j < len - 1 - i; j++){
            if (arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }

    for (int i = 0; i < len; i++){
        cout << arr[i] << '\t';
    }
    return 0;
}