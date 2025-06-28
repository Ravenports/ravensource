commit ae68470a837cb87bcfdb5a6efc80f661da07687b
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    fix type error
    
    this happens only in comm/, not in the main tree
    
    error[E0308]: mismatched types
        --> /wrkdirs/usr/ports/mail/thunderbird/work/thunderbird-138.0/comm/third_party/rust/wgpu-hal/src/vulkan/drm.rs:85:27
         |
    85   |                 .contains(&drm_stat.st_rdev)
         |                  -------- ^^^^^^^^^^^^^^^^^ expected `&u64`, found `&u32`
         |                  |
         |                  arguments to this method are incorrect
         |
         = note: expected reference `&u64`
                    found reference `&u32`

--- comm/third_party/rust/wgpu-hal/src/vulkan/drm.rs
+++ comm/third_party/rust/wgpu-hal/src/vulkan/drm.rs
@@ -81,7 +81,7 @@ impl super::Instance {
             // force-convert to `u64` to keep things portable.
             #[allow(clippy::useless_conversion)]
             if [primary_devid, render_devid]
-                .map(u64::from)
+                .map(u32::from)
                 .contains(&drm_stat.st_rdev)
             {
                 physical_device = Some(device)
