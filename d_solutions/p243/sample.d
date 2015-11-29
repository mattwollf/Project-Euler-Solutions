import std.parallelism;
import std.stdio;
import std.range;

void main()
{
    struct numRange {

        int curr = 0;

        @property auto front(){ return curr;}
        @property auto empty(){ return curr == 20;}

        auto popFront(){curr++;}

    };

    numRange r;

    foreach(int i; taskPool.parallel(r))
    {
        writeln(i);
    }
}
