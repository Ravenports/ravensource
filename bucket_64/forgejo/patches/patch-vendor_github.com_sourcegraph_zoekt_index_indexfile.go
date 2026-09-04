--- vendor/github.com/sourcegraph/zoekt/index/indexfile.go.orig	2026-08-20 05:25:08 UTC
+++ vendor/github.com/sourcegraph/zoekt/index/indexfile.go
@@ -12,7 +12,7 @@
 // See the License for the specific language governing permissions and
 // limitations under the License.
 
-//go:build linux || darwin || freebsd
+//go:build linux || darwin || freebsd || dragonfly
 
 package index
 
