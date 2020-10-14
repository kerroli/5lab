#include <iostream>
#include <unordered_map>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <set>

void printPair(std::pair<std::string, int> map);
void printVec(int a);
bool isCondition(const std::pair<std::string, int> map);
int keyValue(const std::pair<std::string, int> map);
bool comparator(int a, int b);
bool compareInt(const int& a);

int main() {
    // task1
    std::unordered_multimap<std::string, int> months({ {"Jan", 1}, {"Feb1", 2}, {"Feb2", 2}, {"Mar", -3}, {"Apr", -4},
        {"May1", -5}, {"Jun", -6}, {"Jul", 7}, {"Aug", 8}, {"Sep", 9}, {"Oct", -10} , {"Nov", 11}, {"Dec", -12} });
    // print
    std::for_each(months.begin(), months.end(), printPair);
    std::cout << std::endl;
    // add pair of months May, 5
    months.insert(std::make_pair<std::string, int>("May2", 5));
    months.insert(std::make_pair<std::string, int>("May3", 5));
    // print
    std::for_each(months.begin(), months.end(), printPair);
    std::cout << std::endl;
    // erase ONLY one '2'
    for (auto x = months.begin(); x != months.end(); x++) {
        if (x->second == 2) {
            months.erase(x);
            break;
        }
    }
    // print
    std::for_each(months.begin(), months.end(), printPair);
    std::cout << std::endl;
    // copy to map
    std::map <std::string, int> Smonths;
    for (auto x : months) {
        Smonths.insert(std::make_pair(x.first, x.second));
    }
    // print
    std::for_each(Smonths.begin(), Smonths.end(), printPair);
    std::cout << std::endl;
    // task2
    // count negatives then print amount
    int cond = std::count_if(Smonths.begin(), Smonths.end(), isCondition);
    std::cout << "Negatives: " << cond << std::endl;
    // convert to vector
    std::vector<int> vecOfKeys;
    std::transform(Smonths.begin(), Smonths.end(), std::back_inserter(vecOfKeys), keyValue);
    // print
    std::for_each(vecOfKeys.begin(), vecOfKeys.end(), printVec);
    std::cout << std::endl;
    // task3
    // find iterator of 8 then print its placement ( +1 )
    auto iter = std::find(vecOfKeys.begin(), vecOfKeys.end(), 8);
    if (iter == vecOfKeys.end())
        std::cout << "Error: 404" << std::endl;
    else
        std::cout << "Iterator of 8: " << iter - vecOfKeys.begin()+1 << std::endl;
    // replace every X > 0 with 10
    std::replace_if(vecOfKeys.begin(), vecOfKeys.end(), compareInt, 10);
    // print
    std::for_each(vecOfKeys.begin(), vecOfKeys.end(), printVec);
    std::cout << std::endl;
    // sorting our vector
    std::sort(vecOfKeys.begin(), vecOfKeys.end(), comparator);
    // print
    std::for_each(vecOfKeys.begin(), vecOfKeys.end(), printVec);
    std::cout << std::endl;
    // convert to set
    std::set<int> mySet;
    for (int i : vecOfKeys)
        mySet.insert(i);
    // print
    std::for_each(mySet.begin(), mySet.end(), printVec);
    std::cout << std::endl;
    return 0;
}

void printPair(std::pair<std::string, int> map) {
    std::cout << map.first << ": " << map.second << std::endl;
}

bool isCondition(const std::pair<std::string, int> map){
    return map.second < 0;
}

int keyValue(const std::pair<std::string, int> map) {
    return map.second;
}

void printVec(int i) {
    std::cout << i << ' ';
}

bool compareInt(const int& a) {
    return a > 0;
}

bool comparator(int a, int b){
    return a > b;
}
