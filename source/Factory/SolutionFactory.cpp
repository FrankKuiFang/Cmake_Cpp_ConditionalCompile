#include "SolutionFactory.hpp"
#include <algorithm>

#include "../Base.hpp"

std::vector<SolutionInfo*> SolutionFactory::mClasses;

/*
SolutionFactory* SolutionFactory::getInstance()
{
    static SolutionFactory* instance = nullptr;

    if (!instance) {
        instance = new SolutionFactory();
    }

    return instance;
}*/

//C++11 已经保证了satic变量的线程安全性
SolutionFactory& SolutionFactory::getInstance()
{
    static SolutionFactory instance;
    return instance;
}

bool SolutionFactory::registerSimulator(SolutionInfo* ClassInfo)
{
    mClasses.push_back(ClassInfo);

    return true;
}

std::shared_ptr<BaseSolution> SolutionFactory::getSolution(const std::string& solutionName,
    const std::string& version)
{
    std::shared_ptr<BaseSolution> solutionObj = nullptr;

    std::string solutionNameUpper = solutionName;
    std::string ver = version;
    std::transform(solutionNameUpper.begin(), solutionNameUpper.end(), solutionNameUpper.begin(), ::toupper);
    std::transform(ver.begin(), ver.end(), ver.begin(), ::toupper);

    for (auto solutionInfo : mClasses) {
        std::transform(solutionInfo->mName.begin(), solutionInfo->mName.end(),
            solutionInfo->mName.begin(), ::toupper);
        std::transform(solutionInfo->mVersion.begin(), solutionInfo->mVersion.end(),
            solutionInfo->mVersion.begin(), ::toupper);

        if (solutionInfo->mName == solutionNameUpper &&(solutionInfo->mVersion == ver))
        {
            solutionObj.reset(solutionInfo->mFunc());
        }
    }

    return solutionObj;
}