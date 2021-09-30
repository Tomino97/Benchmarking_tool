#include <list>
#include <random>
#include <iostream>
#include <cstring>
#include <sstream>

#include "ubench.hpp"

class pq_list {
    std::list<int> queue;
    unsigned int maxItems;
public:
    explicit pq_list(unsigned int max): maxItems(max) {}

    void insert(int value) {
        queue.emplace_back(value);
        if(queue.size() > maxItems) {
            if (queue.size() > maxItems) {
                queue.erase(std::min_element(queue.begin(), queue.end()));
            }
        }
    }

    int top() {
        return *std::max_element(queue.begin(), queue.end());
    }

    void remove() {
        if (!queue.empty()) {
            queue.erase(std::max_element(queue.begin(), queue.end()));
        }
    }

    bool empty() {
        return queue.empty();
    }
};


std::vector<int> values;
pq_list queue(0);

int main(int argc, char** argv) {
    int val, iterations = 0;

    std::istringstream iss( argv[2] );
    if (!(iss >> val)) {
        std::cerr << "Invalid number: " << argv[2] << '\n';
        return 1;
    }

    std::istringstream iss2( argv[3] );
    if (!(iss2 >> iterations)) {
        std::cerr << "Invalid number: " << argv[3] << '\n';
        return 1;
    }

    queue = pq_list(val);
    if (!strcmp(argv[1], "random")) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(1, iterations);
        for(int i = 0; i < iterations; i++) {
            values.emplace_back(distrib(gen));
        }
    }
    else if (!strcmp(argv[1], "ascending")) {
        for(int i = 1; i <= iterations; i++) {
            values.emplace_back(i);
        }
    }
    else if (!strcmp(argv[1], "descending")) {
        for(int i = iterations; i > 0; i--) {
            values.emplace_back(i);
        }
    }
    else {
        std::cerr << "Invalid string: " << argv[1] << '\n';
        return 1;
    }
    ubench::result res = ubench::measure([]() {
        for(auto i : values) {
            queue.insert(i);
        }
    });
    std::cout << res;
    return 0;
}