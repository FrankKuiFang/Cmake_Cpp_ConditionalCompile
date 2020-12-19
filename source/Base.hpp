#pragma once
#include <iostream>
#include "SolutionFactory.hpp"

using namespace std;

class BaseSolution{
	
public:
    BaseSolution(){
	}

    virtual ~BaseSolution(){}	
	
	virtual void Solve()=0;
};


typedef BaseSolution* (*FuncCreateSolution)();//define a functioin pointer. 

//每一个具体的solution类，例如ChinaSolution类，都会配备一个SolutionInfo对象，用于存储该solution的name ，version,以及创建一个该solution
//的对象所需要的函数。
struct SolutionInfo
{
    std::string mName;
    std::string mVersion;
    FuncCreateSolution mFunc;

    SolutionInfo(const std::string& name,
        const std::string& version,
        FuncCreateSolution func) : 
        mName(name),
        mVersion(version),
        mFunc(func)
    {
        //每生成一个SolutionInfo对象，该对象都会被注册到SolutionFactory。
        //当某个具体的solution文件被编译时，就会生成一个对应的SolutionInfo对象注册到SolutionFactory
        SolutionFactory::getInstance().registerSimulator(this);
    }
};

//该宏用于在 具体的solution类，例如ChinaSolution中，增加成员变量。
#define DECLARE_SOLUTION_CREATE(CLASS_NAME)              \
public:                                               \
    static BaseSolution* CreateObject(){ return new CLASS_NAME##Solution(); }    \
private:                                              \
    static SolutionInfo* ClassInfo_;    

//该宏用于放在 具体的solution类的cpp中，例如ChinaSolution.cpp中，为ClassInfo_成员赋值。
#define IMPL_SOLUTION_CREATE(CLASS_NAME, SIMULATOR_NAME, VERSION)                 \
SolutionInfo* CLASS_NAME##Solution::ClassInfo_ =                  \
     new SolutionInfo( #SIMULATOR_NAME, #VERSION, (FuncCreateSolution)( CLASS_NAME##Solution::CreateObject));  