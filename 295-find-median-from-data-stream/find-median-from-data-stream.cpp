class MedianFinder {
public:
long long sum;
long long n;
    MedianFinder() {
        

    }
    priority_queue<int>maxh;
    priority_queue<int, vector<int>, greater<int>>minh;
    void addNum(int num) {
        if(maxh.empty() && minh.empty()) maxh.push(num);
        else{
            if(num > maxh.top()) minh.push(num);
            else maxh.push(num);
        }
        int n = minh.size();
        int m = maxh.size();
        if(m-n==2 || m-n==-2){
            if(m>n){
                minh.push(maxh.top());
                maxh.pop();
            }
            else{
                maxh.push(minh.top());
                minh.pop();
            }
        }
    }
    
    double findMedian() {
        if(minh.size()>maxh.size()) return minh.top();
        else if(minh.size()<maxh.size()) return maxh.top();
        else{
            return ((double)maxh.top()+(double)minh.top())/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */