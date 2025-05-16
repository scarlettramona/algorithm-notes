class Solution {
public:
    int findMin(vector<int> &nums)
    {
        int left_index = 0;
        int right_index = (nums.size() -1);

        while(nums[left_index] > nums[right_index])
        {
            int middle_index = (left_index + (right_index - left_index) / 2);
            if (nums[middle_index] < nums[right_index])
                right_index = middle_index;
            else
                left_index = middle_index + 1;
        } 

        return nums[left_index];

    }
};