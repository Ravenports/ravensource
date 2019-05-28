# given meta file from CPAN in json format, generate port source
#
# argument 1: port namebase
# argument 2: author string for fetching (e.g. T/TO/TODDR)
# argument 3: tarball associated with meta file
# argument 4: perl argument (configure, buildmod, buildmodtiny)
# argument 5: ravensource directory
# argument 6: location of meta.json
# argument 7: "ok" or "dead" (if not "ok", ignore homepage setting)
# argument 8: "ok" or "rmv" (if not "ok", remove "v" from distversion)
# argument 9: summary override (normally blank)
# argument 10: description override (normally blank)
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
my $meta_json_loc = $ARGV[5];
my $use_homepage  = $ARGV[6];
my $use_distver   = $ARGV[7];
my $sum_override  = $ARGV[8];
my $des_override  = $ARGV[9];

my $json_text   = read_file($meta_json_loc);
my $dir_queue   = "/tmp/cpan-work/build-queue";
my $dir_done    = "/tmp/cpan-work/completed";
my $dir_fail    = "/tmp/cpan-work/failed-to-build";
my $meta_data   = decode_json($json_text);
my $portversion = $meta_data->{'version'};
my $shortdesc   = ($sum_override eq "") ? $meta_data->{'abstract'} : $sum_override;
my $longdesc    = ($des_override eq "") ? $meta_data->{'abstract'} : $des_override;
my $distversion = $portversion;
my $trunc_sdesc;
my $distname;
my $homepage    = "none";
my %perlver     = ("530" => 5.30, "528" => 5.28);
my @perlverkeys = ();   # add versions below
my @variants    = ();
my %reqs = ();
my @reqs_cats   = ("runtime", "build", "configure", "test");
my @reqs_level  = ("requires");	# add recommends below
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
my %bdepcontainer;
my %rdepcontainer;
my $pinged = 0;

my %cache_portname;

if (! -f "${ravensource}/block_meta_recommends") { push @reqs_level, "recommends" }
if (! -f "${ravensource}/broken_530") { push @perlverkeys, "530" }
if (! -f "${ravensource}/broken_528") { push @perlverkeys, "528" }

# given a perl module name, return the equivalent port namebase
# requires: perl module index already in place

sub get_namebase {
   my $modname = shift;
   my $modlen = (length $modname) + 1;
   my $searchfor = $modname . " ";
   my @parts;
   my @subparts;
   my $assembled = "perl";
   my $num_subparts = 0;
   if (exists $cache_portname{$modname}) {
      return $cache_portname{$modname};
   }

   open my $handle, "/tmp/cpan-work/02packages.details.txt" or die "missing CPAN index";
   while (my $line = <$handle>) {
      if (substr($line, 0, $modlen) eq $searchfor) {
         @parts = split(/\//, $line);
         @subparts = split(/-/, $parts[(scalar @parts) - 1]);
         $num_subparts = scalar @subparts;
         for (my $x=0; $x < $num_subparts - 1; $x++) {
            $assembled .= "-" . $subparts[$x];
         }
         $cache_portname{$modname} = $assembled;
         return $assembled;
      }
   }
}

sub make_comment {
   my $copystring = $shortdesc;
   $copystring =~ s/^A perl //;
   $copystring =~ s/^A //;
   $copystring =~ s/^An //;
   $copystring =~ s/^a //;
   $copystring =~ s/^an //;
   $copystring =~ s/^The //;
   $trunc_sdesc = ucfirst substr($copystring, 0, 43);
}

sub make_distname {
   $distname = $port_namebase . "-" . $distversion;
   $distname =~ s/^perl-//;
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

if ("$use_homepage" eq "ok") {
  if (exists $meta_data->{'homepage'}) {
     $homepage = $meta_data->{'homepage'}
  } elsif ((exists $meta_data->{'resources'}{'repository'}{'web'}) &&
    ($meta_data->{'resources'}{'repository'}{'web'} =~ /^http/)) {
     $homepage = $meta_data->{'resources'}{'repository'}{'web'}
  } elsif ((exists $meta_data->{'resources'}{'repository'}{'url'}) &&
    ($meta_data->{'resources'}{'repository'}{'url'} =~ /^http/)) {
     $homepage = $meta_data->{'resources'}{'repository'}{'url'}
  }
}

$homepage =~ s/http:\/\/github.com/https:\/\/github.com/;
$homepage =~ s/http:\/\/bitbucket.org/https:\/\/bitbucket.org/;
$homepage =~ s/http:\/\/svn.ali.as\/.*/none/;

if (substr($portversion, 0, 1) eq "v") {
      print "Note:     stripping leading 'v' from version: $portversion\n";
      $portversion = substr($portversion, 1);
}

# Deal with major screwup on Class-Multimethods
if ("$port_namebase" eq "perl-Class-Multimethods" && "$portversion" eq "1.700") {
   $portversion = "1.701";
}

if ("$use_distver" eq "rmv") {
   $distversion = substr($distversion, 1);
}

make_distname;

if (exists $meta_data->{'prereqs'}) {
   $dump_dependencies_as_comments .= "# -----------------------------------------------\n";
   $dump_dependencies_as_comments .= "# |   Prerequisites extracted from META.json\n";
   $dump_dependencies_as_comments .= "# -----------------------------------------------\n";
   foreach my $cat (@reqs_cats) {
      foreach my $level (@reqs_level) {
         if (exists $meta_data->{'prereqs'}{$cat}{$level}) {
            %reqs = %{ $meta_data->{'prereqs'}{$cat}{$level} };
            foreach my $key (sort keys %reqs) {
               next if ($key eq "perl");
               my $suff = "";
               foreach my $perlkey (@perlverkeys) {
                  if (Module::CoreList::is_core ($key, undef, $perlver{$perlkey})) {
                     $suff .= " (perl $perlver{$perlkey} core)";
                  } else {
                     $pinged = 0;
                     $depname = get_namebase ($key);
                     if ($depname eq $port_namebase) { next; }  # can't depend on yourself
                     if (-f "${ravensource}/IGNORE_$key") { next; } # bad requirement
                     if ($cat eq "runtime") {
                        if (!exists ($rdepcontainer{$perlkey}{$depname})) {                           
                           if ($rdep{$perlkey} == 0) {
                              $rdependencies{$perlkey} .= "$depname:single:$perlkey\n";
                           } else {
                              $rdependencies{$perlkey} .= "\t\t\t\t\t$depname:single:$perlkey\n";
                           }
                           $rdep{$perlkey}++;
                           $rdepcontainer{$perlkey}{$depname} = 1;
                           $pinged = 1;
                        }
                     }
                     if (($cat eq "configure") || ($cat eq "build")) {
                        if (!exists ($bdepcontainer{$perlkey}{$depname}) &&
                            !exists ($rdepcontainer{$perlkey}{$depname}))
                        {
                           if ($bdep{$perlkey} == 0) {
                              $bdependencies{$perlkey} .= "$depname:single:$perlkey\n";
                           } else {
                              $bdependencies{$perlkey} .= "\t\t\t\t\t$depname:single:$perlkey\n";
                           }
                           $bdep{$perlkey}++;
                           $bdepcontainer{$perlkey}{$depname} = 1;
                           $pinged = 1;
                        }
                     }
                     if ($pinged) {
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
