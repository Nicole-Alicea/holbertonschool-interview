#!/usr/bin/python3
"""
A script that reads log lines from stdin, tracks the file size and counts
the occurrences of specific HTTP status codes, 
then prints the file size and status code counts every 10 lines, or when
the program is interrupted.

The script monitors the following HTTP status codes:
    - 200: OK
    - 301: Moved Permanently
    - 400: Bad Request
    - 401: Unauthorized
    - 403: Forbidden
    - 404: Not Found
    - 405: Method Not Allowed
    - 500: Internal Server Error

If the program receives a KeyboardInterrupt (Ctrl+C), it prints the summary
of file size and status codes before exiting.
"""

import sys

def imp(fs, e0, e1, e2, e3, e4, e5, e6, e7):
    """
    Prints the file size and counts of each HTTP status code if they have
    been logged.
    
    Args:
        fs (int): The total file size accumulated from the logs.
        e0, e1, e2, e3, e4, e5, e6, e7 (int): Counters for different HTTP
        status codes.
            - e0: Count of 200 OK responses.
            - e1: Count of 301 Moved Permanently responses.
            - e2: Count of 400 Bad Request responses.
            - e3: Count of 401 Unauthorized responses.
            - e4: Count of 403 Forbidden responses.
            - e5: Count of 404 Not Found responses.
            - e6: Count of 405 Method Not Allowed responses.
            - e7: Count of 500 Internal Server Error responses.
    
    Returns:
        None
    """
    print("File size: {}".format(fs))
    if e0 > 0:
        print("200: {}".format(e0))
    if e1 > 0:
        print("301: {}".format(e1))
    if e2 > 0:
        print("400: {}".format(e2))
    if e3 > 0:
        print("401: {}".format(e3))
    if e4 > 0:
        print("403: {}".format(e4))
    if e5 > 0:
        print("404: {}".format(e5))
    if e6 > 0:
        print("405: {}".format(e6))
    if e7 > 0:
        print("500: {}".format(e7))

if __name__ == "__main__":
    """
    Main function that reads from stdin, parses log lines, and tracks the
    file size and HTTP status codes.

    Every 10 lines, or upon termination (KeyboardInterrupt), it prints a
    summary of the file size and status code counts.
    
    Variables:
        c (int): Counter for the number of lines processed.
        e0, e1, e2, e3, e4, e5, e6, e7 (int): Counters for each HTTP status
        code.
        fs (int): Accumulated file size from the log lines.
    """
    c = 0
    e0 = 0
    e1 = 0
    e2 = 0
    e3 = 0
    e4 = 0
    e5 = 0
    e6 = 0
    e7 = 0
    fs = 0

    try:
        line = sys.stdin.readline()
        while line:
            s = line.split()
            if len(s) > 6:  # Ensure the line has enough parts to contain a status code and file size
                if c == 10:
                    # Print file size and status code counts every 10 lines
                    imp(fs, e0, e1, e2, e3, e4, e5, e6, e7)
                    c = 0

                # Parse the status code and file size
                n = s[-2]  # Status code is the second last field
                if n == "200":
                    e0 += 1
                elif n == "301":
                    e1 += 1
                elif n == "400":
                    e2 += 1
                elif n == "401":
                    e3 += 1
                elif n == "403":
                    e4 += 1
                elif n == "404":
                    e5 += 1
                elif n == "405":
                    e6 += 1
                elif n == "500":
                    e7 += 1
                
                # Add the file size (last field) to the total
                fs += int(s[-1])

                # Read the next line and increment the counter
                line = sys.stdin.readline()
                c += 1

    except KeyboardInterrupt:
        # Print summary and exit gracefully if interrupted
        imp(fs, e0, e1, e2, e3, e4, e5, e6, e7)
        raise

    # Print final summary after reading all lines
    imp(fs, e0, e1, e2, e3, e4, e5, e6, e7)