// we can also solve this using a prepopulated set, but in that implementation, the set will contain all the n nodes that we might never need at a time and hence leads to a larger time complexity
// so instead of storing the seats that were reserved in the set, we will store the seats that are unreserved in the pq and track the seats that were stored using a maxstored variable

class SeatManager {

// pq will contain all the unreserved seats

priority_queue<int, vector<int>, greater<int>> pq;

int maxAllotedSeat = 0;
public:
    SeatManager(int n) {
    }
    
    int reserve() {
        if(pq.empty()){
            // pq is empty, so no seat is unreserved upto the value of maxAllotedSeat, so reserve the next seat
            maxAllotedSeat++;
            return maxAllotedSeat;
        }
        else{
            // pq is not empty, so it contains some unreserved seats out of which the smallest one is at the top of the pq
            // we return that seat and pop that seat from the pq as it is no longer unreserved.
            int minUnreservedSeat = pq.top();
            pq.pop();
            return minUnreservedSeat;
        }
        return -1;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */