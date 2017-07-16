# given json meta file, return summary (if it exists)
#
# argument 1 : location of meta.json

use strict;
use warnings;
use JSON qw (decode_json);
use File::Slurp;

my $meta_json_loc = $ARGV[0];
my $json_text = read_file($meta_json_loc);
my $meta_data = decode_json($json_text);

my $info = $meta_data->{'info'};
if (exists $info->{'summary'}) {
   print $info->{'summary'} . "\n";
}
