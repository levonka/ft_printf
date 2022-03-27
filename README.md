# ft_printf

Ft_printf is a School 42 project.
The purpose of this project is to recode original printf from libc.

[`ft_printf.en.pdf`](/ft_printf.en.pdf) is the task file.

## Usage

To compile the project, run:

```shell
$ make
```

To test the program:

```shell
$ make ex
$ ./a.out
```

## Final score

125/100 (max)

![](screenshots/score.png)

## Overview:

- parsing for flags, field_width, precision, length_modifier.
- parsing for conversion specifier.
- displaying UTF-8 characters. (%C and %S).
- computing unsigned numbers in base 2 (%b), 8 (%o), 10 (%u) and 16 (%x).
- displaying signed numbers (%d %D %i).
- displaying pointer address (%p).
- %f and %F to handle double and float numbers.
- %a and %A to handle hexadecimal double numbers
- colors

## Made by
|                                Person | Intra/Slack |
|--------------------------------------:|------:|
|   [Levon](https://github.com/levonka) | [agottlie](https://profile.intra.42.fr/users/agottlie) |
| [Sergey](https://github.com/yharwyn-) |  [yharwyn](https://profile.intra.42.fr/users/yharwyn-) |
