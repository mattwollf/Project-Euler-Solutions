import std.stdio;
import std.conv;
import std.range;
import std.algorithm;
import std.parallelism;
import core.sync.mutex;

long euclid_mod(long a, long b)  @nogc pure nothrow @trusted
{
    while(b != 0)
    {
        auto tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

real resilience(in long denominator)
{

    struct spaceRange {
        long curr = 2;
        @property auto empty(){return curr == denominator;}
        @property auto front(){ return curr;}
        auto popFront(){ curr++;}
    };

    auto mutex = new Mutex;

    auto space = spaceRange();
    real ds = 1;
    foreach(long i; taskPool.parallel(space, 2))
    {
        if(euclid_mod(denominator, i) == 1)
        {
                synchronized(mutex)
                {
                ds++;
                }
        }
    }

    return ds / (denominator - 1);
}

void main()
{

    struct numRange{
        immutable int increment = 30030;
        long curr = 29099070;
        int cnt = 0;
        @property auto front() { return curr; }
        @property bool empty() { return cnt == 10;}
        auto popFront() {cnt ++;curr += increment;}
    };

    auto nums = numRange();

    static immutable real goalRd = 15499.0 / 94744.0;

    real lowest_res = 2;
    real res;


    foreach(long denominator; nums)
    {
        res = resilience(denominator);

        if(res < lowest_res)
        {
            lowest_res = res;
        }

        writeln(res, " " ,denominator);
    }

}
