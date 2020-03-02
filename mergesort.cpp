#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <math.h>
#include <sstream>
#include <deque>
#include <ctime>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
};

int* B = new int[10];
void Merge(int A[],int low,int mid,int high){
    for(int i=low;i<=high;i++)
        B[i] = A[i];
    int k = low;
    int i=low,j=mid+1;
    while(i<=mid && j<= high){
        if(B[i]<=B[j])
            A[k++] = B[i++];
        else
            A[k++] = B[j++];
    }

    while(i<=mid) A[k++] = B[i++];
    while(j<=high) A[k++] = B[j++];
}
void MergeSort(int A[],int low,int high){
    if(low<high){
        int mid = (low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        Merge(A,low,mid,high);
    }
}
int main()
{
    int a[] = {25,84,21,47,15,27,68,35,20};
    int len = 9;
//    QuickSort(a,0,8);
//    for(int i=0;i<len;i++)
//        cout << a[i] << " ";
//    cout << endl;
//
    int b[] = {25,84,21,47,15,27,68,35,20};
    MergeSort(b,0,8);
    for(int i=0;i<len;i++)
        cout << b[i] << " ";
    cout << endl;
//    int c[] = {0,25,84,21,47,15,27,68,35,20};
//    int le = 9;
//    HeapSort(c,le);
//    for(int i=1;i<=le;i++)
//        cout << c[i] << " ";

    return 0;
}