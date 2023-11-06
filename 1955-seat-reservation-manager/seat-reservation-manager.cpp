class SeatManager {
private:
    set<int> seats;
public:
    SeatManager(int n) {
        for(int i = 0; i<n; i++){
            seats.insert(i+1);
        }
    }
    
    int reserve() {
        int firstseat = *seats.begin();
        seats.erase(seats.begin());
        return firstseat;
    }
    
    void unreserve(int seatNumber) {
        seats.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */