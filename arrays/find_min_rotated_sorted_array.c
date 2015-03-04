/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
You may assume no duplicate exists in the array.
*/

/*C Code*/
int findMin(int num[], int n) {
    
    int mid;
    if(n==1)
        return num[0];
    
    mid=n/2;
    
    if(num[mid-1]>num[mid])
        return num[mid];
    if(num[mid]>num[n-1])
        return findMin(num+mid,n-mid);
    return findMin(num,mid);
}
