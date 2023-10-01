void main() {
    import std.stdio, std.algorithm;

    double[char] bids = ['A': 37.50,
                         'B': 38.11,
                         'C': 36.12];

    bids.byValue.reduce!(min, max).writeln;
    auto highest = reduce!((a,b) => max(a,b))(-double.max, bids.byValue());
	auto lowest = reduce!((a,b) => min(a,b))(double.max, bids.byValue());
    highest.writeln;
    lowest.writeln;
}
