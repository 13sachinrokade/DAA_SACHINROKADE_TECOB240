/*
    Problem : https://www.hackerrank.com/challenges/pairs/problem

	You will be given an array of integers and a target value. Determine the number of pairs of array elements that have a difference equal to a target value.
For example, given an array of [1, 2, 3, 4] and a target value of 1, we have three values meeting the condition:
    C++ 14 : 2-1=1, 3-2=1
Function Description:
Complete the pairs function below. It must return an integer representing the number of element pairs having the required difference.
pairs has the following parameter(s):
k: an integer, the target difference
arr: an array of integers

Input Format:
The first line contains two space-separated integers  n and k, the size of  and the target value.
The second line contains  space-separated integers of the array .

Output Format:
An integer representing the number of pairs of integers whose difference is .

Sample Input
5 2  
1 5 3 4 2  

Sample Output
3
    Approach : 
        We simply need to translate the problem statement into code efficiently, i.e.
        Given N integers, count the number of pairs of integers whose difference is K.
        We use binary search for the purpose. A linear search will run in O(n) time which 
        will not be sufficient to pass all the test cases.
    
    Time Complexity : O( n*log(n) )
    Space Complexity : O( n )
*/
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

long long arr[100000];

bool b_search(int l, int r, long long x){
    int m;
    while (l <= r){
        m = l + (r-l)/2;
        if (arr[m] == x) 
            return true;  
        if (arr[m] < x) 
            l = m + 1; 
        else
            r = m - 1; 
    }
  return false; 
}
int main() {
    int n;
    long long k, ans=0;
    cin>>n>>k;
    int i,j;
    for(i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    for(i=0; i<n-1; i++){
        if(b_search(i+1, n-1, arr[i]+k)){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
