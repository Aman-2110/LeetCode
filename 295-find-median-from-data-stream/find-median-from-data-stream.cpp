class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> maxi;
    priority_queue<int> mini;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mini.size() == maxi.size()){
            if(maxi.empty() || num <= maxi.top())
                mini.push(num);
            else{
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(num);
            }
        }else{
            if(num >= mini.top())
                maxi.push(num);
            else{
                maxi.push(mini.top());
                mini.pop();
                mini.push(num);
            }
        }
    }
    
    double findMedian() {
        if(mini.size() == maxi.size())
            return (mini.top() + maxi.top())/2.0;
        return mini.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */