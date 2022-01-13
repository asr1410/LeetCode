class Solution {
public:
    static bool compare(vector<int> &p1, vector<int> &p2)
{

    return p1[1] < p2[1];
}
    int findMinArrowShots(vector<vector<int>>& points) {
        //sort the array according to ending coordinates
    sort(points.begin(), points.end(), compare);

    //end is the end of first balloon
    int end = points[0][1];

    // we need at least 1 arrow to burst the first balloon
    int ans = 1;

    //iterate over other balloons
    for (int i = 1; i < points.size(); i++)
    {
        if (points[i][0] <= end)
        {
            continue;
        }
        else
        {

            //else we know that the current balloon does not coincide with other balloons
            //so we set end to the current balloon and increase the ans by one
            end = points[i][1];
            ans++;
        }
    }
    return ans;
    }
};