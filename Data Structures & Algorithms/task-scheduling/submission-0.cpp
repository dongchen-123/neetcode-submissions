#include <queue>
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::unordered_map<char, int> freq;
        for (const auto& task : tasks) freq[task]++;
        int task_cnt = tasks.size();
        int cycles = 0;
        std::priority_queue<std::pair<int, char>> heap;
        std::queue<std::pair<int, char>> q;
        for (const auto& f : freq) heap.push({f.second, f.first});
        while (task_cnt > 0) {
            if (q.size() == n+1) {
                if (q.front().first != 0) heap.push(q.front());
                q.pop();
            }
            if (!heap.empty()) {
                if (heap.top().first != 0) {
                    auto tmp = heap.top();
                    tmp.first--;
                    q.push(tmp);
                }
                heap.pop();
                task_cnt--;
            }
            else q.push({0, '\0'});
            cycles++;
        }
        return cycles;
    }
};
