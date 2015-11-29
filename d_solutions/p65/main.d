import std.stdio;
import std.range;

void main()
{
	struct eFraction{

		long k;

		@property @safe @nothrow @nogc auto empty(){return false;}
		@property auto front(){return numerator / denominator;}

		auto popFront(){}
	};
}
