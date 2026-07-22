/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        std::vector<int> m_start, m_end;
        for (const auto& itv : intervals) {
            m_start.push_back(itv.start);
            m_end.push_back(itv.end);
        }
        std::sort(m_start.begin(), m_start.end());
        std::sort(m_end.begin(), m_end.end());
        int i = 0;
        int j = 0;
        int count = 0;
        int max_count = 0;
        while (i < m_start.size() || j < m_end.size()) {
            if (i < m_start.size() && m_start[i] < m_end[j]) {
                count++;
                i++;
            }
            else {
                count--;
                j++;
            }
            max_count = max(count, max_count);
        }
        return max_count;
    }
};
