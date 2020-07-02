class UndergroundSystem {
public:
    unordered_map<int, pair<string, int> > id_to_station_time;
    map<pair<string, string>, pair<int, int> > start_end_to_time_persons;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        id_to_station_time[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string start_station = id_to_station_time[id].first;
        int intime = id_to_station_time[id].second;
        if(start_end_to_time_persons.find({start_station, stationName}) == start_end_to_time_persons.end()) {
            start_end_to_time_persons[{start_station, stationName}] = {(t - intime), 1};
        } else {
            pair<int, int> p = start_end_to_time_persons[{start_station, stationName}];
            start_end_to_time_persons[{start_station, stationName}] = {p.first + (t - intime), p.second+1};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<int, int> p = start_end_to_time_persons[{startStation, endStation}];
        return p.first/((double)p.second);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
 