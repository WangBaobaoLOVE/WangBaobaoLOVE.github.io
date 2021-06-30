#include <iostream>

using namespace std;

int main(){
    int arr[] = {12,13,25,1,23,54,24,67,15,16,46};
    int len = sizeof(arr)/sizeof(int);

    for(int i = 1; i < len; i++){
        int insertvalue = arr[i];

        int j = i-1;
        for (; j > -1; j--){
            if (arr[j] > insertvalue){
                arr[j+1] = arr[j];
            }
            else{
                arr[j+1] = insertvalue; 
                break;
            }
        }
        if (j < 0) {arr[0] = insertvalue;}

    }

    for (int i = 0; i < len; i++){
        cout << arr[i] << '\t';
    }
    cout << endl;
    return 0;
}