class solution
{
	public:
		void findAns(vector<int> &ans, vector<vector<int>> &mainAns, int pos, int n, int k)
		{
			if(k==0){
				mainAns.push_back(ans);
				return;
			}
			if(pos > n)
				return;
			//picking the element
			ans.push_back(pos);
			findAns(ans, mainAns, pos + 1, n, k-1);
			ans.pop_back();
			//not picking the element
			findAns(ans, mainAns, pos + 1, n , k);

		}
		vector<vector<int>> combination(int n,int k)
		{
			vector<vector<int>> mainAns;
			vector<int> ans;
			int pos =0;
			findAns(ans, mainAns, pos, n, k);
			return ans;
		}
}
