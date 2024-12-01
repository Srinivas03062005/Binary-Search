
   //THRESHOLD MEANS NOTHING BUT LIKE SOME BOUNDARY
  /* [1 2 5 9] THRESHOLD = 6
   KEYPOINT **TAKE CEILVALUE
   1/4 2/4 5/4 9/4 = 7 WHEN SUMITUP THAT SHOULD BE LESS THAN OR EQUAL TO THRESHOLD
   7<=6 NOT IF YES THAT SHOUULD BE THE SMALLEST VALUE*/
         //BRUTE FORCE
         
#include <bits/stdc++.h>
using namespace std;
int smallestDivisor(vector<int>& arr, int limit) 
{
    int n = arr.size(); //size of array.
    //Find the maximum element:
    int maxi = *max_element(arr.begin(), arr.end());
    //Find the smallest divisor:
    for (int d = 1; d <= maxi; d++) 
	{
        //Find the summation result:
        int sum = 0;
        for (int i = 0; i < n; i++) 
		{
            sum += ceil((double)(arr[i]) / (double)(d));
        }
        if (sum <= limit)
            return d;
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = smallestDivisor(arr, limit);
    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}
/*Complexity Analysis
Time Complexity: O(max(arr[])*N), where max(arr[]) = maximum element in the array, N = size of the array.
Reason: We are using nested loops. The outer loop runs from 1 to max(arr[]) and the inner loop runs for N times.

Space Complexity: O(1) as we are not using any extra space to solve this problem.*/


   
   
   
              //OPTIMAL
  
#include <bits/stdc++.h>
using namespace std;
int sumByD(vector<int> &arr, int div) 
{
    int n = arr.size(); //size of array
    //Find the summation of division values:
    int sum = 0;
    for (int i = 0; i < n; i++) 
	{
        sum += ceil((double)(arr[i]) / (double)(div));
    }
    return sum;
}
int smallestDivisor(vector<int>& arr, int limit) 
{
    int n = arr.size();
    if (n > limit) return -1;    //OR ANOTHER TAKE ANS VARIABLE INITIALIZE TO -1 AND KEEP UPDATE IN THE INSIDE WHILE OF IF 
    int low = 1, high = *max_element(arr.begin(), arr.end());
    //Apply binary search:
    while (low <= high) 
	{
        int mid = (low + high) / 2;
        if (sumByD(arr, mid) <= limit) 
		{
            high = mid - 1;
        }
        else 
		{
            low = mid + 1;
        }
    }
    return low;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = smallestDivisor(arr, limit);
    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}
/*Complexity Analysis
Time Complexity: O(log(max(arr[]))*N), where max(arr[]) = maximum element in the array, N = size of the array.
Reason: We are applying binary search on our answers that are in the range of [1, max(arr[])]. 
For every possible divisor ‘mid’, we call the sumByD() function. Inside that function, we are traversing the entire array, which results in O(N).

Space Complexity: O(1) as we are not using any extra space to solve this problem.*/
            

