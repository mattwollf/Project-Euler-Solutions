import std.stdio;
import std.range;
import std.math;

real fx(in ulong x) pure nothrow @safe @nogc
{
        immutable real magic = 30.403243784;

        real power = magic - x * x;

        return floor(pow(2,power)) * pow(10,-9);
}

