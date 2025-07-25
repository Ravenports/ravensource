# RESERVED_WARNING
# Provide default versions for ports with multiple versions selectable
# by the user.
#
# Users who want to override these defaults can easily do so by defining
# DEFAULT_VERSIONS in their make.conf as follows:
#
# DEFAULT_VERSIONS=	perl5=5.36 ruby=3.2
#

.if !defined(_INCLUDE_BSD_DEFAULT_VERSIONS_MK)
_INCLUDE_BSD_DEFAULT_VERSIONS_MK=	yes

.  for base in LUA MYSQL PERL5 PHP PGSQL PYTHON3 RUBY SSL TCL
.undef ${base}_DEFAULT
.  endfor

.  for base in ${DEFAULT_VERSIONS}
_l=			${base:C/=.*//g}
${_l:tu}_DEFAULT=	${base:C/.*=//g}
.  endfor

#-------------------------------------------------------------------------
# PERL5
# Possible values: 5.38 and 5.40
#-------------------------------------------------------------------------

PERL5_DEFAULT?=		5.38

PERL_5.38_VERSION=	5.38.4
PERL_5.40_VERSION=	5.40.2

#-------------------------------------------------------------------------
# RUBY
# Possible values: 3.2, 3.3, 3.4
#-------------------------------------------------------------------------

RUBY_DEFAULT?=		3.3

RUBY_3.2_VERSION=	3.2.8
RUBY_3.3_VERSION=	3.3.8
RUBY_3.4_VERSION=	3.4.5

#-------------------------------------------------------------------------
# PYTHON
# Possible values: 3.12, 3.13
#-------------------------------------------------------------------------

PYTHON3_DEFAULT?=	3.12

PYTHON_3.12_VERSION=	3.12.11
PYTHON_3.13_VERSION=	3.13.5

PIP_3.12_VERSION=	25.0.1
PIP_3.13_VERSION=	25.1.1

#-------------------------------------------------------------------------
# SSL
# Possible values: openssl30, libressl, libressl-devel
#-------------------------------------------------------------------------

SSL_DEFAULT?=		libressl

#-------------------------------------------------------------------------
# LUA
# Possible values: 5.2, 5.3, 5.4
#-------------------------------------------------------------------------

LUA_DEFAULT?=		5.4

LUA_5.2_VERSION=	5.2.4
LUA_5.3_VERSION=	5.3.6
LUA_5.4_VERSION=	5.4.8

#-------------------------------------------------------------------------
# TCL/TK
# Possible values: 8.6, 9.0
#-------------------------------------------------------------------------

TCL_DEFAULT?=		8.6

TCL_8.6_VERSION=	8.6.16
TCL_9.0_VERSION=	9.0.2

#-------------------------------------------------------------------------
# PGSQL
# Possible values: 13, 14, 15, 16, 17
#-------------------------------------------------------------------------

PGSQL_DEFAULT?=		16

PGSQL_13_VERSION=	13.21
PGSQL_14_VERSION=	14.18
PGSQL_15_VERSION=	15.13
PGSQL_16_VERSION=	16.9
PGSQL_17_VERSION=	17.5

#-------------------------------------------------------------------------
# MYSQL and derivatives
# Possible values: oracle-(8.0,8.4),innovation,mariadb-(10.6, 10.11, 11.[48], 12)
#
# MariaDB releases:
#   MariaDB 10.6   EOL 06 JUL 2026 (STABLE-LTS)
#   MariaDB 10.11  EOL 16 Feb 2028 (STABLE-LTS)
#   MariaDB 11.4   EOL 29 May 2029 (STABLE-LTS)
#   MariaDB 11.8   EOL 04 JUN 2028 (STABLE-LTS)
#   MariaDB 12.0   EST     Q3 2025 (12.3 EST LTS)
#   MariaDB 13.0   EST     Q3 2026 (13.3 EST LTS)
#   MariaDB 14.0   EST     Q3 2027 (14.3 EST LTS)
#-------------------------------------------------------------------------

MYSQL_DEFAULT=			oracle-8.0

MYSQL_oracle-8.0_VERSION=	8.0.42
MYSQL_oracle-8.4_VERSION=	8.4.5
MYSQL_innovation_VERSION=	9.3.0
MYSQL_mariadb-10.5_VERSION=	10.5.29
MYSQL_mariadb-10.6_VERSION=	10.6.22
MYSQL_mariadb-10.11_VERSION=	10.11.13
MYSQL_mariadb-11.4_VERSION=	11.4.7
MYSQL_mariadb-11.8_VERSION=	11.8.2

#-------------------------------------------------------------------------
# PHP (restricted to branches still receiving updates)
# Possible values: 8.2, 8.3, 8.4
#-------------------------------------------------------------------------

PHP_DEFAULT?=		8.3

PHP_8.2_VERSION=	8.2.29
PHP_8.3_VERSION=	8.3.23
PHP_8.4_VERSION=	8.4.10

#-------------------------------------------------------------------------
# Ravenports system root versions per platform
# Format: ID=opsys/arch/stdarch/os-version/os-release/os-major
#-------------------------------------------------------------------------

PLATFORM_FreeBSD_x86-64=	FreeBSD/amd64/x86_64/1402000/14.2/14
PLATFORM_DragonFly_x86-64=	DragonFly/x86_64/x86_64/600400/6.4/6.4
PLATFORM_Linux_x86-64=		Linux/x86_64/x86_64/610000/6.1.0/6.1
PLATFORM_SunOS_x86-64=		SunOS/i86pc/x86_64/151054/5.11/5.11
PLATFORM_MacOS_x86-64=		Darwin/x86_64/x86_64/170700/17.7.0/17
PLATFORM_NetBSD_x86-64=		NetBSD/x86_64/x86_64/902000000/10.0/10
PLATFORM_MidnightBSD_x86-64=	MidnightBSD/amd64/x86_64/300005/3.0.0/3
PLATFORM_OpenBSD_x86-64=	OpenBSD/amd64/x86_64/tbd/tbd/tbd

#-------------------------------------------------------------------------
# To support old system roots
#-------------------------------------------------------------------------

PREVIOUS_DF64_R62=		DragonFly/x86_64/x86_64/600200/6.2/6.2
PREVIOUS_Linux_K44=		Linux/x86_64/x86_64/440053/4.4.0/4.4
PREVIOUS_FBSD64_R13=		FreeBSD/amd64/x86_64/1302001/13.2/13

.endif # defined (_INCLUDE_BSD_DEFAULT_VERSIONS_MK)
