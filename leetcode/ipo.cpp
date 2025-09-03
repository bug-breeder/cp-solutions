// pick the most k profitable tasks
// ensure the current capital is always >= 0
// profits = [2,7,5,3]
// capital = [0,5,4,1]
// start = 4
// sort by the capital, heap sort by the profits.

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        const int n = profits.size();
        vector<pair<int,int>> projects;
        projects.reserve(n);
        for (int i = 0; i < n; ++i) projects.emplace_back(capital[i], profits[i]);
        sort(projects.begin(), projects.end());

        priority_queue<int> maxProfits;
        long long curr = w;
        int i = 0;

        for (int step = 0; step < k; ++step) {
            while (i < n && projects[i].first <= curr) {
                maxProfits.push(projects[i].second);
                ++i;
            }
            if (maxProfits.empty()) break;

            curr += maxProfits.top();
            maxProfits.pop();
        }
        return curr;
    }
};