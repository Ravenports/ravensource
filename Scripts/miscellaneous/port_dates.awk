# process git output to determine when port was added (first modification)
# and when port was last modified
#
# command: git log --format="format:%ct" --name-only
#
# The output is in reverse chronical order, so repeating port
# entries are ignored for latest modification.  However, for
# the "added" data, the last entry replaces previous ones.
#
# expected format of input:
# 1. unix timestamp
# 2. "n" number of filenames
# 3. blank link *if* another block of same-date entries exist
#
# output:
# namebase timestamp-added timestamp-lastmodified
# (1 per port, no blank lines, timestamps in unix format)
#
# example of invocation:
# awk -f miscellaneous/port_modified.awk /tmp/four | sort

BEGIN {
   accept = 1;
   unixtime = 0;
}
{
   if (NF) {
      if (accept) {
         unixtime = $1;
         accept = 0;
      } else {
         if (substr($1, 1, 7) == "bucket_") {
            split ($1, comp, "/");
            porta[comp[2]] = unixtime;
            if (!(comp[2] in portm)) {
               portm[comp[2]] = unixtime;
            }
         }
      }
   } else {
      accept = 1;
   }  
}
END {
   for (key in portm) {
      print key " " porta[key] " " portm[key];
   }
}
