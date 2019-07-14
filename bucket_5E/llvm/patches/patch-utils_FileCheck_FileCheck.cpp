From 32af43a9664894b4bf4246b44b0b1043fbe706ee Mon Sep 17 00:00:00 2001
From: Rainer Orth <ro@gcc.gnu.org>
Date: Tue, 2 Apr 2019 18:38:23 +0000
Subject: [PATCH] [FileCheck] Fix FileCheck.cpp compilation on Solaris
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit

Both LLVM 8.0.0 and current trunk fail to compile on Solaris with GCC 8.1.0:

  /vol/llvm/src/llvm/dist/utils/FileCheck/FileCheck.cpp: In function ‘void DumpAnnotatedInput(llvm::raw_ostream&, const llvm::FileCheckRequest&, llvm::StringRef, std::vector<InputAnnotation>&, unsigned int)’:
  /vol/llvm/src/llvm/dist/utils/FileCheck/FileCheck.cpp:408:41: error: call of overloaded ‘log10(unsigned int&)’ is ambiguous
     unsigned LineNoWidth = log10(LineCount) + 1;
                                           ^
  In file included from /vol/gcc-8/lib/gcc/i386-pc-solaris2.11/8.1.0/include-fixed/math.h:24,
                   from /vol/gcc-8/include/c++/8.1.0/cmath:45,
                   from /vol/llvm/src/llvm/dist/include/llvm-c/DataTypes.h:28,
                   from /vol/llvm/src/llvm/dist/include/llvm/Support/DataTypes.h:16,
                   from /vol/llvm/src/llvm/dist/include/llvm/ADT/Hashing.h:47,
                   from /vol/llvm/src/llvm/dist/include/llvm/ADT/ArrayRef.h:12,
                   from /vol/llvm/src/llvm/dist/include/llvm/Support/CommandLine.h:22,
                   from /vol/llvm/src/llvm/dist/utils/FileCheck/FileCheck.cpp:18:
  /vol/gcc-8/lib/gcc/i386-pc-solaris2.11/8.1.0/include-fixed/iso/math_iso.h:209:21: note: candidate: ‘long double std::log10(long double)’
    inline long double log10(long double __X) { return __log10l(__X); }
                       ^~~~~
  /vol/gcc-8/lib/gcc/i386-pc-solaris2.11/8.1.0/include-fixed/iso/math_iso.h:170:15: note: candidate: ‘float std::log10(float)’
    inline float log10(float __X) { return __log10f(__X); }
                 ^~~~~
  /vol/gcc-8/lib/gcc/i386-pc-solaris2.11/8.1.0/include-fixed/iso/math_iso.h:70:15: note: candidate: ‘double std::log10(double)’
   extern double log10 __P((double));
                 ^~~~~

Fixed by using std::log10 instead, which allowed the compilation on i386-pc-solaris2.11
and sparc-sun-solaris2.11 to continue.

Differential Revision: https://reviews.llvm.org/D60043


git-svn-id: https://llvm.org/svn/llvm-project/llvm/trunk@357509 91177308-0d34-0410-b5e6-96231b3b80d8
---
 utils/FileCheck/FileCheck.cpp | 3 ++-
 1 file changed, 2 insertions(+), 1 deletion(-)

--- utils/FileCheck/FileCheck.cpp
+++ utils/FileCheck/FileCheck.cpp
@@ -21,6 +21,7 @@
 #include "llvm/Support/WithColor.h"
 #include "llvm/Support/raw_ostream.h"
 #include "llvm/Support/FileCheck.h"
+#include <cmath>
 using namespace llvm;
 
 static cl::opt<std::string>
@@ -405,7 +406,7 @@ static void DumpAnnotatedInput(raw_ostream &OS, const FileCheckRequest &Req,
   unsigned LineCount = InputFileText.count('\n');
   if (InputFileEnd[-1] != '\n')
     ++LineCount;
-  unsigned LineNoWidth = log10(LineCount) + 1;
+  unsigned LineNoWidth = std::log10(LineCount) + 1;
   // +3 below adds spaces (1) to the left of the (right-aligned) line numbers
   // on input lines and (2) to the right of the (left-aligned) labels on
   // annotation lines so that input lines and annotation lines are more
