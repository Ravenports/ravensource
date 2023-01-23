# first file is mod-generated graph, second file is template

FNR==NR {
  # split graph line to first 2 components
  split($0,item," ")

  # Check first component to see if is on the forbidden list
  # If it is, skip.
  if (item[1] in forbidden) { next }

  # split module into 2 components on "@" delimiter
  # When second part in form "XXX-20210315154721-298b63a54430", it
  # represents a commit hash (298b63a54430).  Otherwise it's
  # a tag (e.g. "v3.0.1")
  # Note: I've seen a case where first hyphen was a dot, so only check last part
  split(item[2], dep, "@")
  tag = dep[2]
  if (index(dep[2], "-")) {
     p=split(dep[2],parts,"-")
     if (p > 1) {
        len3 = length(parts[p])
        if (len3 == 12) {
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

  # Determine org, project, and install location
  # Example: github.com/git-lfs/wildmatch/v2@v2.0.1
  #      org = git-lfs
  #  project = wildmatch
  # location = vendor/github.com/git-lfs/wildmatch/v2 (drop v2 on final)
  q=split(dep[1],mylist,"/")
  
  # sanity check
  if (q < 3) { next }

  domain = mylist[1]  
  org = mylist[2]
  project = mylist[3]
  location = "vendor/" dep[1]

  # These orgs already have the V's embedded, use short locs
  if (org == "jcmturner") {
     reloc = "vendor/" domain "/" org "/" project
  } else {
     reloc = location
  }

  # Check if we've seen this location before.
  # If so, put it on the forbidden list and skip.
  if (location in loc) {
     forbidden[item[2]] = 1
     next
  }

  # golang.org/x/ is mirrored at github.com/golang/
  if ((domain == "golang.org") && (org == "x")) {
     domain = "github.com"
     org = "golang"
  }

  # gopkg.in/a.vx mirrored at github.com/go-a/a/vx
  if (domain == "gopkg.in") {
     domain = "github.com"
     split(org,orgpart,".")
     org = "go-" orgpart[1]
     project = orgpart[1]
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
