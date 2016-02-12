#ifndef TRAIL_H
#define TRAIL_H

#include<stack>
#include<utility>
#include "Variable.h"
#include "Domain.h"
using std::stack;

class Trail {
	static stack<int> breadcrumbs;
	static stack < std::pair <Variable, Domain> > trail;


	Trail() {}


public:
	static Trail TRAIL;

	~Trail() {}

	Trail getTrail() {
		return TRAIL;
	}

	void clearTrail() {
		trail.clear();
	}

	int size() {
		return trail.size();
	}

	void placeBreadCrumb() {
		breadcrumbs.add(trail.size());
	}

	void push(Variable &v) {
		std::pair <Variable, Domain> vPair(v, Domain(v.getDomain));
		trail.push(vPair);
	}

	void undo() {
		int targetSize = breadcrumbs.top();
		breadcrumbs.pop();
		for (int size = trail.size(); size > targetSize; --size) {
			std::pair <Variable, Domain> vPair = trail.pop();
			vPair.first.setDomain(vPair.second);
		}
	}

};

#endif