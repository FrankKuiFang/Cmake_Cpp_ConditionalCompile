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

//ÿһ�������solution�࣬����ChinaSolution�࣬�����䱸һ��SolutionInfo�������ڴ洢��solution��name ��version,�Լ�����һ����solution
//�Ķ�������Ҫ�ĺ�����
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
        //ÿ����һ��SolutionInfo���󣬸ö��󶼻ᱻע�ᵽSolutionFactory��
        //��ĳ�������solution�ļ�������ʱ���ͻ�����һ����Ӧ��SolutionInfo����ע�ᵽSolutionFactory
        SolutionFactory::getInstance().registerSimulator(this);
    }
};

//�ú������� �����solution�࣬����ChinaSolution�У����ӳ�Ա������
#define DECLARE_SOLUTION_CREATE(CLASS_NAME)              \
public:                                               \
    static BaseSolution* CreateObject(){ return new CLASS_NAME##Solution(); }    \
private:                                              \
    static SolutionInfo* ClassInfo_;    

//�ú����ڷ��� �����solution���cpp�У�����ChinaSolution.cpp�У�ΪClassInfo_��Ա��ֵ��
#define IMPL_SOLUTION_CREATE(CLASS_NAME, SIMULATOR_NAME, VERSION)                 \
SolutionInfo* CLASS_NAME##Solution::ClassInfo_ =                  \
     new SolutionInfo( #SIMULATOR_NAME, #VERSION, (FuncCreateSolution)( CLASS_NAME##Solution::CreateObject));  