class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
    set<int> st;
    vector<int> ans;
    int sum1 = 0, sum2 = 0;
    
    for (auto it : bobSizes) {
        sum2 += it;
        st.insert(it); // Corrected from st.push(it)
    }
    
    for (auto it : aliceSizes) {
        sum1 += it;
    }
    
    int delta = (sum2 - sum1) / 2;
    
    for (int k = 0; k < aliceSizes.size(); k++) {
        auto it = st.find(aliceSizes[k] + delta); 
        if (it != st.end()) {
            ans.push_back(aliceSizes[k]);
            ans.push_back(aliceSizes[k] + delta);
            return ans; 
        }
    }
    
    return ans;
}
};