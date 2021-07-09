#include <vector>

int main() {
    constexpr std::size_t size = 128;
    auto vec = std::vector<double>(size);
    vec[size] = 0;
    return 0;
}
