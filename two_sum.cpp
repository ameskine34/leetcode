class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> a;
        int x = -1; 
        for (size_t i = 0; i < nums.size(); i++)
        {
            for (size_t j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    a.push_back(i);
                    a.push_back(j);
                    x = 0;
                    break;
                }
            }
            if (!x)
                break;
        }
        return (a);
    }
};