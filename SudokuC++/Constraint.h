#ifndef CONSTRAINT_H
#define CONSTRAINT_H


#include<vector>
#include<algorithm>
#include "Variable.h"
using std::vector;


struct Constraint {
	std::vector<Variable> vars;

	Constraint() {

	}

	Constraint(std::vector<Variable> v) {
		vars = v;
	}

	void addVariable(Variable v) {
		vars.push_back(v);
	}

	int size() {
		return vars.size();
	}

	bool contains(Variable v) {
		return std::find(vars.begin(), vars.end(), v) != vars.end();
	}

	bool isModified() {
		for (Variable var : vars)
			if (var.isModified())
				return true;
		return false;
	}

	bool propagateConstraint() {
		for (Variable var : vars) 
		{
			int num = var.getAssignment();
			if (num) 
			{
				for (Variable vOther : vars) 
				{
					if (&vOther != &var && vOther.getAssignment == num)
						return false;
				}
			}
		}
	}

	bool isConsistent() {
		return propagateConstraint();
	}
};


#endif
