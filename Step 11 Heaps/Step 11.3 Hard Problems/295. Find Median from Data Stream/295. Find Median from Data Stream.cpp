// https://www.youtube.com/watch?v=KcPV49pJYQg

class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> maxHeap_lp;
    priority_queue<int, vector<int>, greater<int>> minHeap_rp;
public:
    MedianFinder() {
        maxHeap_lp = priority_queue<int, vector<int>, less<int>> ();
        minHeap_rp = priority_queue<int, vector<int>, greater<int>>();
    }
    
    void addNum(int num) {
        // maxHeap_lp.push(num);
        
        // minHeap_rp.push(maxHeap_lp.top());
        // maxHeap_lp.pop();

        // if (maxHeap_lp.size() < minHeap_rp.size()) {
        //     maxHeap_lp.push(minHeap_rp.top());
        //     minHeap_rp.pop();
        // }

        if (maxHeap_lp.empty() || num <= maxHeap_lp.top()) maxHeap_lp.push(num);
        else minHeap_rp.push(num);

        if (maxHeap_lp.size() > minHeap_rp.size() + 1) {
            minHeap_rp.push(maxHeap_lp.top());
            maxHeap_lp.pop();
        } else if (maxHeap_lp.size() < minHeap_rp.size()) {
            maxHeap_lp.push(minHeap_rp.top());
            minHeap_rp.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap_lp.size() == minHeap_rp.size())
            return (maxHeap_lp.top() + minHeap_rp.top()) / 2.0;
        return maxHeap_lp.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */