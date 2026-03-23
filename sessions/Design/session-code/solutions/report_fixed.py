"""
Storage Capacity Report Generator — FIXED VERSION

This file shows all three bugs fixed with annotations explaining
what was wrong and how the debugger would have revealed each one.

SOLUTION SUMMARY:
  Bug 1 (Line 33): range(len(nodes) - 1) → range(len(nodes))
  Bug 2 (Line 40): total // count → total / count
  Bug 3 (Line 49): check_threshold(count, 500) → check_threshold(total, 500)
"""


def get_storage_nodes():
    """Returns a list of storage nodes with capacity in TB."""
    return [
        {"name": "node-alpha",   "capacity_tb": 120},
        {"name": "node-beta",    "capacity_tb": 85},
        {"name": "node-gamma",   "capacity_tb": 200},
        {"name": "node-delta",   "capacity_tb": 150},
        {"name": "node-epsilon", "capacity_tb": 95},
    ]


def calculate_total(nodes):
    """Calculate total capacity across all nodes."""
    total = 0
    # FIX 1: range(len(nodes) - 1) missed the last node.
    #   Original: range(4) → indices 0,1,2,3 → skips index 4 (node-epsilon, 95 TB)
    #   Fixed:    range(5) → indices 0,1,2,3,4 → all nodes included
    #   Debugger: Set breakpoint on line 33. Watch 'total' after the loop.
    #             Original: total = 555 (missing 95). Fixed: total = 650.
    for i in range(len(nodes)):
        total += nodes[i]["capacity_tb"]
    return total


def calculate_average(total, count):
    """Calculate average capacity per node."""
    # FIX 2: Integer division (//) truncated the result.
    #   Original: 650 // 5 = 130 (happens to look correct with fixed total)
    #             But 555 // 5 = 111 (truncated from 111.0)
    #   Fixed:    650 / 5 = 130.0 (true division preserves decimals)
    #   Debugger: Set breakpoint on return. Watch 'average'.
    #             With original total (555): 555 // 5 = 111, 555 / 5 = 111.0
    #             The truncation matters when total is not evenly divisible.
    average = total / count
    return average


def check_threshold(capacity, threshold):
    """Return True if capacity exceeds the threshold."""
    return capacity > threshold


def generate_report():
    nodes = get_storage_nodes()
    total = calculate_total(nodes)
    count = len(nodes)
    average = calculate_average(total, count)

    # FIX 3: Passed 'count' (5) instead of 'total' (650) to threshold check.
    #   Original: check_threshold(5, 500) → 5 > 500 → False
    #   Fixed:    check_threshold(650, 500) → 650 > 500 → True
    #   Debugger: Set breakpoint on this line. Hover over the first argument.
    #             Original: shows 5. That is obviously wrong — it should be total.
    is_above_minimum = check_threshold(total, 500)

    print("=" * 45)
    print("  STORAGE CAPACITY REPORT")
    print("=" * 45)
    print(f"  Nodes scanned:      {count}")
    print(f"  Total capacity:     {total} TB")
    print(f"  Average per node:   {average} TB")
    print(f"  Above 500 TB min:   {'YES' if is_above_minimum else 'NO'}")
    print("=" * 45)


if __name__ == "__main__":
    generate_report()
