// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.

class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:

	bool peeked;
	int val;

	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		peeked = false;
		val = -1;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (peeked) return val;
		peeked = true;
		val = Iterator::next();
		return val;
	}

	int next() {
		if (peeked) {
			peeked = false;
			return val;
		} else return (Iterator::next());
	}

	bool hasNext() const {
		return (peeked || Iterator::hasNext());
	}
};

