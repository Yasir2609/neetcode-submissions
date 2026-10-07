class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;
        int maxArea = 0;

        while (i < j) {
            int height = min(heights[i], heights[j]);
            int width = j - i;

            int area = height * width;
            maxArea = max(maxArea, area);

            if (heights[i] < heights[j]) {
                i++;
            } else {
                j--;
            }
        }

        return maxArea;
    }
};