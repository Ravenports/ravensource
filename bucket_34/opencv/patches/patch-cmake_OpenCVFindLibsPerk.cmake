From 0a4445d33c790e11b54818e198fad67d35424847 Mon Sep 17 00:00:00 2001
From: Kumataro <Kumataro@users.noreply.github.com>
Date: Tue, 15 Jul 2025 01:09:24 +0900
Subject: [PATCH] Merge pull request #27536 from Kumataro:fix27530

eigen: fix to get version from eigen after v3.4.0 #27536

Close https://github.com/opencv/opencv/issues/27530

### Pull Request Readiness Checklist

See details at https://github.com/opencv/opencv/wiki/How_to_contribute#making-a-good-pull-request

- [x] I agree to contribute to the project under Apache 2 License.
- [x] To the best of my knowledge, the proposed patch is not based on a code under GPL or another license that is incompatible with OpenCV
- [x] The PR is proposed to the proper branch
- [x] There is a reference to the original bug report and related work
- [ ] There is accuracy test, performance test and test data in opencv_extra repository, if applicable
      Patch to opencv_extra has the same branch name.
- [ ] The feature is well documented and sample code can be built with the project CMake
---
 cmake/OpenCVFindLibsPerf.cmake | 8 +++++++-
 1 file changed, 7 insertions(+), 1 deletion(-)

--- cmake/OpenCVFindLibsPerf.cmake.orig
+++ cmake/OpenCVFindLibsPerf.cmake
@@ -84,7 +84,13 @@ if(WITH_EIGEN AND NOT HAVE_EIGEN)
         set(EIGEN_WORLD_VERSION ${EIGEN3_WORLD_VERSION})
         set(EIGEN_MAJOR_VERSION ${EIGEN3_MAJOR_VERSION})
         set(EIGEN_MINOR_VERSION ${EIGEN3_MINOR_VERSION})
-      else()  # Eigen config file
+      elseif(DEFINED Eigen3_VERSION_MAJOR) # Recommended package config variables
+        # see https://github.com/opencv/opencv/issues/27530
+        set(EIGEN_WORLD_VERSION ${Eigen3_VERSION_MAJOR})
+        set(EIGEN_MAJOR_VERSION ${Eigen3_VERSION_MINOR})
+        set(EIGEN_MINOR_VERSION ${Eigen3_VERSION_PATCH})
+      else()  # Deprecated package config variables
+        # Removed on master at https://gitlab.com/libeigen/eigen/-/commit/f2984cd0778dd0a1d7e74216d826eaff2bc6bfab
         set(EIGEN_WORLD_VERSION ${EIGEN3_VERSION_MAJOR})
         set(EIGEN_MAJOR_VERSION ${EIGEN3_VERSION_MINOR})
         set(EIGEN_MINOR_VERSION ${EIGEN3_VERSION_PATCH})
