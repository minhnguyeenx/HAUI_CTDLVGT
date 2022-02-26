#include <bits/stdc++.h>

using namespace std;

//trộn
void merge(int x[], int l, int m, int r){
    int n1 = m - l +1; // số phần tử ở mảng con trái
                            // cộng 1 vì lưu cả số vtri m
    int n2 = r-m;       //số phần tử của mảng con phái
    int left[n1], right[n2]; // hai mảng trung gian
    
    //copy dữ liệu từ mảng chính ra mảng con
    for(int i = 0; i < n1; i++)
        left[i] = x[l+i];
    for(int i = 0; i < n2; i++){
        right[i] = x[m+i+1];
    }

    int i = 0, j = 0; //biến để chạy mảng con
    int k = l; //lưu k làm vị trí bắt đầu của mảng chính
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){ // nếu phân tử mảng con trái >= phần tử mảng con phải
            x[k] = right[j];j++;
        }
        else{
            x[k] = left[i];i++;
        }
        k++; //tang index mảng chính
    }
    //khi 1 trong 2 mảng đã duyệt hết
    while(j < n2){
        x[k] = right[j];j++;k++;
    }
    while(i < n1){
        x[k] = left[i]; i++; k++;
    }
}   
void Merge_sort(int x[],int l, int r){
    int t; // biến lưu vị trí chia đôi mảng
    if(l < r){ //nếu mảng còn ít nhất 1 phần tử
        t = (l+r)/2; //chia đôi mảng
        Merge_sort(x, l, t);
        Merge_sort(x, t+1, r);
        merge(x, l, t, r);
    }
    else //mảng còn 1 phần tử thì dừng đệ quy
        return;
}

int main(){
    int x[] = {34, 14, 24, 54, 84, 64, 94, 74, 04};
    int n = sizeof(x)/sizeof(x[0]);
    cout << "Day sau khi sap xep: ";
    Merge_sort(x, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << x[i] << " ";
    }
}