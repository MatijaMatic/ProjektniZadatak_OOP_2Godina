#ifndef __greskaunos_h__
#define __greskaunos_h__
using namespace std;
#include <stdexcept>
#include <string>

class UnosGreska : public runtime_error {
public:
    UnosGreska(const string& message) : runtime_error(message) {}
};

#endif //!__greskaunos_h__
