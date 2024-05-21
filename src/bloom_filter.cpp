#include <iostream>
#include <vector>
#include <functional>
#include <cmath> // Include cmath for log function

template<size_t N, size_t K>
class BloomFilter {
private:
    std::vector<bool> bitArray;

public:
    BloomFilter() : bitArray(N, false) {}

    void insert(unsigned long long int x) {
        for (size_t i = 0; i < K; ++i) {
            size_t index = (std::hash<unsigned long long int>{}(x) + i * std::hash<unsigned long long int>{}(x << 16)) % N;
            bitArray[index] = true;
        }
    }

    bool query(unsigned long long int x) {
        for (size_t i = 0; i < K; ++i) {
            size_t index = (std::hash<unsigned long long int>{}(x) + i * std::hash<unsigned long long int>{}(x << 16)) % N;
            if (!bitArray[index]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    // Dimension a Bloom filter for a set of around 5K elements
    const size_t N = 10000; // Size of Bloom filter
    const size_t K = static_cast<size_t>(N / 5000 * std::log(2)); // Optimal value of K

    BloomFilter<N, K> bloomFilter;

    // Simulating packet trace
    std::vector<unsigned long long int> packetTrace = {192168001001ULL, 192168001002ULL, 192168001003ULL, 192168001001ULL, 192168001004ULL};

    // Go through the packet trace and insert new IP addresses in the Bloom filter
    for (const auto& ip : packetTrace) {
        bloomFilter.insert(ip);
    }

    // Increment the counter only if the IP destination is new
    size_t uniqueCount = 0;
    for (const auto& ip : packetTrace) {
        if (bloomFilter.query(ip)) {
            ++uniqueCount;
        }
    }

    // Print the estimated count
    std::cout << "Estimated count of unique IP destinations: " << uniqueCount << std::endl;

    // Exact count (assuming all elements in packet trace are unique)
    size_t exactCount = packetTrace.size();
    std::cout << "Exact count of unique IP destinations: " << exactCount << std::endl;

    return 0;
}
