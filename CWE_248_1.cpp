/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE248_Uncaught_Exception__no_exception_handling_01.cpp
Label Definition File: CWE248_Uncaught_Exception.label.xml
Template File: point-flaw-01.tmpl.cpp
*/
/*
 * @description
 * CWE: 248 Uncaught Exception
 * Sinks: no_exception_handling
 *    GoodSink: Catch the exception if one occurs
 *    BadSink : Do not attempt to catch the possible exception
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

namespace CWE248_Uncaught_Exception__no_exception_handling_01
{

#ifndef OMITBAD

void bad()
{
    {
        string a = "hello";
        /* FLAW: This will undoubtedly throw an out_of_range error since the two
         * random numbers are almost certainly not going to constitute a valid
         * range in "hello"
         */
        string b = a.substr(rand(), rand());
        printLine(b.c_str());
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        try
        {
            string a = "hello";
            /* FIX: catch the out_of_range error */
            string b = a.substr(rand(), rand());
            printLine(b.c_str());
        }
        catch (out_of_range &)
        {
            printLine("Range specified was invalid");
        }
    }
}

void good()
{
    good1();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE248_Uncaught_Exception__no_exception_handling_01; // so that we can use good and bad easily

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
