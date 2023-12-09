#include<iostream>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;



int min_count_coin(int n ,vector<int>& arr){
    //base case
    if(n==0)
    return 0;

    if(n<0)
    return INT_MAX;

    int mini = INT_MAX;

    for(int i = 0;i<arr.size();i++){ // using for loop because working using array which can have as many as elements not known 
                                      // this question is similar to below method just in below a, b , c is known that only 3 variables
        int ans =  min_count_coin(n-arr[i],arr);
        if(ans != INT_MAX){
          mini  = min(mini, 1+ans);
        }

    }


    return mini;

}












int solve(int n, int a, int b, int c){
    // base case
    if(n==0){
        return 0;
    }

    if(n<0){
        return INT_MIN;
    }

    int ans1 = solve(n-a,a,b,c);
    int ans2 = solve(n-b,a,b,c);
    int ans3 = solve(n-c,a,b,c);


      return  1+ max(ans1,max(ans2,ans3)); // need to return length of maximum cut so 1+ 


}


int solvememo(int n, int a, int b,int c ,vector<int>& mapped){
    //base case
    if(n==0)
    return 0;

    if(n<0)
    return INT_MIN;

    if(mapped[n] != -1){
        return mapped[n];
    }


    int ans1 = solvememo(n-a,a,b,c,mapped);
    int ans2 = solvememo(n-b,a,b,c,mapped);
    int ans3  = solvememo(n-c,a,b,c,mapped);

     return  mapped[n]  =  1+max(ans1,max(ans2,ans3));
}

int solveBU(int n,int a, int b, int c){
    
    // 1. 
    vector<int>mapped (n+1,INT_MIN);

    // 2. store
    mapped[0] = 0;

    for(int i = 1 ;i <= n ; i++){
        int ans1 = mapped[i-a];
        int ans2 = mapped[i-b];
        int ans3 = mapped[i-c];
      
      mapped[i] = 1 + max(ans1,max(ans2,ans3));
    
    }

    return mapped[n];

}



int main(){
    int n = 17;
    int a  = 10;
    int b= 11;
    int c = 3;

    int ans  = solve(n,a,b,c);
    if(ans <= 0){
        ans = -1;
    }

    cout<<"Answer is : "<<ans<<endl;


    //2.  method rec + memo 
    vector<int>mapped(n+1,-1);
    cout<<"Ans using rec and memo : "<< solvememo(n,a,b,c,mapped)<<endl;


  // 3. bottom up
  
   cout<<"Ans using bottom up method : "<<solveBU(n,a,b,c);











    return 0;
}