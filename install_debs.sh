#!/bin/sh

set -e -x

apt-get update

apt-get install -y \
  make \
  cmake \
  ninja-build \
  git \
  g++11 \
  clang-14 \
  clang-format-14 \
  clang-tidy-14 \
  libc++-14-dev \
  libc++abi-14-dev \
  lldb-14 \
  vim \
  gdb