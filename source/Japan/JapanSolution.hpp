#pragma once
#include <iostream>
#include "../Base.hpp"
using namespace std;

class JapanSolution:public BaseSolution{
	
public:
    JapanSolution(){
	}

    virtual ~JapanSolution(){}	
	
	virtual void Solve() override;

    DECLARE_SOLUTION_CREATE(Japan);
};