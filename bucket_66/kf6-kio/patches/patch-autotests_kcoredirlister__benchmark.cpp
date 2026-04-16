--- autotests/kcoredirlister_benchmark.cpp.orig	2026-03-07 20:31:18 UTC
+++ autotests/kcoredirlister_benchmark.cpp
@@ -40,15 +40,15 @@ public:
     {
         // Fill randInt[i] with random numbers from 0 to (10^(i+1))-1
         for (int i = 0; i < maxPowerOfTen; ++i) {
-            std::uniform_int_distribution<int> distribution(0, pow(10, i + 1) - 1);
+            std::uniform_int_distribution<int> distribution(0, pow(10.0, i + 1) - 1);
 
             // Fill the vector with consecutive numbers
-            randInt[i].reserve(pow(10, i + 1));
-            for (int j = 0; j < pow(10, i + 1); ++j) {
+            randInt[i].reserve(pow(10.0, i + 1));
+            for (int j = 0; j < pow(10.0, i + 1); ++j) {
                 randInt[i].append(j);
             }
             // And now scramble them a little bit
-            for (int j = 0; j < pow(10, i + 1); ++j) {
+            for (int j = 0; j < pow(10.0, i + 1); ++j) {
                 int rd1 = distribution(generator);
                 int rd2 = distribution(generator);
                 int swap = randInt[i].at(rd1);
@@ -144,7 +144,7 @@ public:
 
     void insert(int powerOfTen)
     {
-        for (int x = 0; x < pow(10, powerOfTen + 1); ++x) {
+        for (int x = 0; x < pow(10.0, powerOfTen + 1); ++x) {
             QUrl u = QUrl::fromLocalFile(fileNameArg.arg(randInt[powerOfTen].at(x))).adjusted(QUrl::StripTrailingSlash);
 
             KFileItem kfi(u, QStringLiteral("text/text"));
@@ -194,7 +194,7 @@ public:
 
     void insert(int powerOfTen)
     {
-        for (int x = 0; x < pow(10, powerOfTen + 1); ++x) {
+        for (int x = 0; x < pow(10.0, powerOfTen + 1); ++x) {
             QUrl u = QUrl::fromLocalFile(fileNameArg.arg(randInt[powerOfTen].at(x))).adjusted(QUrl::StripTrailingSlash);
 
             KFileItem kfi(u, QStringLiteral("text/text"));
@@ -247,7 +247,7 @@ public:
 
     void insert(int powerOfTen)
     {
-        for (int x = 0; x < pow(10, powerOfTen + 1); ++x) {
+        for (int x = 0; x < pow(10.0, powerOfTen + 1); ++x) {
             QUrl u = QUrl::fromLocalFile(fileNameArg.arg(randInt[powerOfTen].at(x))).adjusted(QUrl::StripTrailingSlash);
 
             KFileItem kfi(u, QStringLiteral("text/text"));
@@ -304,7 +304,7 @@ public:
     // Add files in random order from the randInt vector
     void insert(int powerOfTen)
     {
-        for (int x = 0; x < pow(10, powerOfTen + 1); ++x) {
+        for (int x = 0; x < pow(10.0, powerOfTen + 1); ++x) {
             QUrl u = QUrl::fromLocalFile(fileNameArg.arg(randInt[powerOfTen].at(x))).adjusted(QUrl::StripTrailingSlash);
 
             KFileItem kfi(u, QStringLiteral("text/text"));
@@ -324,7 +324,7 @@ void fillNumberOfFiles()
     QTest::addColumn<int>("numberOfFiles");
     for (int i = 0; i < maxPowerOfTen; ++i) {
         // it shows numberOfFiles: 10, 100 or 1000 but the data is the power of ten
-        QTest::newRow(QStringLiteral("%1").arg(pow(10, i + 1)).toLatin1()) << i;
+        QTest::newRow(QStringLiteral("%1").arg(pow(10.0, i + 1)).toLatin1()) << i;
     }
 }
 
@@ -332,7 +332,7 @@ template<class T>
 void createFiles(int powerOfTen)
 {
     T data;
-    const int numberOfFiles = pow(10, powerOfTen + 1);
+    const int numberOfFiles = pow(10.0, powerOfTen + 1);
     data.reserve(numberOfFiles);
     QBENCHMARK {
         data.clear();
@@ -346,12 +346,12 @@ void findByName(int powerOfTen)
 {
     T data;
     data.clear();
-    data.reserve(pow(10, powerOfTen + 1));
+    data.reserve(pow(10.0, powerOfTen + 1));
     data.insert(powerOfTen);
 
     QBENCHMARK {
         for (int i = 0; i < powerOfTen; i++) {
-            QString randName = QStringLiteral("a%1.txt").arg(pow(10, i));
+            QString randName = QStringLiteral("a%1.txt").arg(pow(10.0, i));
             KFileItem item = data.findByName(randName);
             // QCOMPARE(item.name(), randName);
         }
@@ -364,11 +364,11 @@ void findByUrl(int powerOfTen)
 {
     T data;
     data.clear();
-    data.reserve(pow(10, powerOfTen + 1));
+    data.reserve(pow(10.0, powerOfTen + 1));
     data.insert(powerOfTen);
     QBENCHMARK {
         for (int i = 0; i < powerOfTen; i++) {
-            QUrl randUrl = QUrl::fromLocalFile(fileNameArg.arg(pow(10, i)));
+            QUrl randUrl = QUrl::fromLocalFile(fileNameArg.arg(pow(10.0, i)));
             KFileItem item = data.findByUrl(randUrl);
             // QCOMPARE(item.url(), randUrl);
         }
@@ -381,10 +381,10 @@ void findByUrlAll(int powerOfTen)
 {
     T data;
     data.clear();
-    data.reserve(pow(10, powerOfTen + 1));
+    data.reserve(pow(10.0, powerOfTen + 1));
     data.insert(powerOfTen);
     QBENCHMARK {
-        for (int i = 0; i < pow(10, powerOfTen + 1); i++) {
+        for (int i = 0; i < pow(10.0, powerOfTen + 1); i++) {
             QUrl u = QUrl::fromLocalFile(fileNameArg.arg(i)).adjusted(QUrl::StripTrailingSlash);
             data.findByUrl(u);
         }
