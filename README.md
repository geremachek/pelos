# 📜 pelos

Pelos is a text filter which converts the typical hyphenated transliterations of the Aegean scripts into their actual Unicode representations.

Passing arguments to the parser over the command-line can be achieved through the `peloslw` and `peloscw` wrappers included in this repository.

## Usage

```
Usage: pelos [-hlc]
	-h	Display this help information
	-l	Parse Linear B transliterations
	-c	Parse Cypriot Syllabary transliterations
```

## Installation

Compile it with `make` and put the binary wherever.

## Future

The long-term trajectory for this project is to add support for Linear A (in some form) and for ideographic signs.