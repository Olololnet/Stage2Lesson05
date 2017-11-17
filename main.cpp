#include <iostream>

void Exercise3()
{
    // Exercise3: развернуть каждый восьмой бит в числе типа double,
    // используя int или char

    double dSomeDouble = 1111111.;
    const unsigned char ucLastActiveBit = 1;

    unsigned char* ucChar = (unsigned char*) &dSomeDouble;
    for (unsigned int i = 0; i < sizeof(dSomeDouble); i++)
    {
        unsigned char ucLastBit = *ucChar & ucLastActiveBit;

        if (ucLastBit)
            *ucChar = *ucChar & (~ucLastBit);
        else
            *ucChar |= ucLastActiveBit;

        ++ucChar;
    }

    std::cout << (int)dSomeDouble << std::endl;
}

struct CForwardStruct
{
    int iSomeIntInfo;
    CForwardStruct* pNextStruct;
};

void RecursiveReleaseStructsMemory(CForwardStruct* pStartStruct)
{
    if (pStartStruct->pNextStruct)
        RecursiveReleaseStructsMemory(pStartStruct->pNextStruct);

    std::cout << "current remove: " << pStartStruct->iSomeIntInfo << std::endl;
    delete pStartStruct;
}

void Exercise2()
{
    // Exercise2: написать функцию освобождения памяти из под
    // однонаправленного списка

    CForwardStruct* pFirstStruct  = new CForwardStruct;
    pFirstStruct ->iSomeIntInfo = 1;
    CForwardStruct* pSecondStruct = new CForwardStruct;
    pSecondStruct->iSomeIntInfo = 2;
    CForwardStruct* pThirdStruct  = new CForwardStruct;
    pThirdStruct->iSomeIntInfo  = 3;

    pFirstStruct->pNextStruct  = pSecondStruct;
    pSecondStruct->pNextStruct = pThirdStruct;
    pThirdStruct->pNextStruct  = NULL;

    RecursiveReleaseStructsMemory(pFirstStruct);
}

void Remove(char* szBaseString, char* szSubString)
{
    const char chEndChar = '\0';
    char* szBaseStringCopy = szBaseString;

    while (*szBaseStringCopy != chEndChar)
    {
        char* szCopySubString = szSubString;
        char* szCopyBaseStringMoved = szBaseStringCopy;
        while (*szCopySubString != chEndChar)
        {
            if (*szCopyBaseStringMoved != *szCopySubString)
                break;

            ++szCopyBaseStringMoved;
            ++szCopySubString;
        }

        if (*szCopySubString == chEndChar)
        {
            while (*szBaseString++ != chEndChar)
            {
                *szBaseStringCopy++ = *szCopyBaseStringMoved++;

                if (*szCopyBaseStringMoved == chEndChar)
                {
                    *szBaseStringCopy = chEndChar;
                    break;
                }
            }

            break;
        }

        ++szBaseStringCopy;
    }
}

void Exercise1()
{
    // Exercise1: написать функцию удаления подстроки в строке:
    // void remove(char* src, char* substr);
    // одно вхождение

    char szBaseString[] = "somebasestring";
    char szSubString[]  = "base";

    Remove(szBaseString, szSubString);

    std::cout << szBaseString << std::endl;
}

int main()
{
//    Exercise3();
//    Exercise2();
//    Exercise1();

    return 0;
}
