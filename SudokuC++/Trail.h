#ifndef TRAIL_H
#define TRAIL_H

#include<stack>
//#include<utility>
#include<algorithm>
#include "Variable.h"
#include "Domain.h"
using std::stack;

class Trail {
	static stack<int> breadcrumbs;
	static stack < std::pair <Variable, Domain> > trail;
	static Trail TRAIL;

	Trail() {}


public:


	~Trail() {}

	static Trail getTrail() {
		return TRAIL;
	}

	void clearTrail() {
		stack < std::pair <Variable, Domain> > empty;
		std::swap(trail, empty);
	}

	int size() {
		return trail.size();
	}

	void placeBreadCrumb() {
		breadcrumbs.push(trail.size());
	}

	void push(Variable &v) {
		std::pair <Variable, Domain> vPair(v, Domain(v.getDomain));
		trail.push(vPair);
	}

	void undo() {
		int targetSize = breadcrumbs.top();
		breadcrumbs.pop();
		for (int size = trail.size(); size > targetSize; --size) {
			std::pair <Variable, Domain> vPair = trail.top();
			trail.pop();
			vPair.first.setDomain(vPair.second);
		}
	}

};

stack<int> Trail::breadcrumbs;
stack < std::pair <Variable, Domain> > Trail::trail;
Trail Trail::TRAIL;

#endif