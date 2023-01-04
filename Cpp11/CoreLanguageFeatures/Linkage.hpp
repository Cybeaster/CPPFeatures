#pragma once

namespace{
    static int var;
}

namespace cpp12
{
   static int var;
} // namespace cpp12


namespace cpp11
{
    int var; 
} // namespace cpp11

static void funstatic()
{
    var = 1;
}


void fun(int*& outVarGlobal, int*& outVarLocal)
{
    funstatic();
    
    var = 5;
    static int var3;
    int var2 = 1;
    var3 = 1;
    outVarLocal = &var2;
    outVarGlobal = &var3;

}