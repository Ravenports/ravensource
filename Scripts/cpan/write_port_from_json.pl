# given meta file from CPAN in json format, generate port source
#
# argument 1: port namebase
# argument 2: author string for fetching (e.g. T/TO/TODDR)
# argument 3: tarball associated with meta file
# argument 4: perl argument (configure, buildmod, buildmodtiny)
# argument 5: ravensource directory
#

use strict;
use warnings;
use JSON qw (decode_json);
use File::Slurp;
use Module::CoreList;
use Text::Wrap;

my $port_namebase = $ARGV[0];
my $port_author   = $ARGV[1];
my $tarball       = $ARGV[2];
my $buildmech     = $ARGV[3];
my $ravensource   = $ARGV[4];

my $json_text   = read_file('/tmp/cpan-work/meta.json');
my $dir_queue   = "/tmp/cpan-work/build-queue";
my $dir_done    = "/tmp/cpan-work/completed";
my $dir_fail    = "/tmp/cpan-work/failed-to-build";
my $meta_data   = decode_json($json_text);
my $portversion = $meta_data->{'version'};
my $shortdesc   = $meta_data->{'abstract'};
my $trunc_sdesc;
my $homepage    = "none";
my %perlver     = ("524" => 5.24, "522" => 5.22);
my @perlverkeys = ("524", "522");
my @variants    = ();
my %reqs = ();
my @reqs_cats   = ("build", "configure", "runtime", "test");
my @reqs_level  = ("requires", "recommends");
my $descriptions = "";
my $subpackages = "";
my $options_avail = "";
my $counter = 0;
my $inner_counter = 0;
my $dump_vopts = "";
my $dump_dependencies_as_comments = "";
my $dump_buildrun_options = "";
my $manual_portion = "";
my $depname = "";
my %bdep;
my %rdep;
my %bdependencies;
my %rdependencies;

sub make_comment{
   my $copystring = $shortdesc;
   $copystring =~ s/^A perl //;
   $trunc_sdesc = ucfirst substr($copystring, 0, 43);
}

make_comment;

foreach my $key (@perlverkeys) {
   if (!Module::CoreList::is_core ($port_namebase, undef, $perlver{$key})) { push @variants, $key; }
   $bdep{$key} = 0;
   $rdep{$key} = 0;
   $bdependencies{$key} = "[PERL_$key].BUILD_DEPENDS_ON=\t\t";
   $rdependencies{$key} = "[PERL_$key].BUILDRUN_DEPENDS_ON=\t\t";
}

my $VARIANT_LIST= join (" ", @variants);
foreach my $n (@variants) {
   $descriptions  .= "SDESC[$n]=\t\t$trunc_sdesc (v$n)\n";
   $subpackages   .= "SPKGS[$n]=\t\tsingle\n";
   $options_avail .= ($counter ? " " : "") . "PERL_$n";
   $dump_vopts    .= "VOPTS[$n]=\t\t";
   $inner_counter = 0;
   foreach my $z (@variants) {
      $dump_vopts .= ($inner_counter ? " " : "") . "PERL_$z=" . ("$n" eq "$z" ? "ON" : "OFF");
      $inner_counter++;
   }
   $dump_vopts .= "\n";
   $dump_buildrun_options .= "[PERL_$n].USES_ON=\t\t\tperl:$n,$buildmech\n";
   $counter++;
}

if (exists $meta_data->{'homepage'}) {
   $homepage = $meta_data->{'homepage'}
} elsif (exists $meta_data->{'resources'}{'repository'}{'web'}) {
   $homepage = $meta_data->{'resources'}{'repository'}{'web'}
} elsif (exists $meta_data->{'resources'}{'repository'}{'url'}) {
   $homepage = $meta_data->{'resources'}{'repository'}{'url'}
}

if (exists $meta_data->{'prereqs'}) {
   $dump_dependencies_as_comments .= "# -----------------------------------------------\n";
   $dump_dependencies_as_comments .= "# |   Prerequisites extracted from META.json\n";
   $dump_dependencies_as_comments .= "# -----------------------------------------------\n";
   foreach my $cat (@reqs_cats) {
      foreach my $level (@reqs_level) {
         if (exists $meta_data->{'prereqs'}{$cat}{$level}) {
            %reqs = %{ $meta_data->{'prereqs'}{$cat}{$level} };
            my $suff = "";
            foreach my $key (keys %reqs) {
               next if ($key eq "perl");
               foreach my $perlkey (@perlverkeys) {
                  if (Module::CoreList::is_core ($key, undef, $perlver{$perlkey})) {
                     $suff .= " (perl $perlver{$perlkey} core)";
                  } else {
                     $depname = "perl-" . $key;
                     $depname =~ s/::/-/g;
                     if (($cat eq "configure") || ($cat eq "build")) {
                        if ($bdep{$perlkey} == 0) {
                           $bdependencies{$perlkey} .= "$depname:single:$perlkey\n";
                        } else {
                           $bdependencies{$perlkey} .= "\t\t\t\t\t$depname:single:$perlkey\n";
                        }
                        $bdep{$perlkey}++;
                     }
                     if ($cat eq "runtime") {
                        if ($rdep{$perlkey} == 0) {
                           $rdependencies{$perlkey} .= "$depname:single:$perlkey\n";
                        } else {
                           $rdependencies{$perlkey} .= "\t\t\t\t\t$depname:single:$perlkey\n";
                        }
                        $rdep{$perlkey}++;
                     }
                     if (! -f "${dir_done}/${key}") {
                        if (! -f "${dir_queue}/${key}") {
                           if (! -f "${dir_fail}/${key}") {
                              open HANDLE, ">>${dir_queue}/${key}";
                              close HANDLE;
                           }
                        }
                     }
                  }
               }
               $dump_dependencies_as_comments .= sprintf ("# | %12s : $key$suff\n", $cat);
            }
         }
      }
   }
   foreach my $key (@perlverkeys) {
      if ($bdep{$key} > 0) { $dump_buildrun_options .= $bdependencies{$key} }
      if ($rdep{$key} > 0) { $dump_buildrun_options .= $rdependencies{$key} }
   }
} else {
  $dump_dependencies_as_comments = "# This perl port has no dependencies at all.\n";
}

if (-f "${ravensource}/specification.manual") {
  $manual_portion = read_file ("${ravensource}/specification.manual");
}

open(FOUT, ">" , "${ravensource}/specification");
print FOUT <<EOF;
DEF[PORTVERSION]=	$portversion
# ------------------------------------------------------------------------

NAMEBASE=		$port_namebase
VERSION=		\${PORTVERSION}
KEYWORDS=		perl
VARIANTS=		$VARIANT_LIST
$descriptions
HOMEPAGE=		$homepage
CONTACT=		Perl_Automaton[perl\@ironwolf.systems]

DOWNLOAD_GROUPS=	main
SITES[main]=		CPAN/ID:$port_author
DISTFILE[1]=		$tarball:main

$subpackages
OPTIONS_AVAILABLE=	$options_avail
OPTIONS_STANDARD=	none
$dump_vopts
GENERATED=		yes

$dump_dependencies_as_comments
$dump_buildrun_options
$manual_portion
EOF

close(FOUT);

$Text::Wrap::columns = 75;
open(FOUT, ">" , "${ravensource}/descriptions/desc.single");
print FOUT wrap ("", "", $shortdesc . "\n");
close(FOUT);
