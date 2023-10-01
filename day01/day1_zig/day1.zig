const std = @import("std");

const input = @embedFile("input.txt");

fn cmpByValue(context: void, a: u64, b: u64) bool {
    return std.sort.desc(u64)(context, a, b);
}

pub fn main() !void {
    var current_max: [3]u64 = [_]u64{ 0, 0, 0 };
    var current_sum: u64 = 0;
    var splits = std.mem.split(u8, input, "\n");
    while (splits.next()) |chunk| {
        if (chunk.len == 0) {
            if (current_sum > current_max[2]) {
                current_max[2] = current_sum;
                std.sort.sort(u64, current_max[0..], {}, cmpByValue);
            }
            current_sum = 0;
            continue;
        }
        var item = try std.fmt.parseInt(u64, chunk, 10);
        current_sum += item;
    }
    const total_sum = current_max[0] + current_max[1] + current_max[2];
    std.debug.print("{}\n", .{total_sum});
}
