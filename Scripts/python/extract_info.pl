# given json meta file, return latest version
#
# argument 1 : location of meta.json
# argument 2 : either "unset" or specified version
#
# output:
#   version (determined or passed through)
#   md5sum of version
#   tarball of version

use strict;
use warnings;
use JSON qw (decode_json);
use File::Slurp;

# use Data::Dumper;

my $meta_json_loc = $ARGV[0];
my $json_text = read_file($meta_json_loc);
my $meta_data = decode_json($json_text);
my $focus_version;
my $md5sum = "unset";
my $tarball = "unset";
my $homepage = "none";

my $info = $meta_data->{'info'};

if (defined $ARGV[1] && $ARGV[1] ne "unset") {
  $focus_version = $ARGV[1];
} else {
  if (exists $info->{'version'}) {
    $focus_version = $info->{'version'};
  } else {
    die ("no version found in json file");
  }
}

# print Dumper($meta_data->{'releases'}->{$focus_version}[1]);
# print Dumper($meta_data);

if (exists $info->{'home_page'}) {
  if ($info->{'home_page'} ne "") {
     $homepage = $info->{'home_page'};
  }
}

my @slice = @{$meta_data->{'releases'}->{$focus_version}};
my $rsize = scalar @slice;

for (my $x=0; $x < $rsize; $x++) {
   if ($slice[$x]->{'packagetype'} eq 'sdist') {
     if (exists $slice[$x]->{'md5_digest'}) {
       $md5sum = $slice[$x]->{'md5_digest'};
     }
     if (exists $slice[$x]->{'filename'}) {
       $tarball = $slice[$x]->{'filename'};
     }
     last;
   }
}

print $focus_version . " " . $md5sum . " " . $tarball . " " . $homepage . "\n";
