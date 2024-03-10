class Solution {
    public:
        std::string removeDuplicates(std::string s, int k) {
                std::stack<std::pair<char, int>> stk;

                        for (char ch : s) {
                                    if (!stk.empty() && stk.top().first == ch) {
                                                    stk.top().second++;
                                                                    if (stk.top().second == k) {
                                                                                        stk.pop();
                                                                                                        }
                                                                                                                    } else {
                                                                                                                                    stk.push({ch, 1});
                                                                                                                                                }
                                                                                                                                                        }

                                                                                                                                                                std::string result;
                                                                                                                                                                        while (!stk.empty()) {
                                                                                                                                                                                    auto [ch, count] = stk.top();
                                                                                                                                                                                                stk.pop();
                                                                                                                                                                                                            result.insert(result.begin(), count, ch);
                                                                                                                                                                                                                    }

                                                                                                                                                                                                                            return result;
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                };
