--- protolib/include/protoPktIP.h.orig	2021-02-01 04:25:51 UTC
+++ protolib/include/protoPktIP.h
@@ -69,7 +69,7 @@ class ProtoPktIP : public ProtoPkt
             RTG      =  43,  // IPv6 routing header
             FRAG     =  44,  // IPv6 fragment header
             GRE      =  47,  // Generic Router Encapsulation
-            ESP      =  50,  // Encapsulation security payload header
+            ESPXX      =  50,  // Encapsulation security payload header
             AUTH     =  51,  // authentication/ESP header  
             MOBILE   =  55,  // IP Moobility (Min Encap)                
             ICMPv6   =  58,  // ICMP for IPv6 
@@ -140,7 +140,7 @@ class ProtoPktIPv4 : public ProtoPktIP
                 {
                     EOOL   =      0, // End of Options List    [RFC791,JBP]                            
                     NOP    =      1, // No Operation           [RFC791,JBP]                            
-                    SEC    =    130, // Security                  [RFC1108]                            
+                    SECXX  =    130, // Security                  [RFC1108]                            
                     LSR    =    131, // Loose Source Route     [RFC791,JBP]                            
                     TS     =     68, // Time Stamp             [RFC791,JBP]                            
                     ESEC   =    133, // Extended Security         [RFC1108]                            
@@ -155,7 +155,7 @@ class ProtoPktIPv4 : public ProtoPktIP
                     VISA   =    142, // Expermental Access Control [Estrin]                            
                     ENCODE =     15, // ???                      [VerSteeg]                            
                     IMITD  =    144, // IMI Traffic Descriptor        [Lee]                            
-                    EIP    =    145, // Extended Internet Protocol[RFC1385]                            
+                    EIPXX  =    145, // Extended Internet Protocol[RFC1385]                            
                     TR     =     82, // Traceroute        [RFC1393]                                    
                     ADDEXT =    147, // Address Extension    [Ullmann IPv7]                            
                     RTRALT =    148, // Router Alert              [RFC2113]                            
