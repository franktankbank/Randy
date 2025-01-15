# Randy

A tool to generate many random numbers

## Badges

![GitHub License](https://img.shields.io/github/license/franktankbank/Randy?style=plastic)
## Features

- True Color
- Windows and MacOS supported
- Fast


## Installation

Install Randy with cmake and ninja

```bash
  git clone https://github.com/franktankbank/Randy.git
  cd Randy
  mkdir build && cd build
  cmake .. -G Ninja
  ninja
  ninja install
```

## Usage

This tool is currently a work in progress and currently only does one thing. More will be added at a later date.
```bash

Usage: randy SUBCOMMAND [OPTIONS]


OPTIONS:
   -h,    --help           Print this help message and exit
   -s,    --state string   Select a US state/territory
   -n,    --number int     Specify how many to generate
   -v,    --version        Show Version

SUBCOMMANDS:
  phone                    Generate Random phone number(s)
  version                  Show version
```

## Examples
```bash
randy phone -s NJ                # Generate 1 random phone number with a random New Jersey area code
randy phone -s NJ -n 3           # Generate 3 random phone numbers with a random New Jersey area code
randy version                    # Print version information
```
## License

[MIT](https://github.com/franktankbank/Randy/blob/main/LICENSE)


## Author

- [@franktankbank](https://www.github.com/franktankbank)

