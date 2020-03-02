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
int PartPation(int A[],int low,int high){
    int pivot = A[low];
    while(low<high){
        while(low<high && A[high]>=pivot) high--;
        A[low] = A[high];
        while(low<high && A[low]<=pivot) low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void QuickSort(int A[],int low, int high){
    if(low<high){
        int pivotpos = PartPation(A,low,high);
        QuickSort(A,low,pivotpos-1);
        QuickSort(A,pivotpos+1,high);
    }
}

int main()
{
    int a[] = {25,84,21,47,15,27,68,35,20};
    int len = 9;
    QuickSort(a,0,8);
    for(int i=0;i<len;i++)
        cout << a[i] << " ";
    cout << endl;
//
//    int b[] = {25,84,21,47,15,27,68,35,20};
//    MergeSort(b,0,8);
//    for(int i=0;i<len;i++)
//        cout << b[i] << " ";
//    cout << endl;
//    int c[] = {0,25,84,21,47,15,27,68,35,20};
//    int le = 9;
//    HeapSort(c,le);
//    for(int i=1;i<=le;i++)
//        cout << c[i] << " ";

    return 0;
}