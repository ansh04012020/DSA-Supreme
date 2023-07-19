#include <iostream>
#include <vector>
using namespace std;

//Merge sort copy array

// void merge(vector<int> &v, int s, int e)
// {
//     int mid = s + (e - s) / 2;
//     vector<int> left,right;
//     // vector<int> right;
//     // left array
//     for (int i = s; i <= mid; i++)
//         left.push_back(v[i]);
//     // right array
//     for (int i = mid + 1; i <= e; i++)
//         right.push_back(v[i]);
//     int leftI = 0, rightI = 0, mainI = s;
//     while ((leftI < left.size()) && (rightI < right.size()))
//     {
//         if (left[leftI] <= right[rightI])
//             v[mainI++] = left[leftI++];
//         else
//             v[mainI++] = right[rightI++];  
//     }
//     while (leftI < left.size())
//     {
//         v[mainI++] = left[leftI++];
//     }
//     while (rightI < right.size()){
//         v[mainI++] = right[rightI++];
//     }
// }

//merge sort in Place
void merge(vector<int> &v, int s, int e)
{

    int mid = s + (e - s) / 2;
    int leftI = s, rightI = mid+1;
   
    while ((leftI <= mid) && (rightI <= e))
    {

        if (v[leftI] <= v[rightI]){
            leftI++;
        }
        else{
            int val=v[rightI];
            int ind=rightI;
            while(ind!=leftI){
                v[ind]=v[ind-1];
                ind=ind-1;
            }
            v[leftI]=val;
        leftI++;
        rightI++;
        // mid++;
        }
    }

   
}

void mergeSort(vector<int> &v, int s, int e)
{
    int mid =  (e + s)/2;
    if (s >=e)
    return;
    mergeSort(v, s, mid);
    mergeSort(v, mid+1, e);

    merge(v, s, e);
}
int main()
{
    vector<int> nums = {4,2,5,9,1,6,11,8,44,22,33,66,11};
    mergeSort(nums, 0, nums.size()-1);
    for (auto i : nums)
        cout << i<<" ";
    return 0;
}