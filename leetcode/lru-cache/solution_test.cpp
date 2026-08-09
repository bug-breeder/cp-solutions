#include "../../tools/leetcode.h"
#include "solution.cpp"

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    test(cache.get(1) == 1, "get(1) == 1");
    cache.put(3, 3); // evicts key 2
    test(cache.get(2) == -1, "get(2) == -1 (evicted)");
    cache.put(4, 4); // evicts key 1
    test(cache.get(1) == -1, "get(1) == -1 (evicted)");
    test(cache.get(3) == 3, "get(3) == 3");
    test(cache.get(4) == 4, "get(4) == 4");
    return summary();
}
