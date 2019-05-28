# given no meta file, generate port source
#
# argument 1: port namebase
# argument 2: author string for fetching (e.g. T/TO/TODDR)
# argument 3: tarball associated with meta file
# argument 4: perl argument (configure, buildmod, buildmodtiny)
# argument 5: ravensource directory
# argument 6: summary override (normally blank)
# argument 7: description override (normally blank)
#

use strict;
use warnings;
use File::Slurp;
use Module::CoreList;
use Text::Wrap;

my $port_namebase = $ARGV[0];
my $port_author   = $ARGV[1];
my $tarball       = $ARGV[2];
my $buildmech     = $ARGV[3];
my $ravensource   = $ARGV[4];
my $sum_override  = $ARGV[5];
my $des_override  = $ARGV[6];


my $dir_queue   = "/tmp/cpan-work/build-queue";
my $dir_done    = "/tmp/cpan-work/completed";
my $dir_fail    = "/tmp/cpan-work/failed-to-build";
my $shortdesc   = ($sum_override eq "") ? "No description provided." : $sum_override;
my $longdesc	= ($des_override eq "") ? $shortdesc : $des_override;
my $trunc_sdesc = $shortdesc;
my $distname;
my $portversion;
my $homepage    = "none";
my %perlver     = ("530" => 5.30, "528" => 5.28);
my @perlverkeys = ();	# add versions below
my @variants    = ();
my %reqs = ();
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

my %cache_portname;

if (! -f "${ravensource}/broken_530") { push @perlverkeys, "530" }
if (! -f "${ravensource}/broken_528") { push @perlverkeys, "528" }

sub make_distname {
   $distname = $port_namebase . "-" . $portversion;
   $distname =~ s/^perl-//;
}

sub set_portversion_from_tarball {
   my @parts     = split(/\//, $tarball);
   my @subparts  = split(/-/, $parts[(scalar @parts) - 1]);
   my @interdots = split(/\./, $subparts[(scalar @subparts) - 1]);
   my $caboose = (scalar @interdots) - 1;
   if ($interdots[$caboose - 1] eq "tar") { $caboose--; }
   $portversion = $interdots[0];
   for (my $x = 1; $x < $caboose; $x++) {
      $portversion .= "." . $interdots[$x];
   }
}

set_portversion_from_tarball;
make_distname;

foreach my $key (@perlverkeys) {
   if (!Module::CoreList::is_core ($port_namebase, undef, $perlver{$key})) { push @variants, $key; }
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

$dump_dependencies_as_comments .= "# No meta files available, therefore no dependencies defined.\n";

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
SINGLE_JOB=		yes
DISTNAME=		$distname

$dump_dependencies_as_comments
$dump_buildrun_options
$manual_portion
EOF

close(FOUT);

$Text::Wrap::columns = 75;
open(FOUT, ">" , "${ravensource}/descriptions/desc.single");
print FOUT wrap ("", "", $longdesc . "\n");
close(FOUT);
