class Solution 

public:
		//finding the subset in the given array
		void findAns(vector<int> &nums, vector<int> &ans, vector<vector<int>> &mainAns, int pos)
		{
			if(pos == nums.size()){mainAns.push_back(ans); return;}
			//skipping the part
			findAns(nums, ans, mainAns, pos + 1) ;
			ans.push_back(nums[pos]);
			findAns(nums, ans, mainAns, pos + 1);
			ans.pop_back();
		}
		vector<vector<int>> subset(vector<int> &nums)
		{
			vector<vector<int>> mainAns;
			vector<int> ans;
			int pos =0;
			findAns(nums,ans, mainAns, pos);
			return mainAns;
		}
}
//Solution for the subset probloem with elements repeating an should be unique
class Solution
{
	public:
		void findAns(vector<int> &nums, vector<int> &ans, vector<vector<int>> &mainAns, int pos)
		{
			if(pos == nums.size()){mainAns.push_back(ans); return;}
			//adding the element
			ans.push_back(nums[i]);
			findAns(nums, ans, mainAns, pos + 1);
			ans.pop_back();
			while(pos < nums.size() && nums[pos]== nums[pos + 1]) pos++;
			findAns(nums, ans, mainAns, pos + 1);
		}
		vector<vector<int>> subset(vector<int> &nums)
		{
			vector<vector<int>> mainAns;
			sort(nums.begin(), nums.end());
			vector<int> ans;
			int pos =0;
			findAns(nums, ans, mainAns, pos);
			return mainAns;
		}
}
