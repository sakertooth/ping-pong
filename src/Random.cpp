#include "Random.hpp"

int Random::range(int from, int to) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(from, to);
    return dist(mt);
}