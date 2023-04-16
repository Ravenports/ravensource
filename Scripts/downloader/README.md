# Ravenports Downloader

This script is used to install a functional ravensw on supported
platforms quickly.

```
============
FreeBSD
DragonFly
MidnightBSD
============
root> fetch http://www.ravenports.com/repository/ravenports-downloader.sh -o - | /bin/sh


============
NetBSD
============
root> ftp -o - http://www.ravenports.com/repository/ravenports-downloader.sh | /bin/sh


============
Solaris 10
============
root> /usr/sfw/bin/wget http://www.ravenports.com/repository/ravenports-downloader.sh -O - | /usr/bin/bash


============
Linux
============
user> curl http://www.ravenports.com/repository/ravenports-downloader.sh | sudo /bin/bash
      - or -
user> wget http://www.ravenports.com/repository/ravenports-downloader.sh -O - | sudo /bin/bash

```
