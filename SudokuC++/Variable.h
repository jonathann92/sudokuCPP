#ifndef VARIABLE_H
#define VARIABLE_H

#include<vector>
#include<string>
#include "Domain.h"
#include "Trail.h"
using std::string;
using std::vector;

class Variable {
	static int namingCounter;
	Domain domain;
	int row, col, block;
	bool modified;
	bool unchangeable;
	string name = "v";
	Trail trail = Trail::getTrail();
	int oldSize;

public:
	Variable() {}
	~Variable() {}

	Variable(vector<int> possible_values, int xrow, int xcol, int xblock) {
		domain = Domain(possible_values);
		if (size() == 1) {
			modified = true;
			unchangeable = true;
		}

		row = xrow;
		col = xcol;
		block = xblock;
		name.append(std::to_string(++namingCounter));
		oldSize = size();
	}

	Variable(const Variable &v) {
		domain = v.domain;
		row = v.row;
		col = v.col;
		block = v.block;
		modified = v.modified;
		name = v.name;
	}

	bool isChangable() {
		return !unchangeable;
	}

	bool isAssigned() {
		return size() == 1;
	}

	bool isModified() {
		return modified;
	}

	void setModified(bool mod) {
		modified = mod;
		domain.setModified(modified);
	}

	int row() {
		return row;
	}

	int col() {
		return col;
	}

	int block() {
		return block;
	}

	int getAssignment() {
		if (!this->isAssigned())
			return 0;
		return domain.getValues()[0];
	}

	vector<int> values() {
		return domain.getValues();
	}

	int size() {
		return domain.size();
	}

	Domain getDomain() {
		return domain;
	}

	string getName() {
		return name;
	}


	void updateDomain(const Domain &d) {
		methodModifiesDomain();

		if (domain != d) {
			domain = d;
			modified = true;
		}
	}

	void setDomain(const Domain &d) {
		if (domain != d) {
			domain = d;
			modified = true;
		}
	}

	void removeValueFromDomain(int val) {
		methodModifiesDomain();
		domain.remove(val);
		this->modified = domain.isModified();
	}

	void methodModifiesDomain() {
		int newSize = size();
		if (oldSize > newSize) {
			oldSize = newSize;
		}

		trail.push(*this);
	}

};

int Variable::namingCounter = 0;

#endif