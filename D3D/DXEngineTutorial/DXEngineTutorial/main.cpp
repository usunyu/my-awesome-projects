#include "Framework.h"

void main()
{
    Framework* framework = new Framework();

    if (framework->Initialize())
    {
        framework->Run();
    }

    delete framework;

    return;
}