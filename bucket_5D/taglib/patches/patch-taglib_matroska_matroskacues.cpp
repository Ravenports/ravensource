--- taglib/matroska/matroskacues.cpp.orig	2026-01-25 11:41:46 UTC
+++ taglib/matroska/matroskacues.cpp
@@ -29,7 +29,7 @@
 
 using namespace TagLib;
 
-Matroska::Cues::Cues(offset_t segmentDataOffset) :
+Matroska::Cues::Cues(TagLib::offset_t segmentDataOffset) :
   Element(static_cast<ID>(EBML::Element::Id::MkCues)),
   segmentDataOffset(segmentDataOffset)
 {
@@ -118,13 +118,13 @@ void Matroska::Cues::write(TagLib::File
     Element::write(file);
 }
 
-bool Matroska::Cues::sizeChanged(Element &caller, offset_t delta)
+bool Matroska::Cues::sizeChanged(Element &caller, TagLib::offset_t delta)
 {
   // Adjust own offset
   if(!Element::sizeChanged(caller, delta))
     return false;
 
-  const offset_t offset = caller.offset() - segmentDataOffset;
+  const TagLib::offset_t offset = caller.offset() - segmentDataOffset;
   for(const auto &cuePoint : cuePoints) {
     if(cuePoint->adjustOffset(offset, delta)) {
       setNeedsRender(true);
@@ -156,7 +156,7 @@ Matroska::CuePoint::CuePoint() = default
 
 Matroska::CuePoint::~CuePoint() = default;
 
-bool Matroska::CuePoint::isValid(TagLib::File &file, offset_t segmentDataOffset) const
+bool Matroska::CuePoint::isValid(TagLib::File &file, TagLib::offset_t segmentDataOffset) const
 {
   for(const auto &track : cueTracks) {
     if(!track->isValid(file, segmentDataOffset))
@@ -185,7 +185,7 @@ Matroska::CuePoint::Time Matroska::CuePo
   return time;
 }
 
-bool Matroska::CuePoint::adjustOffset(offset_t offset, offset_t delta)
+bool Matroska::CuePoint::adjustOffset(TagLib::offset_t offset, TagLib::offset_t delta)
 {
   bool ret = false;
   for(const auto &cueTrack : cueTracks)
@@ -198,7 +198,7 @@ Matroska::CueTrack::CueTrack() = default
 
 Matroska::CueTrack::~CueTrack() = default;
 
-bool Matroska::CueTrack::isValid(TagLib::File &file, offset_t segmentDataOffset) const
+bool Matroska::CueTrack::isValid(TagLib::File &file, TagLib::offset_t segmentDataOffset) const
 {
   if(!trackNumber) {
     debug("Cue track number not set");
@@ -234,32 +234,32 @@ unsigned long long Matroska::CueTrack::g
   return trackNumber;
 }
 
-void Matroska::CueTrack::setClusterPosition(offset_t clusterPos)
+void Matroska::CueTrack::setClusterPosition(TagLib::offset_t clusterPos)
 {
   clusterPosition = clusterPos;
 }
 
-offset_t Matroska::CueTrack::getClusterPosition() const
+TagLib::offset_t Matroska::CueTrack::getClusterPosition() const
 {
   return clusterPosition;
 }
 
-void Matroska::CueTrack::setRelativePosition(std::optional<offset_t> relativePos)
+void Matroska::CueTrack::setRelativePosition(std::optional<TagLib::offset_t> relativePos)
 {
   relativePosition = relativePos;
 }
 
-std::optional<offset_t> Matroska::CueTrack::getRelativePosition() const
+std::optional<TagLib::offset_t> Matroska::CueTrack::getRelativePosition() const
 {
   return relativePosition;
 }
 
-void Matroska::CueTrack::setCodecState(std::optional<offset_t> codecStatePos)
+void Matroska::CueTrack::setCodecState(std::optional<TagLib::offset_t> codecStatePos)
 {
   codecState = codecStatePos;
 }
 
-std::optional<offset_t> Matroska::CueTrack::getCodecState() const
+std::optional<TagLib::offset_t> Matroska::CueTrack::getCodecState() const
 {
   return codecState;
 }
@@ -294,7 +294,7 @@ const Matroska::CueTrack::ReferenceTimeL
   return refTimes;
 }
 
-bool Matroska::CueTrack::adjustOffset(offset_t offset, offset_t delta)
+bool Matroska::CueTrack::adjustOffset(TagLib::offset_t offset, TagLib::offset_t delta)
 {
   bool ret = false;
   if(clusterPosition > offset) {
@@ -302,7 +302,7 @@ bool Matroska::CueTrack::adjustOffset(of
     ret = true;
   }
   // operator*() used instead of value() to support restricted compilers
-  if(offset_t codecStateValue;
+  if(TagLib::offset_t codecStateValue;
      codecState.has_value() && (codecStateValue = *codecState) != 0 &&
      codecStateValue > offset) {
     codecState = codecStateValue + delta;
