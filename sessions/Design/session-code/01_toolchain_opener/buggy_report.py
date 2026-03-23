"""
Calsoft Engineering Internship 2026
Session: Software Design Principles and Engineering Workflow


PURPOSE:
  This program generates a simple storage capacity report.
  It reads a list of storage nodes, calculates total and average
  capacity, and prints a summary.

  It runs without syntax errors. It produces output.
  The output is WRONG.

  There are THREE bugs hidden in this code.
  Interns must find all three using only the debugger.
  No print statements allowed.

BUGS:
  Bug 1 (Logic error)    — line 46: off-by-one in loop range
  Bug 2 (Wrong operator)  — line 54: integer division truncates result
  Bug 3 (Incorrect call)  — line 63: wrong variable passed to threshold check

TRAINER NOTES:
  - Do NOT show this header to interns. Copy buggy_report_intern.py instead.
  - After the exercise, reveal this file to show where the bugs were.
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
    # BUG 1: range stops one short — misses the last node
    for i in range(len(nodes) - 1):
        total += nodes[i]["capacity_tb"]
    return total


def calculate_average(total, count):
    """Calculate average capacity per node."""
    # BUG 2: integer division (//) truncates decimal — should be /
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

    # BUG 3: passes 'count' to threshold check instead of 'total'
    is_above_minimum = check_threshold(count, 500)

    print("=" * 45)
    print("  STORAGE CAPACITY REPORT")
    print("=" * 45)
    print(f"  Nodes scanned:      {count}")
    print(f"  Total capacity:     {total} TB")
    print(f"  Average per node:   {average} TB")
    print(f"  Above 500 TB min:   {'YES' if is_above_minimum else 'NO'}")
    print("=" * 45)

    # Expected output:
    #   Nodes scanned:      5
    #   Total capacity:     650 TB    <-- Bug 1 makes this 555
    #   Average per node:   130.0 TB  <-- Bug 2 makes this 111 (truncated from 555)
    #   Above 500 TB min:   YES       <-- Bug 3 makes this NO (checks 5 > 500)


if __name__ == "__main__":
    generate_report()
