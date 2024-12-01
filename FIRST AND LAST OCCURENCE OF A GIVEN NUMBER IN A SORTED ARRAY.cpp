//ONLINE C++ COMPILER
//we can do it using lower bound and upper bound also 
#include <bits/stdc++.h>
using namespace std;
int firstOccurrence(vector<int> &arr, int n, int k) 
{
    int low = 0, high = n - 1;
    int first = -1;
    while (low <= high) 
	{
        int mid = (low + high) / 2;
        if (arr[mid] == k) 
		{
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < k) 
		{
            low = mid + 1; 
        }
        else 
		{
            high = mid - 1; 
        }
    }
    return first;
}
int lastOccurrence(vector<int> &arr, int n, int k) 
{
    int low = 0, high = n - 1;
    int last = -1;
    while (low <= high) 
	{
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] == k) 
		{
            last = mid;
            //look for larger index on the right
            low = mid + 1;
        }
        else if (arr[mid] < k) 
		{
            low = mid + 1; // look on the right
        }
        else 
		{
            high = mid - 1; // look on the left
        }
    }
    return last;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) 
{
    int first = firstOccurrence(arr, n, k);
    if (first == -1) return { -1, -1};
    int last = lastOccurrence(arr, n, k);
    return make_pair(first, last);
}
int main()
{
    vector<int> arr =  {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8, x = 8;
    pair<int,int> ans=firstAndLastPosition(arr, n, x);
    cout<<ans.first<<" "<<ans.second;
    return 0;
}
