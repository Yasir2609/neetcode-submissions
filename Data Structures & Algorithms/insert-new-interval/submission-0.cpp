class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& nums){
        vector<vector<int>> ans;

        int n = nums.size();
        sort(nums.begin(),nums.end());

        int start1 = nums[0][0];
        int end1 = nums[0][1];

        for(int i=1;i<n;i++){
            int start2 = nums[i][0];
            int end2 = nums[i][1];

            if(end1 >= start2){
                end1 = max(end1,end2);
            }
            else{
                ans.push_back({start1,end1});
                start1 = start2;
                end1=end2;
            }
        }

        ans.push_back({start1,end1});

        return ans;
    }


    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> res;

        int n = intervals.size();
        bool inserted = false;

        for(int i=0;i<n;i++){
            if(intervals[i][0] >= newInterval[0] && !inserted){
                res.push_back(newInterval);
                inserted = true;
            }

            res.push_back(intervals[i]);
        }

        if(!inserted){
            res.push_back(newInterval);

            return merge(res);
        }
        
    }
};
