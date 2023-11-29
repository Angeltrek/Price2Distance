class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid = 0, i = 0, j = 0, k = 0;

        if(nums.size() % 2 == 0) {
            mid = nums.size() / 2;
        } else {
            mid = nums.size() / 2 + 1;
        }

        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid, nums.end());

        while(i < nums.size()) {
            if(j < left.size()) {
                nums[i] = left[left.size() - 1 - j];
                i++;
                j++;
            }

            if(k < right.size()) {
                nums[i] = right[right.size() - 1 - k];
                i++;
                k++;
            }
        }
    }
};