#!/bin/sh

#########################################################
#
# reference README http://source.android.com/source/downloading.html
# http://source.android.com/source/initializing.html
#
#########################################################

echo "Installing Host Packages required for compiling android "
sudo apt-get install git gnupg flex bison gperf build-essential \
	zip curl libc6-dev libncurses5-dev:i386 x11proto-core-dev \
	libx11-dev:i386 libreadline6-dev:i386 libgl1-mesa-glx:i386 \
	libgl1-mesa-dev g++-multilib mingw32 tofrodos \
	python-markdown libxml2-utils xsltproc zlib1g-dev:i386

sudo ln -s /usr/lib/i386-linux-gnu/mesa/libGL.so.1 /usr/lib/i386-linux-gnu/libGL.so

echo "Installing sun-java6-jdk"
sudo add-apt-repository "deb http://archive.ubuntu.com/ubuntu hardy main multiverse"
sudo add-apt-repository "deb http://archive.ubuntu.com/ubuntu hardy-updates main multiverse"
sudo add-apt-repository "deb http://archive.canonical.com/ lucid partner"
sudo apt-get update
sudo apt-get install sun-java6-jdk

echo "Installing repo binary"
mkdir -p ~/bin
curl https://dl-ssl.google.com/dl/googlesource/git-repo/repo > ~/bin/repo
chmod a+x ~/bin/repo
echo "repo installed at ~/bin/repo"
