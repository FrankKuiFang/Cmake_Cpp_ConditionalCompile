#pragma once
#include <iostream>
#include "../Base.hpp"

using namespace std;

class ChinaSolution :public BaseSolution {

public:
    ChinaSolution() {
    }

    virtual ~ChinaSolution() {}

    virtual void Solve() override;

    DECLARE_SOLUTION_CREATE(China);
};