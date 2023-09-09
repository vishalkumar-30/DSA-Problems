class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>result(rowIndex+1, 1);
        for(int j=1; j<result.size()-1; j++){
            for(int i=rowIndex-1; i>=j; i--){
                result[i]=result[i+1] + result[i];
            }
        }
        return result;
    }
};