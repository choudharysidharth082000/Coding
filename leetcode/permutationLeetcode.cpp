class Solution {
public:
//using the DFS Appraoch
    void findAns(vector<int> &nums, unordered_map<int, int> &store,vector<vector<int>> &mainAns, vector<int> &permutations)
    {
        if(permutations.size() == nums.size()){mainAns.push_back(permutations); return;}
        for(auto it : store)
        {
            if(it.second > 0)
            {
                permutations.push_back(it.first);
                store[it.first]--;
                findAns(nums, store, mainAns, permutations);
                store[it.first]++;
                permutations.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> permutations;
        vector<vector<int>> mainAns;
        unordered_map<int, int> store;
        for(auto it: nums)
            store[it]++;
        findAns(nums, store, mainAns, permutations);
        return mainAns;        
    }
};
//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
//Using the Swap Approach
class Solution {
public:
    //using the Swap approach removinf the space compelxity
    void findAns(vector<int> &nums, vector<vector<int>> &mainAns, int pos)
    {
        if(pos == nums.size()){mainAns.push_back(nums); return;}
        int n = nums.size();
        for(int i=pos;i<n;i++)
        {
            swap(nums[pos], nums[i]);
            findAns(nums, mainAns, pos +1);
            swap(nums[i], nums[pos]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> mainAns;
        int pos =0;
        findAns(nums, mainAns, pos);
        return mainAns;
    }
};