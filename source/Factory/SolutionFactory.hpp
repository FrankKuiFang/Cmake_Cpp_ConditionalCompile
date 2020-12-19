#pragma once



#include <string>
#include <vector>
#include <memory>

//#include "../Base.hpp""
class BaseSolution;
class SolutionInfo;

class SolutionFactory
{
public:
    //static SolutionFactory* getInstance();
    static SolutionFactory& getInstance();

    bool registerSimulator(SolutionInfo* Info);

    std::shared_ptr<BaseSolution> getSolution(const std::string& simulator,
        const std::string& version);

private:
    SolutionFactory() {}
    ~SolutionFactory() {}

    static std::vector<SolutionInfo*> mClasses;//���ڴ洢�ù�������������ЩSolution!
};