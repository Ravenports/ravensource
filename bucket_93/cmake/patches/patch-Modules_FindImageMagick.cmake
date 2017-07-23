--- Modules/FindImageMagick.cmake.orig	2017-07-23 15:18:01 UTC
+++ Modules/FindImageMagick.cmake
@@ -196,6 +196,7 @@ foreach(component ${ImageMagick_FIND_COM
   if(component STREQUAL "Magick++")
     FIND_IMAGEMAGICK_API(Magick++ Magick++.h
       Magick++ CORE_RL_Magick++_
+      Magick++-6 Magick++-7
       Magick++-Q8 Magick++-Q16 Magick++-Q16HDRI Magick++-Q8HDRI
       Magick++-6.Q16 Magick++-6.Q8 Magick++-6.Q16HDRI Magick++-6.Q8HDRI
       Magick++-7.Q16 Magick++-7.Q8 Magick++-7.Q16HDRI Magick++-7.Q8HDRI
@@ -204,6 +205,7 @@ foreach(component ${ImageMagick_FIND_COM
   elseif(component STREQUAL "MagickWand")
     FIND_IMAGEMAGICK_API(MagickWand "wand/MagickWand.h;MagickWand/MagickWand.h"
       Wand MagickWand CORE_RL_wand_
+      MagickWand-6 MagickWand-7
       MagickWand-Q16 MagickWand-Q8 MagickWand-Q16HDRI MagickWand-Q8HDRI
       MagickWand-6.Q16 MagickWand-6.Q8 MagickWand-6.Q16HDRI MagickWand-6.Q8HDRI
       MagickWand-7.Q16 MagickWand-7.Q8 MagickWand-7.Q16HDRI MagickWand-7.Q8HDRI
@@ -212,6 +214,7 @@ foreach(component ${ImageMagick_FIND_COM
   elseif(component STREQUAL "MagickCore")
     FIND_IMAGEMAGICK_API(MagickCore "magick/MagickCore.h;MagickCore/MagickCore.h"
       Magick MagickCore CORE_RL_magick_
+      MagickCore-6 MagickCore-7
       MagickCore-Q16 MagickCore-Q8 MagickCore-Q16HDRI MagickCore-Q8HDRI
       MagickCore-6.Q16 MagickCore-6.Q8 MagickCore-6.Q16HDRI MagickCore-6.Q8HDRI
       MagickCore-7.Q16 MagickCore-7.Q8 MagickCore-7.Q16HDRI MagickCore-7.Q8HDRI
