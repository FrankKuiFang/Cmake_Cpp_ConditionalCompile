#pragma once
#include <iostream>
#include "../Base.hpp"
using namespace std;

class EuroSolution:public BaseSolution{
	
public:
    EuroSolution(){
	}

    virtual ~EuroSolution(){}	
	
	virtual void Solve() override;

    DECLARE_SOLUTION_CREATE(Euro);
};