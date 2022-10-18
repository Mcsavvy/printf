% _printf(1) Version 1.0 | Custom _printf Documentation

NAME
====

**_printf** - format and print data

SYNOPSIS
========

**_printf(const char *format, ...)**

DESCRIPTION
===========

Produces output according to a format.  The format is the string that contains the text to be written to stdout. It can optionally contain embedded format tags that are replaced by the values specified in subsequent additional arguments and formatted as requested.

SUPPORTED FORMAT TAGS
---------------------

%c
:   prints a single character

%s
:   prints a string

%%
:   prints a '%'


EXAMPLES
========
```c
_printf("My name is %s, I'm %d years old and I stay at %c block." "John", 69, 'D');
// output
"My name is John, I'm 69 years old and I stay at D block."
```

BUGS
====

See GitHub Issues: [ISSUES](https://github.com/mcsavy/printf/issues)

AUTHORS
=======

* [Toluwani](https://github.com/ToluwaniAJ)

* [Mcsavvy](https://github.com/Mcsavvy)

SEE ALSO
========

**printf(1)**
