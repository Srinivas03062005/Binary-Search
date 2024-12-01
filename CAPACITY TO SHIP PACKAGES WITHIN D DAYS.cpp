/*
PROBLEM STATEMENT : You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. 
The packages must be shipped within 'd' days.
The weights of the packages are given in an array 'of weights'. 
The packages are loaded on the conveyor belts every day in the same order as they appear in the array. 
The loaded weights must not exceed the maximum weight capacity of the ship.
Find out the least-weight capacity so that you can ship all the packages within 'd' days.


[1 2 3 4 5 6 7 8 9 10]  D=5
IF WE TAKE CAPACITY=100 THEN THE SUMOFALL IN THE ARRAY IS 55 THEN 1 DAY IS ENOUGH NAA SO NOT 100,
IF WE TAKE CAPACITY=10 THEN THE TOTAL ARRAY TAKES 7 DAYS AS FOLLOWS
1. 1 2 3 4
2. 5 
3. 6
4. 7
5. 8
6. 9
7. 10
IF WE TAKE CAPACITY=15 THEN THE TOTAL ARRAY TAKES 5 DAYS AS FOLLOWS
1. 1 2 3 4 5
2. 6 7
3. 8
4. 9
5. 10
*/

                       //BRUTE
                       
#include <bits/stdc++.h>
using namespace std;
int findDays(vector<int> &weights, int cap) 
{
    int days = 1; //First day.
    int load = 0;
    int n = weights.size(); //size of array.
    for (int i = 0; i < n; i++) 
	{
        if (load + weights[i] > cap) 
		{
            days += 1; //move to next day
            load = weights[i]; //load the weight.
        }
        else 
		{
            //load the weight on the same day.
            load += weights[i];
        }
    }
    return days;
}
int leastWeightCapacity(vector<int> &weights, int d) 
{
    //Find the maximum and the summation:
    int maxi = *max_element(weights.begin(), weights.end());
    int sum = accumulate(weights.begin(), weights.end(), 0);
    for (int i = maxi; i <= sum; i++) 
	{
        if (findDays(weights, i) <= d) 
		{
            return i;
        }
    }
    //dummy return statement:
    return -1;
}
int main()
{
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int d = 5;
    int ans = leastWeightCapacity(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}
/*Complexity Analysis
Time Complexity: O(N * (sum(weights[]) - max(weights[]) + 1)),
 where sum(weights[]) = summation of all the weights, max(weights[]) = maximum of all the weights, N = size of the weights array.
Reason: We are using a loop from max(weights[]) to sum(weights[]) to check all possible weights. Inside the loop,
 we are calling findDays() function for each weight. Now, inside the findDays() function, we are using a loop that runs for N times.

Space Complexity: O(1) as we are not using any extra space to solve this problem.*/




    
    
            //OPTIMAL
            
#include <bits/stdc++.h>
using namespace std;
int findDays(vector<int> &weights, int cap) 
{
    int days = 1; //First day.
    int load = 0;
    int n = weights.size(); //size of array.
    for (int i = 0; i < n; i++) 
	{
        if (load + weights[i] > cap) 
		{
            days += 1; //move to next day
            load = weights[i]; //load the weight.
        }
        else 
		{
            //load the weight on the same day.
            load += weights[i];
        }
    }
    return days;
}
int leastWeightCapacity(vector<int> &weights, int d) 
{
    //Find the maximum and the summation:
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    while (low <= high) 
	{
        int mid = (low + high) / 2;
        int numberOfDays = findDays(weights, mid);
        if (numberOfDays <= d) 
		{
            //eliminate right half
            high = mid - 1;
        }
        else 
		{
            //eliminate left half
            low = mid + 1;
        }
    }
    return low;
}
int main()
{
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = leastWeightCapacity(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}
/*Complexity Analysis
Time Complexity: O(N * log(sum(weights[]) - max(weights[]) + 1)),
where sum(weights[]) = summation of all the weights, max(weights[]) = maximum of all the weights, N = size of the weights array.
Reason: We are applying binary search on the range [max(weights[]), sum(weights[])]. For every possible answer �mid�, 
we are calling findDays() function. Now, inside the findDays() function, we are using a loop that runs for N times.

Space Complexity: O(1) as we are not using any extra space to solve this problem.*/
