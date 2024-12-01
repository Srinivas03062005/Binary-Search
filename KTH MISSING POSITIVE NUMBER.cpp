/*GIVEN AN INCREASING ARRAY AND VARIABLE K
  [2 3 4 7 11] K=5
  1 2 3 4 5 6 7 8 9 10 11
  - + + + - - + - - -  +
  1       2 3   4 5 6
  5 TH ONE IS 9
  */
  
                   //BRUTE
                   
#include <bits/stdc++.h>
using namespace std;
int missingK(vector < int > vec, int n, int k) 
{
    for (int i = 0; i < n; i++) 
	{
        if (vec[i] <= k) k++; //shifting k
        //Note: The main idea is to shift k by 1 step if the current element is smaller or equal to k. 
		//And whenever we get a number > k, we can conclude that k is the missing number.
        else break;
    }
    return k;
}
int main()
{
    vector<int> vec = {4, 7, 9, 10};
    int n = 4, k = 4;
    int ans = missingK(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}
/*Complexity Analysis
Time Complexity: O(N), N = size of the given array.
Reason: We are using a loop that traverses the entire given array in the worst case.

Space Complexity: O(1) as we are not using any extra space to solve this problem.*/






                     //OPTIMAL
 
 /*
 0 1 2 3 4     
[2 3 4 7 11]  K=5
 ACTUAL NUMBERS
 1 2 3 4 5
 2-1=1 BEFORE 2 THERE ARE 1 NUMBER WHICH IS MISSED
 3-2=1 BEFORE 3 THERE ARE 1 NUMBER WHICH IS MISSED
 4-3=1 BEFORE 4 THERE ARE 1 NUMBER WHICH IS MISSED
 7-4=3 BEFORE 7 THERE ARE 3 NUMBERS WHICH ARE MISSED
 11-5=6  BEFORE 11 THERE ARE 6 NUMBERS WHICH ARE MISSED
 */
            
#include <bits/stdc++.h>
using namespace std;
int missingK(vector < int > vec, int n, int k) 
{
    int low = 0, high = n - 1;
    while (low <= high) 
	{
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1);
        if (missing < k) 
		{
            low = mid + 1;
        }
        else 
		{
            high = mid - 1;
        }
    }
    //ACTUALLY ANSWER IS VEC[HIGH]+MORE
    //BUT IN THIS CASE FINALLY HIGH POINTS TO -1 SO PROBLEM [4 7 9] K=3,SO WHEN IT IS -1 WE CANNOT ACCESS VECTOR AS VEC[-1] IT IS WRONG SO ...
    //SO VEC[HIGH]+MORE----->MORE=K-MISSING----->MISSING=VEC[HIGH]-HIGH-1
    //SO FINALLY VEC[HIGH]+K-(VEC[HIGH]-HIGH-1)
    // K+HIGH+1
    return k + high + 1;
    
    //HERE FINALLY LOW=HIGH+1 SO WE CAN RETURN LOW+K ALSO
}
int main()
{
    vector<int> vec = {2,3,4,7,11};
    int n = 5, k = 5;
    int ans = missingK(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}
/*Complexity Analysis
Time Complexity: O(logN), N = size of the given array.
Reason: We are using the simple binary search algorithm.

Space Complexity: O(1) as we are not using any extra space to solve this problem.*/



