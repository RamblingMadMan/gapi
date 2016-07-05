#!/bin/bash
BLUE='\033[0;34m'
NC='\033[0m'

echo_do() {
	tput setaf 3; echo "$@"; tput sgr0;
	$@
}

echo_do make install BUILD_TYPE=release DESTDIR=`pwd`/gapi_0.1-1/usr/local
echo_do dpkg-deb --build gapi_0.1-1
