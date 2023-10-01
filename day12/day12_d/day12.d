import std.stdio;
import std.range;
import std.typecons;
import std.math;

bool[][] build_adj_mat(char[] data, int width) {
    bool[][] res;
    for (int i = 0; i < data.length; ++i) {
        bool[] row;
        for (int j = 0; j < data.length; ++j) {
            row ~= false;
        }
        res ~= row;
    }
    for (int j = 0; j < data.length; ++j) {
        for (int i = 0; i < data.length; ++i) {
            if ((abs(i - j) == 1) ||(abs(i - j) == width)) {
                if (cast(int)data[i] >= (cast(int) data[j]-1)) {
                    res[i][j] = true;
                }
            }    
        }
    }    
    return res;
}

char minElement(int[char] arr) {
    char lowest;
    bool iterated = false;
    foreach(key, val; arr) {
        if (!iterated) {
            lowest = key;
            iterated = true;
        }
        if (val < arr[lowest]) {
            lowest = key;
        }
    }
    return lowest;
}

char[] dijkstra(char[] map, bool[][]adj) {
    int[char] dist;
    char[char] prev;
    char[] Q;
    foreach(char c; map) {
        dist[c] = 1000000;
        prev[c] = '0';
        Q ~= c;
    }
    dist['S'] = 0;
    while (Q.length > 0) {
        char u = dist.minElement;
        remove!(a => a == u)(Q);
    }
    return ['A'];
}

void main() {
    string name;
    char[] map;
    int width = 0;
    do {
        name = readln();
        if (name.length == 0) break;
        width = cast(int)name.length - 1;
        foreach (char c; name[0..$-1]) {
            map ~= c;
        }
    } while(true);

    bool[][] adj = build_adj_mat(map, width);
    dijkstra(map, adj);
}
