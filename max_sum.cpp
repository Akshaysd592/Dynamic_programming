#include<iostream>
#include <vector>
using namespace std;


// 1. 
int solve(vector<int>& arr, int index){
    // base case 
    if(index >= arr.size()){
        return 0;
    }

    int include = arr[index] + solve(arr,index+2);
    int exclude = 0 + solve(arr,index+1);

    return max(include,exclude);
}


// 2.
int solvememo(vector<int>&arr, int index, vector<int>& mapped){//1.
    //base case
    if(index >= arr.size())
    return 0;
    // 3.
    if(mapped[index] != -1)
    return mapped[index];

    int include = arr[index] + solvememo(arr,index+2,mapped);
    int exclude =  0 + solvememo(arr, index+1,mapped);
//    2.
   return  mapped[index] = max(include,exclude);

}

// 3. 
int solveBU(vector<int>&arr, int index){
    // 1
    vector<int>mapped(arr.size()+2,0);

    // 2
    // not required already 0 values in it else put according to requirement

    //3 
    for(int i = arr.size()-1 ;i>=0;i--){
        int include  = arr[i] + mapped[i+2];  // don't change the logic just change in array if required because it is i+2 so arr.size()+2 
        int exclude = 0 + mapped[i+1]; 

        mapped[i] = max(include,exclude);
    }

    return    mapped[index]; // need to return mapped[0] /return the parameter which is passed initially


}


// 4. space optimisation 
int solveSo(vector<int>& arr){
    
    //1.
    int next1  = 0;
    int next2 = 0;
    int curr;


    //  2. 
    for(int i = arr.size()-1 ;i>=0;i--){
        int include = arr[i] + next2;
        int exclude  = 0 + next1;
        curr = max(include,exclude);

        // 3. 
        next2 = next1;
        next1 = curr;

    } 
    
    return curr;


}


int main(){
    vector<int>arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(9);
    // Q.  finding maximum sum with not taking adjacent elements 
  

    // 1. simple recursion 
     cout<<"Answer is "<< solve(arr,0)<<endl;// passing array and index normal recursion


    
    // 2. rec + memoisation
   vector<int>mapped(arr.size(),-1);
   cout<<"Answer using recursion and memoisation is "<<  solvememo(arr,0,mapped)<<endl;


   // 3. bottom up approach 
   cout<<"Answer using bottom up approach "<<solveBU(arr,0)<<endl;

   // 4. space optimisation
   cout<<"Answer using space optimisation method " << solveSo(arr);

    return 0;
}