import std.stdio;
import std.conv;
import std.math;
import std.functional;
import std.array;
import std.range;
import std.random;
import std.algorithm;

bool isEven(long a)  nothrow pure @nogc @trusted
{
    return (a & 1) == 0;
}

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

real resilience(in long denominator) @safe pure @nogc
{
    real ds = 1;
    foreach(long i; 2..denominator)
    {
        if(euclid_mod(denominator, i) == 1)
        {
            ds ++;
        }
    }

    return ds / (denominator - 1);
}

void main()
{
    static immutable real goalRd = 15499.0 / 94744.0;
    immutable int denominator_increment = 30030;
    long denominator = 9699690;

    real lowest_res = 2;
    real res;

    do
    {
        res = resilience(denominator);

        if(res < lowest_res)
        {
            lowest_res = res;
            writeln(res, " " ,denominator);
        }

        denominator += denominator_increment;

    } while(res > goalRd);

    writeln(res);
}
