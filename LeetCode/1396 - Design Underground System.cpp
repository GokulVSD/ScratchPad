// https://leetcode.com/problems/design-underground-system/submissions/

// Relatively straight forward with the usage of maps.

class UndergroundSystem {
public:
    
    map< pair<string, string>, vector<int> > deltas;
    unordered_map< int, pair<string, int> > transit;
    
    UndergroundSystem() {
        deltas = {};
        transit = {};
    }
    
    void checkIn(int id, string stationName, int t) {
        transit[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        auto a = transit[id];
        deltas[make_pair(a.first, stationName)].emplace_back(t - a.second);
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto a = deltas[make_pair(startStation, endStation)];
        return accumulate(a.begin(), a.end(), 0.0) / a.size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */