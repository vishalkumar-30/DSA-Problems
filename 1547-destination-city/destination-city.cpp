class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> cities;

        // Collect outgoing cities
        for (const auto& path : paths) {
            cities.insert(path[0]);
        }

        // Find destination city with no outgoing path
        for (auto& path : paths) {
            string dest = path[1];
            if (cities.find(dest) == cities.end()) {
                return dest;
            }
        }

        return "";
    }
};