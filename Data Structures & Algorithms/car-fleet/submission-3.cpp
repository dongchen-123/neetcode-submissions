double time (int pos, int target, int velocity) {
    return (double)(target - pos) / velocity;
}

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::priority_queue<std::pair<int, double>> pos_heap = {};
        std::stack<std::pair<int, double>> pos_stack = {};
        if (position.size() == 1) return 1;
        for (int i = 0; i < position.size(); i++) pos_heap.push({position[i], time(position[i], target, speed[i])});
        while (!pos_heap.empty()) {
            if (pos_stack.empty()) pos_stack.push(pos_heap.top());
            else {
                if (pos_heap.top().second > pos_stack.top().second) pos_stack.push(pos_heap.top());
            }
            pos_heap.pop();
        }
        return pos_stack.size();
    }
};
