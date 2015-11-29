import std.stdio;
import std.range.primitives;



struct mything
{
        char[10] ar;
        uint index = 0;

         @property bool empty()
        {
                return index == 9;
        }

         @property auto front()
        {
                return ar[index];
        }

        auto popFront()
        {
                return ar[index++];
        }
}

void main()
{
        mything r;

        r.ar
}
