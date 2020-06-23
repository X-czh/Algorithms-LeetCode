class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        record[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        auto rec = record[id];
        auto checkin_station = rec.first;
        auto checkin_time = rec.second;
        total_cnts[checkin_station][stationName] += 1;
        total_time[checkin_station][stationName] += t - checkin_time;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return double(total_time[startStation][endStation]) / total_cnts[startStation][endStation];
    }
private:
    unordered_map<string, unordered_map<string, int>> total_cnts;
    unordered_map<string, unordered_map<string, long>> total_time;
    unordered_map<int, pair<string, int>> record;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
