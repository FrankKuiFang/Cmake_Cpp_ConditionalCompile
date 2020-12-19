
#include <iostream>
#include <string>
#include "SolutionFactory.hpp"
#include "Base.hpp"
using namespace std;

int main(int argc, char* argv[]) {

    string solutionName = "Euro";
    //solutionName = "China";
    //solutionName = "Japan";
    string version = "1";


    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--sname") == 0) {
            if (i + 1 < argc) {
                solutionName = argv[i + 1];
            }
            i++;
        }
        if (strcmp(argv[i], "--version") == 0) {
            if (i + 1 < argc) {
                version = argv[i + 1];
            }
            i++;
        }
    }

    std::shared_ptr<BaseSolution> solu = SolutionFactory::getInstance().getSolution(solutionName, version);
    if (!solu) {
        std::cout << "No Solution available with type '" << solutionName << "'" << "version'" << version << "'" << std::endl;
        return -2;
    }
    solu->Solve();

    return 0;
}