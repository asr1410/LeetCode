#include <vector>
using namespace std;

class ProductOfNumbers {
public:
    vector<unsigned long long> products;
    int zeroCount = 0;

    ProductOfNumbers() {
        products.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            products.clear();
            products.push_back(1);
            zeroCount = 0;
        } else {
            products.push_back(products.back() * num);
        }
    }

    int getProduct(int k) {
        if (k >= products.size()) return 0;
        return products.back() / products[products.size() - k - 1];
    }
};
