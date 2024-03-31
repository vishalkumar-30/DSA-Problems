class Solution {
public:
    int maxBottlesDrunk(int nB, int ne) {
        if(ne > nB) return nB;
        if(ne == nB) return nB+1;
        int ans = nB;
        int emp = nB;
        while(emp>=ne){
            ans++;
            emp -= ne;
            ne++;
            emp++;
        }
        return ans;
    }
};