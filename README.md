# Polaris Bios Editor for the console (Linux/MacOS/Windows, etc.)

---

## Common commands:

### Show help:

`./pbec`

or

`./pbec --help`

### Viewing ROM details:

#### Show all info in summary:

`./pbec -i test.rom -s -r ALL`

#### Show all info in full (decimal and hex where relevant):

`./pbec -i test.rom -f -r ALL`

### Timing Straps

Copying timing straps from array 0 to arrays 1, 2, 3 from test.rom to test2.rom:

`./pbec -i test.rom -c 0 -p 1 2 3 -o test2.rom`

## Building:

### Prerequisites:

#### MacOS

Install the gcc compiler tools:

`xcode-select --install`

#### Ubuntu

`apt-get install gcc`


#### Centos

`yum install gcc gcc-c++`


### To build:

`make clean && make`

### To run:

`./pbec ...`

### To run tests:

`./tests`

---

## Other details:

Header information taken from the linux source for the AMD drivers at:

https://github.com/torvalds/linux/blob/master/drivers/gpu/drm/radeon/atombios.h

