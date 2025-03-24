#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            unordered_map<int, bool> meeting_days;
            for (int i = 1; i <= days; i++) {
                meeting_days[i] = true;
            }

            for (auto meeting : meetings) {
                for (int i = meeting[0]; i <= meeting[1]; i++) {
                    meeting_days[i] = false;
                }
            }

            return count_if(meeting_days.begin(), meeting_days.end(),
                        [](pair<int, bool> day) {
                            return day.second;
                        }
                    );
        }

        int countDaysOptimized(int days, vector<vector<int>>& meetings) {
            int freeDays = 0;
            int latestEnd = 0;

            sort(meetings.begin(), meetings.end(),
                [](vector<int> a, vector<int> b) {
                    return a[0] < b[0];   // sort based off starting time of meetings
                });
            
            for (auto& meeting : meetings) {
                if (meeting[0] > latestEnd) {
                    freeDays += meeting[0] - latestEnd - 1;
                }
                latestEnd = max(latestEnd, meeting[1]);
            }

            freeDays += days - latestEnd;

            return freeDays;
        }
    };