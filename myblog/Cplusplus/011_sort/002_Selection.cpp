#include <iostream>

using namespace std;

int main(){
    int arr[] = {12,13,25,1,23,54,24,67,15,16,46};
    int len = sizeof(arr)/sizeof(int);

    for(int i = 0; i < len -1; i++){
        int minindex = i;
        for (int j = i; j < len; j++){
            if (arr[j] < arr[minindex]){
                minindex = j;
            }
        }
        int tmp = arr[minindex];
        arr[minindex] = arr[i];
        arr[i] = tmp;
    }

    for (int i = 0; i < len; i++){
        cout << arr[i] << '\t';
    }
    cout << endl;

    for(int i = 0; i < len -1; i++){
        int maxindex = i;
        for (int j = i; j < len; j++){
            if (arr[j] > arr[maxindex]){
                maxindex = j;
            }
        }
        int tmp = arr[maxindex];
        arr[maxindex] = arr[i];
        arr[i] = tmp;
    }

    for (int i = 0; i < len; i++){
        cout << arr[i] << '\t';
    }
    return 0;
}