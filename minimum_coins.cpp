#include <bits/stdc++.h>
using namespace std;

int min_count_coin(int n, vector<int> &arr)
{
    // base case
    if (n == 0)
        return 0;

    if (n < 0)
        return INT_MAX;

    int mini = INT_MAX;

    for (int i = 0; i < arr.size(); i++)
    { // using for loop because working using array which can have as many as elements not known
      // this question is similar to below method just in rod_cuts.cpp program a, b , c is known that only 3 variables
        int ans = min_count_coin(n - arr[i], arr);
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }

    return mini;
}

int solvememo(int n, vector<int> &arr, vector<int> &mapped)
{
    // base case
    if (n == 0)
        return 0;

    if (n < 0)
        return INT_MAX;

    if (mapped[n] != -1)
    {
        return mapped[n];
    }

    int mini = INT_MAX;

    for (int i = 0; i < arr.size(); i++)
    { // using for loop because working using array which can have as many as elements not known
      // this question is similar to below method just in rod_cuts.cpp program a, b , c is known that only 3 variables
        int ans = solvememo(n - arr[i], arr, mapped);
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }

    return mapped[n] = mini;
}

int solveTab(int n, vector<int> &arr)
{

    vector<int> dp(n + 1, INT_MAX);

    dp[0] = 0;

    for (int target = 1; target <= n; target++)
    {
        int mini = INT_MAX;


        for (int i = 0; i < arr.size(); i++)
        {
           if(target-arr[i] >=0){
            int ans = dp[target- arr[i]];

            if(ans !=  INT_MAX){
                mini = min(mini, 1+ans);
            }
           }
        }

         dp[target] = mini;
    }

    return dp[n];
}


int main()
{

    // Q. minimum number of coins
    int target = 7;

    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    cout << "minimum number of coins " << min_count_coin(target, arr) << endl;

    // rec+memo
    vector<int> mapped(target + 1, -1);
    cout << "rec and memo method " << solvememo(target, arr, mapped) << endl;
    

    // tabulation
    cout << "Tabulation method solution " << solveTab(target, arr) << endl;
    return 0;
}