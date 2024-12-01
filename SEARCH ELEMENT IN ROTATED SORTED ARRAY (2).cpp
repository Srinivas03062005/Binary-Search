
#include <bits/stdc++.h>
using namespace std;
bool searchInARotatedSortedArrayII(vector<int>&arr, int k) 
{
    int n = arr.size(); // size of the array.
    int low = 0, high = n - 1;
    while (low <= high) 
	{
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == k) return true;

        //Edge case:
        while (arr[low] == arr[mid] && arr[mid] == arr[high]) 
        {
            low = low + 1;
            high = high - 1;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) 
        {
            if (arr[low] <= k && k <= arr[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
        //if right part is sorted:
        else 
		{ 
            if (arr[mid] <= k && k <= arr[high]) 
			{
                //element exists:
                low = mid + 1;
            }
            else 
			{
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return false;
}
int main()
{
    vector<int> arr = {3,3,2,3,3,3,3};
    int k = 2;
    bool ans = searchInARotatedSortedArrayII(arr, k);
    if (!ans)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array.\n";
    return 0;
}


