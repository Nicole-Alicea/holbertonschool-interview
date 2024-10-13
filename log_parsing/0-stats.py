#!/usr/bin/python3
"""
A script that reads from stdin line by line, computes metrics, and prints
the statistics every 10 lines or on keyboard interruption (Ctrl + C).

The input format expected is:
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>

Metrics tracked:
- Total file size (sum of all valid file sizes from the input).
- Number of occurrences of specific status codes: 200, 301, 400, 401, 403, 404,
405, 500.
"""

import sys

# Dictionary to store the count of each status code
status_code_counts = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}

total_file_size = 0
line_count = 0

def print_stats():
    """Function to print the accumulated statistics."""
    global total_file_size, status_code_counts
    print(f"File size: {total_file_size}")
    for code in sorted(status_code_counts.keys()):
        if status_code_counts[code] > 0:
            print(f"{code}: {status_code_counts[code]}")

if __name__ == "__main__":
    try:
        for line in sys.stdin:
            try:
                # Split the line by spaces
                parts = line.split()

                # Ensure the line has the correct number of parts for IP, status code, and file size
                if len(parts) < 9:
                    continue

                # Extract the status code and file size
                status_code = parts[-2]
                file_size = parts[-1]

                # Convert file size to integer and accumulate
                total_file_size += int(file_size)

                # Update the count for the status code, if it's a tracked one
                if status_code in status_code_counts:
                    status_code_counts[status_code] += 1

                # Increment the line count
                line_count += 1

                # After every 10 lines, print the statistics
                if line_count % 10 == 0:
                    print_stats()

            except Exception:
                # If an exception occurs, skip the line
                continue

    except KeyboardInterrupt:
        # On keyboard interrupt (Ctrl + C), print the statistics
        print_stats()
        raise

    # Print final statistics after all input has been processed
    print_stats()
