class PeekingIterator : public Iterator {
public:

    vector<int>v;
    int i=0;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    v=nums;
	}
	
	int peek() {
        return v[i];
	}
	
	int next() {
	    return v[i++];
	}
	
	bool hasNext() const {
	   if(i<v.size()){
           return true;
       } 
        return false;
	}
};