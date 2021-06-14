class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left=0, right=nums.size()-1;
        while(true)
        {
        int q=partition(nums, left, right);
        if(q==k-1) return nums[k-1];
        else if(q>k-1) right=q-1;
        else left=q+1; 
        }
    }
    
    
private:
    int partition(vector<int> &nums, int left, int right) //bigggest to smallest
    {
        int pivot=nums[right];
        int i=left-1;
        for(int j=left; j<right; j++)
        {
            if(nums[j]>=pivot){
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[++i], nums[right]);
        return i;
    }
};
