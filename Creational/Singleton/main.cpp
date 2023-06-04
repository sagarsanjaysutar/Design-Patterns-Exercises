#include "Database.h"

int main()
{
    Database::GetInstance(); // Makes a new instance.
    Database::GetInstance(); // Returns existing one.
    return 0;
}