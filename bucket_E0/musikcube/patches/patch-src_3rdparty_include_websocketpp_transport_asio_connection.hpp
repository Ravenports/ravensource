--- src/3rdparty/include/websocketpp/transport/asio/connection.hpp.orig	2024-07-14 19:37:30 UTC
+++ src/3rdparty/include/websocketpp/transport/asio/connection.hpp
@@ -573,7 +573,7 @@ protected:
         lib::error_code const & ec)
     {
         if (ec == transport::error::operation_aborted ||
-            (post_timer && lib::asio::is_neg(post_timer->expires_from_now())))
+            (post_timer && lib::asio::is_neg(post_timer->expires_after())))
         {
             m_alog->write(log::alevel::devel,"post_init cancelled");
             return;
@@ -679,7 +679,7 @@ protected:
         // Whatever aborted it will be issuing the callback so we are safe to
         // return
         if (ec == lib::asio::error::operation_aborted ||
-            lib::asio::is_neg(m_proxy_data->timer->expires_from_now()))
+            lib::asio::is_neg(m_proxy_data->timer->expires_after()))
         {
             m_elog->write(log::elevel::devel,"write operation aborted");
             return;
@@ -751,7 +751,7 @@ protected:
         // Whatever aborted it will be issuing the callback so we are safe to
         // return
         if (ec == lib::asio::error::operation_aborted ||
-            lib::asio::is_neg(m_proxy_data->timer->expires_from_now()))
+            lib::asio::is_neg(m_proxy_data->timer->expires_after()))
         {
             m_elog->write(log::elevel::devel,"read operation aborted");
             return;
@@ -1095,7 +1095,7 @@ protected:
         callback, lib::asio::error_code const & ec)
     {
         if (ec == lib::asio::error::operation_aborted ||
-            lib::asio::is_neg(shutdown_timer->expires_from_now()))
+            lib::asio::is_neg(shutdown_timer->expires_after()))
         {
             m_alog->write(log::alevel::devel,"async_shutdown cancelled");
             return;
