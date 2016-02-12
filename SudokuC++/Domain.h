#ifndef DOMAIN_H
#define DOMAIN_H

#include<vector>
#include<algorithm>
using std::vector;

class Domain {
	vector<int> values;
	bool modified;

public:
	Domain() {}

	Domain(int value) {
		values.push_back(value);
	}

	Domain(vector<int> vals) {
		values.clear();
		values = vals;
	}

	Domain(const Domain &d) {
		values.clear();
		values = d.values;
		modified = d.modified;
	}

	~Domain(){}


	vector<int> getValues() {
		return values;
	}

	int size() {
		return values.size();
	}

	bool isEmpty() {
		return values.empty();
	}

	bool isModified() {
		return modified;
	}

	bool remove(int value) {
		int oldSize = values.size();
		values.erase(std::remove(values.begin(), values.end(), value), values.end());
		if (oldSize == values.size())
			return false;
		setModified(true);
		return true;
	}

	void setModified(bool mod) {
		modified = mod;
	}

	bool operator==(const Domain &rhs) {
		return this->values == rhs.values && this->modified == rhs.modified;
	}

	bool operator!=(const Domain &rhs) {
		return !(*this == rhs);
	}
};


#endif