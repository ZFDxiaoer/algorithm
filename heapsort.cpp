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


void AdjustUp(int A[],int k){
    A[0] = A[k];
    int i = k /2;
    while(i>0 && A[i]<A[0]){
        A[k] = A[i];
        k = i;
        i = k/2;
    }
    A[k] = A[0];
}


//第k个元素开始下沉
void AdjustDown(int A[],int k,int len){
    A[0] = A[k];
    for(int i=2*k;i<=len;i*=2){
        if(i<len && A[i]<A[i+1]) i++;
        if(A[0]>=A[i]) break;
        else{
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}

void BuildMaxHeap(int A[],int len){
    for(int i=len/2;i>0;i--){
        AdjustDown(A,i,len);
    }
}

void HeapSort(int A[], int len){
    BuildMaxHeap(A,len);
    for(int i=len;i>1;i--){
        swap(A[i],A[1]);
        AdjustDown(A,1,i-1);
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
//    int b[] = {25,84,21,47,15,27,68,35,20};
//    MergeSort(b,0,8);
//    for(int i=0;i<len;i++)
//        cout << b[i] << " ";
//    cout << endl;
    int c[] = {0,25,84,21,47,15,27,68,35,20};
    int le = 9;
    HeapSort(c,le);
    for(int i=1;i<=le;i++)
        cout << c[i] << " ";

    return 0;
}