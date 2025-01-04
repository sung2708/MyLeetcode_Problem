class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> d;
        for (int i = 0; i < nums.size(); i++)
        {
            int result = target - nums[i];
            if (d.find(result) != d.end())
            {
                return {d[result], i};
            }
            d[nums[i]] = i;
        }
        return {};
    }
};