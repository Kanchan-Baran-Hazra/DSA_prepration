class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;

        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string ans;

        while (!pq.empty()) {
            auto [cnt1, ch1] = pq.top();
            pq.pop();

            int n = ans.size();

            // Using ch1 would make three consecutive characters
            if (n >= 2 && ans[n - 1] == ch1 && ans[n - 2] == ch1) {
                if (pq.empty()) break;

                auto [cnt2, ch2] = pq.top();
                pq.pop();

                ans.push_back(ch2);
                cnt2--;

                if (cnt2 > 0)
                    pq.push({cnt2, ch2});

                pq.push({cnt1, ch1});
            }
            else {
                // Decide whether to use one or two copies
                int use = 1;

                if (cnt1 >= 2 &&
                    (pq.empty() || cnt1 > pq.top().first))
                    use = 2;

                while (use-- && cnt1 > 0) {
                    ans.push_back(ch1);
                    cnt1--;
                }

                if (cnt1 > 0)
                    pq.push({cnt1, ch1});
            }
        }

        return ans;
    }
};