class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>>rightHalf;//mean heap
    priority_queue<int>leftHalf;//max heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(leftHalf.empty() || num <= leftHalf.top()){
            leftHalf.push(num);
        }else{
            rightHalf.push(num);
        }
        //balance
        if(leftHalf.size() > rightHalf.size() +1){
            rightHalf.push(leftHalf.top());
            leftHalf.pop();
        }else if(rightHalf.size() > leftHalf.size()){
            leftHalf.push(rightHalf.top());
            rightHalf.pop();
        }
    }
    
    double findMedian() {
        if(leftHalf.size()>rightHalf.size()){
            return leftHalf.top();
        }else{
            return (leftHalf.top()+rightHalf.top())/2.0;
        }
    }
};
