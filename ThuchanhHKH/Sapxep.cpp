#include <bits/stdc++.h>

using namespace std;

//Noi bot
void Bubble_sort(int x[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(x[j] > x[j+1])
                swap(x[j], x[j+1]);
        }
    }
}

//Chon
void Selection_sort(int x[], int n){
    for(int i = 0; i < n-1; i++){
        int m = i;
        for(int j = i+1; j < n; j++){
            if(x[m] > x[j])
                m = j;
        }
        swap(x[m], x[i]);
    }
}

//Chen
void Insertion_sort(int x[], int n){
    for(int i = 1; i < n; i++){
        int tam = x[i];
        int j = i-1;
        while(j > -1 && x[j] > tam){
            x[j+1] = x[j];
            j--;
        }
        x[j+1] = tam;
    }
}

//sap xep phan doan
void Quick_sort(int x[], int n, int l, int r){
    if(l < r){
        int k = (l+r)/2;
        int t = x[k];
        int i = l;
        int j = r;
        do{
            while(x[i] < t) i++; // lấy số đầu tiên lớn hơn t
            while(x[j] > t) j--; //lấy số đầu tiên(từ cuối xuống) nhỏ hơn t
            if(i <= j){
                swap(x[i], x[j]);
                i++;
                j--;
            }
        }while(i <= j);
        Quick_sort(x, n, l, j);
        Quick_sort(x, n, i, r);
    }
}

//vun dong
void Heapify(int x[], int n, int k){ //vun thanh dong
    if(k <= n/2-1){
        int j = 2*k+1; // con cua x[k] la x[j] va x[j+1]
        if(j < n-1 && x[j] < x[j+1])
            j++;
        if(x[k] < x[j]){ //x[k] nho hon 2 con
            swap(x[j], x[k]);
            Heapify(x, n, j);
        }
    }
}
void First_heap(int x[], int n){
    for(int k = n/2-1; k >= 0; k--){
        Heapify(x, n, k);
    }
}
void Heap_sort(int x[], int n){
    First_heap(x, n);
    for(int i = n-1; i >= 1; i--){
        swap(x[0], x[i]);
        Heapify(x, i, 0);
    }
}

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
        if(left[i] >= right[j]){ // nếu phân tử mảng con trái >= phần tử mảng con phải
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
    int x[] = {1, 4, 2, 3, 10, -100};
    int n = sizeof(x)/sizeof(x[0]);
    //Bubble_sort(x, n);
    //Selection_sort(x, n);
    //Insertion_sort(x, n);
    //Quick_sort(x, n, 0, n-1);
    //Heap_sort(x, n);
    Merge_sort(x,0, n-1);
    for(int i = 0; i < n; i++){
        cout << x[i] << " ";
    }
}