class ProductOfNumbers {
public:
    vector<unsigned long long> products; // Store cumulative products
    vector<int> zeroIdx; // Store indexes of zeros

    ProductOfNumbers() {
        products.push_back(1); // Base product (neutral element)
    }
    
    void add(int num) {
        if (num == 0) {
            products.push_back(1); // Reset product after zero
            zeroIdx.push_back(products.size() - 1); // Store zero index
        } else {
            products.push_back(products.back() * num);
        }
    }
    
    int getProduct(int k) {
        int startIdx = products.size() - k - 1;
        
        // If there is a zero in the last k elements, return 0
        if (!zeroIdx.empty() && zeroIdx.back() > startIdx) {
            return 0;
        }
        
        return products.back() / products[startIdx];
    }
};
