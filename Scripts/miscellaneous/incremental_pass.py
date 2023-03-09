#!/raven/bin/python3
"""
This script produces a list of ports that failed or were skipped during the
previous run of ravenadm.  It excludes ports that were skipped because the
causing port was ignored.

In order to do this it needs to scan 2 log files:
02_failure_list.log
04_skipped_list.log
"""

import sys
import subprocess


def get_logs_directory():
    """
    Executes ravenadm to determine the log directory of the currently selected profile
    """
    cmd = ["/raven/bin/ravenadm", "dev", "info", "G"]
    output = subprocess.check_output(cmd, universal_newlines=True)
    return output.strip() + "/logs/logs"


def scan_failed_build_log(logs_directory):
    """
    Read 02_failure_list.log line by line, extract the port name and append
    the FAILED_BUILD list with the value.

    sample line:
    02:37:40 alsa-lib:standard (skipped 1)
    """
    result = []
    filename = logs_directory + "/02_failure_list.log"
    with open(filename, "r", encoding="utf-8") as fin:
        for line in fin:
            lean_line = line.strip()
            if " " in lean_line:
                elements = lean_line.split(" ")
                result.append(elements[1])
    return result


def scan_skipped_ports_log(logs_directory):
    """
    Read 04_skipped_list.log line by line, and return a dictionary.
    The keys will be the failed port the caused the skip, and the
    values will be lists of the ports skipped by the failure

    sample line:
    R-rcmdcheck:standard by R-ps:standard
    """
    result = {}
    filename = logs_directory + "/04_skipped_list.log"
    with open(filename, "r", encoding="utf-8") as fin:
        for line in fin:
            lean_line = line.strip()
            if " " in lean_line:
                elements = lean_line.split(" ")
                failed = elements[2]
                skipped = elements[0]
                if failed not in result:
                    result[failed] = []
                result[failed].append(skipped)
    return result


def print_increment_list(failed_ports, skipped_ports):
    """
    Produce a list sent to standard output that contains all the
    elments of the failed ports, and a subset of the elements of the
    skipped ports: the ones skipped due to build failure.
    """
    for failure in failed_ports:
        print(failure)
        if failure in skipped_ports:
            for skipped in skipped_ports[failure]:
                print(skipped)


def main():
    """
    Script entry point
    """
    logs_directory = get_logs_directory()
    failed_ports = scan_failed_build_log(logs_directory)
    skipped_ports = scan_skipped_ports_log(logs_directory)
    print_increment_list(failed_ports, skipped_ports)
    return 0


if __name__ == "__main__":
    sys.exit(main())
