[![Run Status](https://api.shippable.com/projects/5b2b5de13626c20700cc6dd3/badge?branch=master)](https://app.shippable.com/github/wilvk/pbec)

# Polaris Bios Editor for the console (Linux/MacOS/Windows, etc.)

---
*WARNING: Running a modified BIOS will most likely void your GPU warranty and could potentially destroy your GPU. 
By using this software you agree to full responsibility for any results to your hardware.*
---

## Common commands:

### Show help:

`./pbec`

or

`./pbec --help`

### Viewing ROM details:

#### Print all info in summary:

`./pbec -i support/test.rom -s -r ALL`

#### Print only timing strap info:

`./pbec -i support/test.rom -s -r VRAM_TIMING`

#### Print all info in full (decimal and hex where relevant):

`./pbec -i support/test.rom -f -r ALL`



### Timing Straps

#### Copying:

Copying timing straps from array 0 to arrays 1, 2, 3 from support/test.rom to test2.rom:

`./pbec -i support/test.rom -c 0 -p 1 2 3 -o test2.rom`

#### Editing

You can also specify the hexadecimal byte form of a timing strap from the command line using the `-n` option. The length of the strap should be 96 hexadecimal characters (0-9, a-f).

The following example sets the first timing strap to the value specified.

`./pbec -i support/test.rom -o test3.rom -n aaaaaaaaaabbbbbbbbbbcccccccccc333333333344444444445555555555666666666677777777778888888889abcdef -p 1`

## Building:

### Prerequisites:

#### MacOS

Install the gcc compiler tools:

`xcode-select --install`

#### Ubuntu

`apt-get -y install gcc make g++`


#### Centos/Fedora

`yum install gcc gcc-c++`


### To build:

`make clean && make`

### To run:

`./pbec ...`

### To run tests:

`./tests`

---

### To build and run tests under different Linux flavours using Docker:

#### Ubuntu 16.04:

`make dockerbuild-ubuntu1604`

#### Fedora 27:

`make dockerbuild-fedora27`

This will make the binaries in your host as it uses a mounted volume to the source directory.

## Other details:

Header information taken from the linux source for the AMD drivers at:

https://github.com/torvalds/linux/blob/master/drivers/gpu/drm/radeon/atombios.h

