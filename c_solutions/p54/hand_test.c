#include <stdio.h>
#include <hand.h>

const char *junkStr          = "8H 3C 7D 4S TH";
const char *pairStr          = "2H 2S 3D JD TS";
const char *twoPairStr       = "QH QD AS AC TC";
const char *threeKindStr     = "5H 8H 4C 4D 4S";
const char *straightStr      = "2H 3S 4D 5C 6C";
const char *flushStr         = "5H 6H AH 2H QH";
const char *fullHouseStr     = "QH QC QD AC AS";
const char *fourKindStr      = "7H 7C 7D 7S 2H";
const char *straightFlushStr = "7H 6H 8H 9H TH";
const char *royalFlushStr    = "KS JS QS TS AS";

const char *testBeginForFunctionStr = "beginning tests for function %s\n";
const char *finishedSetStr = "Finished set of tests %s, passed %d out of %d\n";

hand *junkHand;
hand *pairHand;
hand *twoPairHand;
hand *threeKindHand;
hand *straightHand;
hand *flushHand;
hand *fullHouseHand;
hand *fourKindHand;
hand *straightFlushHand;
hand *royalFlushHand;

int cntsetsTest(int rc, hand *h, int sizetest, const char *passStr, const char *failStr);

int testHasPair();
int testHasTwoPair();
int testHasThreeKind();
int testHasStraight();
int testHasFlush();
int testHasFullHouse();
int testHasFourKindManual();
int testHasFourKindMemcpy();
int testHasStraightFlush();
int testRoyalFlush();

int testcntsets();


int main()
{
        junkHand = strToHand(junkStr);
        pairHand = strToHand(pairStr);
        twoPairHand = strToHand(twoPairStr);
        threeKindHand = strToHand(threeKindStr);
        straightHand = strToHand(straightStr);
        flushHand = strToHand(flushStr);
        fullHouseHand = strToHand(fullHouseStr);
        fourKindHand = strToHand(fourKindStr);
        straightFlushHand = strToHand(straightFlushStr);
        royalFlushHand = strToHand(straightFlushStr);

        printf(testBeginForFunctionStr, "testcntsets");

        int passed = testcntsets();


        return 0;
}

int testcntsets()
{
        const char * fnFailStr = "FAILED %s test on cntsets with setsize of %d\n";
        const char *fnPassStr = "PASSED %s test on cntsets with setsize of %d\n";

        int passedTests = 0;
        int numTests = 0;

        for(int i = 2; i < 5; i++)
        {
                numTests++;
                if( 0 == cntsets(junkHand, i))
                {
                        passedTests++;
                        printf(fnPassStr, "junk hand", i);
                }
                else
                {
                        printf(fnFailStr, "junk hand", i);
                }
        }
        numTests++;
        if(cntsets(pairHand, 2) == 1)
        {
                passedTests++;
                printf(fnPassStr, "pair hand", 2);
        }
        else
        {
                printf(fnFailStr, "pair hand", 2);
        }

        for(int i = 3; i < 5; i++)
        {
                numTests++;
                if(cntsets(pairHand, i) == 0)
                {
                        printf(fnPassStr, "pair hand", i);
                        passedTests++;
                }
                else
                {
                        printf(fnFailStr, "pair hand", i);
                }
        }

        numTests++;
        if(cntsets(twoPairHand, 2) == 2)
        {
                passedTests++;
                printf(fnPassStr, "two pair hand", 2);
        }
        else
        {
                printf(fnFailStr, "two Pair Hand", 2);
        }

        for(int i = 3; i < 5; i++)
        {
                numTests++;
                if(cntsets(twoPairHand, i) == 0)
                {
                        printf(fnPassStr, "two pair hand", i);
                        passedTests++;
                }
                else
                {
                        printf(fnFailStr, "two pair hand", i);
                }
        }

        numTests++;
        if(cntsets(threeKindHand, 2) == 2)
        {
                printf(fnPassStr, "two pair hand", 2);
                passedTests++;
        }
        else
        {
                printf(fnFailStr, "two pair hand", 2);
        }

        numTests++;
        if(cntsets(threeKindHand, 3) == 1)
        {
                printf(fnPassStr, "two pair hand", 3);
                passedTests++;
        }
        else
        {
                printf(fnFailStr, "two pair hand", 3);
        }

        numTests++;
        if(cntsets(threeKindHand, 4) == 0)
        {
                printf(fnPassStr, "two pair hand", 4);
                passedTests++;
        }
        else
        {
                printf(fnFailStr, "two pair hand", 4);
        }

        numTests++;
        if(cntsets(fullHouseHand, 2) == 3)
        {
                printf(fnPassStr, "two pair hand", 2);
                passedTests++;
        }
        else
        {
                printf(fnFailStr, "two pair hand", 2);
        }

        numTests++;
        passedTests += cntsetsTest(1,fullHouseHand,3,"PASSED cntsets with full house hand, setsize=3","FAILED cntsets with full house hand, setsize=3");


        printf(finishedSetStr, "cntsets()",passedTests, numTests);

        return passedTests;
}

int cntsetsTest(int rc, hand *testHand, int setsize, const char *passStr, const char *failStr)
{
        if(cntsets(testHand, setsize) == rc)
        {
                printf(passStr);
                return 1;
        }
        else printf(failStr);

        return 0;
}
