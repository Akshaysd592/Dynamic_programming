#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 1] recursion
// int solve(int n){
//     //base case 
//     if(n<=1){
//         return n;
//     }

//     int result = solve(n-1) + solve(n-2);

//     return result;

// }







// 2] recursion with data memoisation
// int solve(int n,vector<int>&mapped){
//     //base case 
//     if(n<=1){
//         return n;
//     }
//     if(mapped[n] != -1){
//         return mapped[n];
//     }

    



//     int result = solve(n-1,mapped) + solve(n-2,mapped);
//     mapped[n] = result;
//     return result;

// }











// 3] Bottom up approach
// Tabulation method

int solve(int n){
    // 1. create dp array
    vector<int>dp (n+1,0);

    // 2. analyse the base case
    dp[0] = 0;
    dp[1] = 1;

    // 3. recursive logic
    // In top down top to bottom n to 0 
    //But here bottom up so 0 to n  but 0 and 1 value already got
    for(int i = 2;i<=n;i++){
        int ans = dp[i-1] + dp[i-2]; // for i = 2 finding dp[1] + dp[0] similarly other values
        dp[i] = ans;
    }
  
     return dp[n];
}

// space optimisation
// since in fabonacci series don't need to store value , 
// curr is depends on prev1 and prev2 

int solveSO(int n){
    //step 1 
    // replace dp array with optimised storage
    int prev1 = 1;
    int prev2 = 0;
    int curr ;

  
    // step 2
    // get dp value/each value using prev1 and prev2 
    for(int i = 2;i<=n ;i++){

        int curr = prev1+prev2;


        // step 3 
        // movement of variables 
         prev2  = prev1;
         prev1 = curr;

    }


    // step 3 

    return prev1;


}





int main(){

        int n ;
        cout<<"Enter the value of n"<<endl;
        cin>>n;

        // method: memoisation
        // vector<int> mapped (n+1,-1); // when using memoisation 
        // int ans  = solve(n,mapped);


        // method: bottom up method call
        //  int ans = solve(n);
        



        // space optimisation 
        int ans = solveSO(n);
        cout<<"The "<<n<<"th fibonacci number is "<<ans<<endl;


  
    return 0;
}