#ifndef ITRANSPORT_H
#define ITRANSPORT_H

#include <iostream>
using namespace std;

/**
 * \brief A common Product Inteface
 */
class iTransport
{
public:
    /**
     * \brief Virtual destructor is necessary in an interface.
     * \ref https://stackoverflow.com/a/3628611/19139887
     */
    virtual ~iTransport()
    {
        cout << "iTransport::~iTransport()" << endl;
    };

    virtual void deliver() = 0;
};

#endif
