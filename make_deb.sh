#!/bin/bash
echo_do() {
	tput setaf 3; echo "$@"; tput sgr0;
	$@
}

echo_do make install BUILD_TYPE=release DESTDIR=`pwd`/gapi_0.1-1/usr/local
echo_do dpkg-deb --build gapi_0.1-1
