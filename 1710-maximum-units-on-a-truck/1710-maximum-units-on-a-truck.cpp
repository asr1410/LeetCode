class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
	int freq[1001]{0}, maxUnits = 0;   // freq[i] = number of boxes that can hold i units
	for(auto& box : boxTypes) freq[box[1]] += box[0];
	// greedily choose starting from max units till either truckSize runs out or you choose all boxes
	for(int units = 1000; truckSize > 0 && ~units; --units) { 
		maxUnits += min(truckSize, freq[units]) * units;
		truckSize -= freq[units];
	}
	return maxUnits;
}
};