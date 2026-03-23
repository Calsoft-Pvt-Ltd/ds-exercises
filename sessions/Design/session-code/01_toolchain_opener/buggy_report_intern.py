"""
Storage Capacity Report Generator

This program reads storage node data, calculates total and average
capacity, and prints a summary report.

TASK:
  The program runs without errors but the output is wrong.
  Use the debugger to find and fix all the bugs.
  Document each bug: what it was, how you found it, and the fix.

  RULE: No print statements. Debugger only.
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
    for i in range(len(nodes) - 1):
        total += nodes[i]["capacity_tb"]
    return total


def calculate_average(total, count):
    """Calculate average capacity per node."""
    average = total // count
    return average


def check_threshold(capacity, threshold):
    """Return True if capacity exceeds the threshold."""
    return capacity > threshold


def generate_report():
    nodes = get_storage_nodes()
    total = calculate_total(nodes)
    count = len(nodes)
    average = calculate_average(total, count)
    is_above_minimum = check_threshold(count, 500)

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
