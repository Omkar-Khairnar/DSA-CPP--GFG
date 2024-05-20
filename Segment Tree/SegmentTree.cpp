
#include <bits/stdc++.h> 
using namespace std;
 
 
class SegmentTree
{
public:
    vector<int>seg;
    SegmentTree(int n){
        seg.resize(4*n+1);
    }
    
    //Building Segment Tree for Min Elements in Given Query Range, Taking nums array of length n;
    void build(int index, int low, int high, vector<int>&nums){
        if(low == high){
            seg[index] = nums[low];
            return ;
        }
        int mid = (low+high)/2;
        build(2*index+1, low, mid, nums);
        build(2*index+2, mid+1, high, nums);

        seg[index] = min(seg[2*index+1], seg[2*index+2]);
    }

    int query(int index, int low, int high, int l, int r){
        //3 Cases Total

        //No Overlap -> [low..high] [l..r] OR [l..r] [low..high]
        if(l>high || low > r){
            return INT_MAX;
        }
        //Complete Overlap --> [l... low,..,high, ... r]
        else if(low>=l && high<=r){
            return seg[index];
        }
        //Partial Overlap
        else{
            int mid = (low+high)/2;
            int left = query(2*index+1, low, mid, l, r);
            int right = query(2*index+2, mid+1, high, l, r);
            return min(left, right);
        }
    }

    void update(int index, int low, int high, int i, int val){
        if(low == high){
            seg[index] = val;
            return ;
        }
        int mid = (low+high)/2;
        if(i <= mid){
            update(2*index+1, low, mid, i, val);
        }
        else{
            update(2*index+2, mid+1, high, i, val);
        }
        seg[index] = min(seg[2*index+1], seg[2*index+2]);
    }
};

int main(int argc, char const *argv[])
{

    int n; 
    cin >> n;
    vector<int>nums;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        nums.push_back(val);
    }

    SegmentTree st(n);
    st.build(0, 0, n-1, nums);

    cout << st.query(0, 0, n-1, 0, 1);

 
  return 0;
}
