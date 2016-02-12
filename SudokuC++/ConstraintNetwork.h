#ifndef CONSTRAINT_N_H
#define CONSTRAINT_N_H

#include<vector>
#include<algorithm>
#include"Constraint.h"
#include "Variable.h"

class ConstraintNetwork {
	vector<Constraint> contraints;
	vector<Variable> variables;

public:
	ConstraintNetwork() {}
	~ConstraintNetwork() { }

	void add(Constraint c) {

	}
};


#endif