#include <iostream>

/*
                Lower Bound -  smallest index such that the nmbr at that index is greater than equals to the given nmbr
                                                    i.e,    arr[ind] >= x

                            for example - there is an array - arr[] = {3, 5, 8, 15, 19}
                                            if given nmbr x = 8, then the lower bound = 2  bcz arr[2] >= x      (index 2)
                                            if given nmbr x = 9, then the lower bound = 3  bcz arr[3] >= x      (index 3)
                                                                                                   15 >= 9 
                                            if given nmbr x = 16, then the lower bound = 4  bcz arr[4] >= x      (index 4)
                                                                                                    19 >= 16
                                            if given nmbr x = 20, then the lower bound = 5  which is greater than the length 
                                            of the array and is hypothetical


                                            lets have a different array -  arr[] = {3, 5, 8, 15, 19, 19, 19}
                                            if given nmbr x = 19, then the lower bound = 4  bcz we have to find lower bound
                                            which also means we have to find smallest index

                            note - if thereis the nmbr which doesn't exist in the array, we can return the index after last index 

                                let have an array -  arr[] = {1, 2, 3, 3, 7, 8, 9, 9, 9, 11}    where n= 10
                                                                    here x = 11
                                        in order to find 11 we iterate through whole array as linear search, which will give 
                                        us Time complexity of 'O(N)'
                                        instead of linear search we will perform binary search

                                                    lets search lower bound for x = 1
                                        for binary search - '0' index will be low, '9' index will be high, then mid = (0 + 9)/2
                                                                                                                    = 4 index
                                        element at 4th index is 5, which is greater than '1', so 1 is definitly at the left of 5

                                        then again '0' index will be low, '3' index will be high, then mid = (0 + 3)/2
                                                                                                           = 1 index
                                        element at 1st index is 2, which is greater than '1', so 1 is definitly at the left of 2

                                        for binary search - '0' index will be low, '0' index will be high, then mid = (0 + 0)/2
                                                                                                                    = 0 index
                                        from our formula 'arr[ind] >= x',  '1' might be our answer

                                        so lets place the high before 0 index, we stop bcz of that. the last index which could be
                                        our answer will be our lower bound
                                                    so the lower bound is = 0th index


                                    refer video for next example


        code template for lower bound
f(arr, target, n)
{
    low = 0, high = n-1;
    ans = n

    while(low <= high)
    {
        mid = (low + high)/2;

        if(arr[mid] >= x)                   // checking, maybe this is an answer
        {
            ans = mid;
            high = mid -1;
        }
        else
            low = mid + 1;
    }
}
return ans;


    Actual code
int lowerBound(vector<int>arr, int x, int n)
{
    int low = 0, high = n-1;
    int ans = n;

    while(low <= high)
    {
        int mid = (low + high)/2;

        // maybe an answer
        if(arr[mid] >= x)                   // checking, maybe this is an answer
        {
            ans = mid;
            // look for more small index on left
            high = mid -1;
        }
        else
            low = mid + 1;                  // look for right
    }
    return ans;
}


            for C++, lower bound can be found by these line of code
lb = lower_bound(v.begin(), v.end(), x);

            to get the index
lb = lower_bound(v.begin(), v.end(), x) - v.begin();

        if have to find lower bound between 2 and 8(2nd) in - arr[] = {1, 2, 3, 3, 5, 8, 8, 10, 10, 11}
lb = lower_bound(arr+2, arr+7, x);                      // 2 and 7 are indexes


        TC - O(log 'base 2' N)
        SC - O()


                
                Upper Bound -  smallest index such that the number at that index is greater than x
                                    i.e,    'arr[ind] > x'

            example -  arr[] = {2, 3, 6, 7, 8, 8, 11, 11, 11, 12}
                            x = 6

                        here upper bound will be index 3 bcz    arr[index] > x
                                                                    arr[3] > 6
                                                                        7  > 6

                            x = 11
                        here upper bound will be index 9 bcz    arr[index] > x
                                                                    arr[9] > 11
                                                                        12 > 11

                            x = 12
                        here upper bound will be index 10 bcz    arr[index] > x         // hypothetical
                                                                    arr[10] > 12
                                                                        
                            x = 13
                        here upper bound will be index 10 bcz    arr[index] > x         // hypothetical
                                                                    arr[10] > 6
                                                                        

Lower_bound                     Upper_bound
if(arr[mid] >= x)               if(arr[mid] > x)
    ans = mid;                      ans = mid;
    high = mid - 1;                 high = mid - 1;
else                            else
    low = mid + 1;                  low = mid + 1;


        Actual code         (same as lower bound)
int lowerBound(vector<int>arr, int x, int n)
{
    int low = 0, high = n-1;
    int ans = n;

    while(low <= high)
    {
        int mid = (low + high)/2;

        // maybe an answer
        if(arr[mid] > x)                   // checking, maybe this is an answer // lb -> '>=', ub -> '>'
        {
            ans = mid;
            // look for more small index on left
            high = mid -1;
        }
        else
            low = mid + 1;                  // look for right
    }
    return ans;
}


            for C++, lower bound can be found by these line of code
lb = upper_bound(v.begin(), v.end(), x);

            to get the index
lb = upper_bound(v.begin(), v.end(), x) - v.begin();

        if have to find lower bound between 2 and 8(2nd) in - arr[] = {1, 2, 3, 3, 5, 8, 8, 10, 10, 11}
lb = upper_bound(arr+2, arr+7, x);                      // 2 and 7 are indexes


        TC - O(log 'base 2' N)
        SC - O()
*/



