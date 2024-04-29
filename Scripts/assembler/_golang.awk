# first file is mod-generated graph, second file is template
# Skip "## explicit" lines
# Skip lines that do not start with "#"

FNR==NR {
  if ($0 == "## explicit") { next }
  if (length($0) == 0) { next }
  if (substr($0, 1, 1) != "#") { next }

  # split graph line to first 3 components
  # example: # github.com/alexbrainman/sspi v0.0.0-20210105120005-909beea2cc74
  # example: # github.com/davecgh/go-spew v1.1.1
  split($0, dep, " ")
  tag = dep[3]
  if (index(tag, "-")) {
    p = split (tag, parts, "-")
    if (p > 1) {
      len3 = length(parts[p])
      if (len3 == 12) {
        # git hash is 12 chars
        tag = parts[p]
      }
    }
  }
  # remove "+incompatible" from the end of tags
  original_tag = tag
  badtag = "+incompatible"
  lenbt = length(badtag)
  lent = length(tag)
  if ((lent > lenbt) && (substr(tag, lent - lenbt + 1, lenbt) == badtag)) {
     tag = substr(tag, 1, lent - lenbt)
  }

  # Determine org, project and install location
  q = split (dep[2], mylist, "/")
  domain = mylist[1]  

  # gopkg.in/a.vx mirrored at github.com/go-a/a/vx
  if (domain == "gopkg.in") {
     domain = "github.com"
     split(mylist[2], orgpart,".")
     org = "go-" orgpart[1]
     project = orgpart[1]
     reloc = "vendor/gopkg.in/" mylist[2]
  } else {
    # sanity check.  There has to be at least 2 slashes (except for gopkg.in)
    if (q < 3) { next }

    org = mylist[2]
    project = mylist[3]
    # These ords already have the V's embedded, use short locs
    if (org == "jcmturner") {
      reloc = "vendor/" domain "/" org "/" project
    } else {
      reloc = "vendor/" dep[2]
    }
  }


  # golang.org/x/ is mirrored at github.com/golang/
  if ((domain == "golang.org") && (org == "x")) {
     domain = "github.com"
     org = "golang"
  }


  # Store crates
  ll++  
  url[ll""] = org ":" project ":" tag ":" reloc
  loc[location] = 1
  next
}

function tabs(txt) {
   if (length(txt) < 7)
      return "\t\t"
   else
      return "\t"
}

function DOWNLOAD_GROUPS() {
   workline = "DOWNLOAD_GROUPS=\tmain"
   maxcr = 9;
   if (ll < maxcr)
      maxcr = ll
   for (j = 1; j <= maxcr; j++)
      workline = workline " cr0" j
   print workline
   if (ll > 9) {
      cur = 10
      do {
         workline = "\t\t\t"
         maxcr = cur + 9
         if (ll < maxcr)
            maxcr = ll
         for (j = cur; j <= maxcr; j++) {
            if (j == cur)
               workline = workline "cr" j
            else
               workline = workline " cr" j
         }
         print workline
         cur = cur + 10
      }
      while (maxcr < ll)
   }
}

function DF_INDEX() {
   workline= "DF_INDEX=\t\t"
   maxcr = 10
   dfiles = ll + 1
   if (dfiles < maxcr)
      maxcr = dfiles
   for (j = 1; j <= maxcr; j++) {
      if (j > 1)
         workline = workline " "
      workline = workline j
   }
   print workline
   if (dfiles > 10) {
      cur = 11
      do {
         workline = "\t\t\t"
         maxcr = cur + 9
         if (dfiles < maxcr)
            maxcr = dfiles
         for (j = cur; j <= maxcr; j++) {
            if (j > cur)
               workline = workline " "
            workline = workline j
         }
         print workline
         cur = cur + 10
      }
      while (maxcr < dfiles)
   }
}

function crid (id) {
   if (id < 10)
      return "cr0" id
   else
      return "cr" id
}

function CR_SITES () {
   for (j=1; j <= ll; j++) {
      print "SITES[" crid(j) "]=\t\tGITHUB/" url[j""]
   }
}

function CR_DISTFILES() {
   for (j=1; j <= ll; j++) {
      print "DISTFILE[" (j+1) "]=\t\tgenerated:" crid(j)
   }
   print "DIST_SUBDIR=\t\tgolang/" namebase
}

{
   # process template (file 2)
   if ($0 == "%%DOWNLOAD_GROUPS%%")
      DOWNLOAD_GROUPS()
   else if ($0 == "%%CR_SITES%%")
      CR_SITES()
   else if ($0 == "%%CR_DISTFILES%%")
      CR_DISTFILES()
   else if ($0 == "%%DF_INDEX%%")
      DF_INDEX()
   else
      print $0
}
