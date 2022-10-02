#include<iostream>
#include<vector>
using namespace std;
void show(vector<int> &arr){
    for(int x:arr){
        cout<<x<<' ';
    }
    cout<<'\n';
}
void sort(vector<int> &arr,int n){
    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i+1; j < n;j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr[i],arr[min]);
    }
}
int main(){
    int n;
    cout<<"Enter number of elements in array :\n";
    cin>>n;
    vector<int> v;
    cout<<"Enter array:\n";
    for(int i = 0; i < n ; i++){
        int k;
        cin>>k;
        v.push_back(k);
    }
    sort(v,n);
    show(v);
    return 0;
}