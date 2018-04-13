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

Copying timing straps from array 0 to arrays 1, 2, 3 from support/test.rom to test2.rom:

`./pbec -i support/test.rom -c 0 -p 1 2 3 -o test2.rom`

## Building:

### Prerequisites:

#### MacOS

Install the gcc compiler tools:

`xcode-select --install`

#### Ubuntu

`apt-get -y install gcc make g++ libboost-dev`


#### Centos

`yum install gcc gcc-c++`


### To build:

`make clean && make`

### To run:

`./pbec ...`

### To run tests:

`./tests`

---

### To build and run tests for Ubuntu 1604 in Docker:

`make dockerbuild-ubuntu1604`

This will make the binaries in your host as it uses a mounted volume to the source.

## Other details:

Header information taken from the linux source for the AMD drivers at:

https://github.com/torvalds/linux/blob/master/drivers/gpu/drm/radeon/atombios.h