/*
*           Q. Search Insert Position
                Q. You are given a sorted array 'arr' of distinct values and a target value 'm'. You need
                    to search for the index of the target value in the array.

                    If the value is present in the array, then return the index.
                    If the value is not present, determine the index when it would be inserted in the array
                    while maintaining the sorted order.

            given array -  arr[] = {1, 2, 4, 7}     m = 6
                            we have to insert 'm' in the arr[], for that we have to find its ideal index

                        for the arr[] = {1, 2, 4, 7}
                                index =  0  1  2  3

                            our ideal o/p should be - arr[] = {1, 2, 4, 6, 7}
                                                      index =  0  1  2  3  4
                                        ideally '6' should be in index 3 position

                                if we have to enter element '2' in the above array then it should be in the
                                '1' index position
                                                        arr[] = {1, 2, 2, 4, 7}
                                                        index =  0  1  2  3  4
                                                                    ^
                                                                    |
                                                                  x = 2

        sol - Actual code           (solving for lower_bound)
int searchInsert(vector<int>arr, int x)
{
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = n;

    while(low <= high)
    {
        int mid = (low + high)/2;

        // maybe an answer
        if(arr[mid] >= x)                   // checking, maybe this is an answer
        {
            ans = mid;
            // look for more small index on left
            high = mid -1;
        }
        else
            low = mid + 1;                  // look for right
    }
    return ans;
}
*/



/*
                Q. Floor and Ceil in Sorted Array

            explanation -  Floor - largest nmbr in array <= x
                           Ceil - smallest nmbr in array >= x

                        if arr[] = {10, 20, 30, 40, 50}   and x = 25

                            floor = 20,     bcz 20 is largest nmbr which is smaller than 25
                            ceil = 20,     bcz 30 is smallest nmbr which is greater than 25

                        if arr[] = {10, 20, 25, 30, 40}   and x = 25

                            floor = 25,     bcz 25 is largest nmbr which is smaller equals to than 25
                            ceil = 25,     bcz 25 is smallest nmbr which is greater equals to than 25

    pseudo code (for floor)
floor(arr, x)
{
    ans = -1                            // <- if doesn't exit any nmbr
    low = 0, high = n-1

    while(low <= high)
    {
        mid = (low + high)/2
        if(arr[mid] == mid)
            ans = arr[mid]              // here we are returning element, to return index search it
            low = mid+1
        else
            high = mid-1
    }
}
*/

int main()
{
    std::cout << "Hello World!\n";
}