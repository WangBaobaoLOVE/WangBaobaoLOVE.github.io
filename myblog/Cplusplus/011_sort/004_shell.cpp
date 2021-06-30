#include <iostream>

using namespace std;

int main(){
    int arr[] = {12,13,25,1,23,54,24,67,15,16,46};
    int len = sizeof(arr)/sizeof(int);
    
    for (int gap = len / 2; gap > 0; gap = gap / 2) {
        // 注意：这里和动图演示的不一样，动图是分组执行，实际操作是多个分组交替执行
        for (int i = gap; i < len; i++) {
            int j = i;
            int current = arr[i];
            while (j - gap >= 0 && current < arr[j - gap]) {
                 arr[j] = arr[j - gap];
                 j = j - gap;
            }
            arr[j] = current;
        }
    }

    for (int i = 0; i < len; i++){
        cout << arr[i] << '\t';
    }
    cout << endl;
    return 0;
}