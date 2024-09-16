class Solution {
public:
    int timeConvertToMinutes(string time)
    {
        int hourToMinute = stoi(time.substr(0, 2)) * 60;
        int minute = stoi(time.substr(3, 2));
        return hourToMinute + minute;
    }

    int findMinDifference(vector<string>& timePoints) 
    {
        // Sort the time points
        sort(begin(timePoints), end(timePoints));

        // Add the first time point again at the end to account for the circular nature of time
        timePoints.push_back(timePoints[0]);

        // Variable to store the minimum difference
        int ans = INT_MAX, n = timePoints.size(), time_one, time_two;
        
        // Loop through the time points to find the minimum difference
        for(int i = 0; i < n - 1; i++)
        {
            time_one = timeConvertToMinutes(timePoints[i]);
            time_two = timeConvertToMinutes(timePoints[i + 1]);
            
            // Calculate the difference between consecutive time points
            ans = min(ans, abs(time_one - time_two));
            
            // Calculate the difference considering the circular nature of time
            ans = min(ans, abs(time_one - (1440 + time_two)));
        }
        return ans;
    }
};