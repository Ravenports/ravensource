"""
This script combines individual point release notes to avoid an every
changing package list.  Releases 1.5.0 to 1.8.5 use four part versions.

argument 1: STAGEDIR
argument 2: PREFIX
"""

import os
import sys

RNOTES = "share/doc/git/RelNotes"
STAGEDIR = "tbd"
PREFIX = "tbd"


def merge_point(major, minor, point):
    """ Handles 3 part tuples """
    subfile = f"{major}.{minor}.{point}.adoc"
    finfile = f"{major}.{str(minor).zfill(2)}.adoc"
    abs_subfile = f"{STAGEDIR}{PREFIX}/{RNOTES}/{subfile}"
    abs_finfile = f"{STAGEDIR}{PREFIX}/{RNOTES}/{finfile}"    
    if os.path.exists(abs_subfile):
        os.system(f"/bin/cat {abs_subfile} >> {abs_finfile}")
        os.remove(abs_subfile)
        print(f"Merge {subfile} => {finfile}")


def merge_subpoint(major, minor, point, subpoint):
    """ Handles 4 part tuples """
    subfile = f"{major}.{minor}.{point}.{subpoint}.adoc"
    finfile = f"{major}.{str(minor).zfill(2)}.adoc"
    abs_subfile = f"{STAGEDIR}{PREFIX}/{RNOTES}/{subfile}"
    abs_finfile = f"{STAGEDIR}{PREFIX}/{RNOTES}/{finfile}"    
    if os.path.exists(abs_subfile):
        os.system(f"/bin/cat {abs_subfile} >> {abs_finfile}")
        os.remove(abs_subfile)
        print(f"Merge {subfile} => {finfile}")

    
def release_v1():
    """ Handles versions 1.5 to 1.9 """
    for minor in range(5, 10):
        for point in range(13):
            merge_point(1, minor, point)
            for subpoint in range(1,10):
                merge_subpoint(1, minor, point, subpoint)  

def release_vx():
    """ Handles versions 2.0.0 to 4.99.15 """
    for major in range(2, 5):
        for minor in range(100):
            for point in range(16):
                merge_point(major, minor, point)

def main():
    """ Script entry point """
    release_v1()
    release_vx()

if __name__ == "__main__":
    STAGEDIR = sys.argv[1]
    PREFIX = sys.argv[2]
    main()
