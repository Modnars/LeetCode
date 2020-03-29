// URL    : https://leetcode-cn.com/contest/weekly-contest-182/problems/design-underground-system/
// Author : Modnar
// Date   : 2020/03/29

#include <bits/stdc++.h>

/* ************************* */

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

class UndergroundSystem {
public:
    UndergroundSystem() { }
    
    void checkIn(int id, std::string stationName, int t) {
        in_rec[stationName][id] = t;
    }
    
    void checkOut(int id, std::string stationName, int t) {
        out_rec[stationName][id] = t;
    }
    
    double getAverageTime(std::string startStation, std::string endStation) {
        int count = 0;
        double total = 0.0;
        const auto beg = in_rec[startStation], end = out_rec[endStation];
        for (const auto &rec : beg)
            if (end.find(rec.first) != end.end()) {
                ++count;
                total += end.find(rec.first)->second - beg.find(rec.first)->second;
            }
        return total / count;
    }

private:
    std::map<std::string, std::map<int, int>> in_rec;
    std::map<std::string, std::map<int, int>> out_rec;
};

/* ************************* */

int main(int argc, const char *argv[]) {
    UndergroundSystem *undergroundSystem = new UndergroundSystem();
    undergroundSystem->checkIn(45, "Leyton", 3);
    undergroundSystem->checkIn(32, "Paradise", 8);
    undergroundSystem->checkIn(27, "Leyton", 10);
    undergroundSystem->checkOut(45, "Waterloo", 15);
    undergroundSystem->checkOut(27, "Waterloo", 20);
    undergroundSystem->checkOut(32, "Cambridge", 22);
    std::cout << undergroundSystem->getAverageTime("Paradise", "Cambridge") << std::endl;
    // 返回 14.0。从 "Paradise"（时刻 8）到 "Cambridge"(时刻 22)的行程只有一趟
    std::cout << undergroundSystem->getAverageTime("Leyton", "Waterloo") << std::endl;
    // 返回 11.0。总共有 2 躺从 "Leyton" 到 "Waterloo" 的行程，编号为 id=45 的乘客出发于 time=3 到达于 time=15，编号为 id=27 的乘客于 time=10 出发于 time=20 到达。所以平均时间为 ( (15-3) + (20-10) ) / 2 = 11.0
    undergroundSystem->checkIn(10, "Leyton", 24);
    std::cout << undergroundSystem->getAverageTime("Leyton", "Waterloo") << std::endl;
    // 返回 11.0
    undergroundSystem->checkOut(10, "Waterloo", 38);
    std::cout << undergroundSystem->getAverageTime("Leyton", "Waterloo") << std::endl;
    // 返回 12.0
    return EXIT_SUCCESS;
}
