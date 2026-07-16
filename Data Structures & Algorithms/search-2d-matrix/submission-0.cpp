class Solution {
public:

    bool search(vector<int>&nums,int target){
        int low = 0;
        int high = nums.size()-1;

        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid] > target) high = mid-1;
            else low = mid+1;
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i =0;i<n;i++){
            if(target >= matrix[i][0] && target <= matrix[i][m-1]){
                return search(matrix[i],target);
            }
        }

        return false;
    }
};
