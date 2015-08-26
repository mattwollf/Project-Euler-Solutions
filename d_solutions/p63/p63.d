import std.string;
import std.conv;
import std.stdio;
import std.math;

void main()
{
        int matches = 0;

        for(int i = 0; i < 10; i++)
        {
                for(int j = 1; j <= 5000000; j++)
                {
                        if(pred!int(i, j))
                        {
                                matches++;
                        }
                        else if(floor(to!float(pow(i,j))) > j)
                                break;
                }
                writeln(to!string(i) ~ " done");
        }
        writeln(matches);
}

template pred(T)
{
        bool pred(T n, ulong g)
        {
                return to!string(pow(n,g)).length == g;
        }
}
