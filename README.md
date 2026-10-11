*This project has been created as part of the 42 curriculum by zeyalcin.*

# ft_printf

## Description

`ft_printf` is a reimplementation of the standard C `printf()` function for the mandatory conversions required by the 42 project.

The library supports:

- `%c` — character
- `%s` — string
- `%p` — pointer address in hexadecimal
- `%d` / `%i` — signed decimal integer
- `%u` — unsigned decimal integer
- `%x` — lowercase hexadecimal
- `%X` — uppercase hexadecimal
- `%%` — percent sign

The project is compiled as a static library named `libftprintf.a`.

## Implementation

The implementation is divided into three main parts:

- `ft_printf()` scans the format string and detects conversion specifiers.
- `ft_conversion()` selects the correct printing function and reads variadic arguments with `va_arg`.
- Helper functions print characters, strings, signed integers, pointers, and numbers in different bases.

Variadic arguments are handled with:

- `va_list`
- `va_start`
- `va_arg`
- `va_end`

Number conversion is implemented recursively.

For a number `n` and a base length `b`, the function first processes:

```text
n / b
```

and then:

```text
n % b
```

The remainder is used as an index in a base string.

Examples:

```text
0123456789
0123456789abcdef
0123456789ABCDEF
```

This allows the same base-printing function to be used for decimal and hexadecimal conversions.

For `%p`, the pointer value is converted to an unsigned integer representation and printed in lowercase hexadecimal format with the `0x` prefix.

No Libft functions are used in this implementation.

## Instructions

Compile the library with:

```bash
make
```

This creates:

```text
libftprintf.a
```

Available Makefile rules:

```bash
make
make clean
make fclean
make re
```

To test the library, create a small C file including `ft_printf.h` and compile it with:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a
```

Then run:

```bash
./a.out
```

Example:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Number: %d, Hex: %x, String: %s\n",
		-42, 42, "hello");
	return (0);
}
```

## Algorithm and Design Choices

The format string is processed from left to right using a pointer.

If the current character is not `%`, it is written directly with `write()`.

When `%` is found, the pointer moves to the next character and that character is passed to `ft_conversion()`.

The `ft_conversion()` function determines which conversion is required and retrieves the next variadic argument with `va_arg`.

This keeps `ft_printf()` focused on parsing the format string while the helper functions handle the actual output.

For signed decimal integers, a recursive function is used to print each digit.

Negative values are first converted to a positive `long` value after printing the minus sign. Using `long` prevents problems with the minimum `int` value.

A shared recursive base-printing function is used for:

- `%u`
- `%x`
- `%X`
- `%p`

This avoids implementing separate algorithms for unsigned decimal and hexadecimal numbers.

The recursive base conversion works by dividing the number by the length of the selected base.

For example, in decimal:

```text
123 / 10 = 12
123 % 10 = 3
```

The function first processes `12` and then `3`.

For hexadecimal:

```text
42 / 16 = 2
42 % 16 = 10
```

Using the lowercase hexadecimal base:

```text
0123456789abcdef
```

index `10` corresponds to `a`.

Therefore:

```text
42 decimal = 2a hexadecimal
```

For `%p`, the pointer address is converted to an `unsigned long` value and passed to the hexadecimal base-printing function.

The prefix:

```text
0x
```

is written before the hexadecimal address.

Printing functions also keep track of how many characters were written. This count is returned to `ft_printf()`, allowing it to return the total number of printed characters like the original `printf()`.

## Project Structure

```text
ft_printf/
├── Makefile
├── README.md
├── ft_printf.c
├── ft_printf.h
└── ft_printf_helper.c
```

### ft_printf.c

Contains:

- `ft_printf()`
- `ft_conversion()`
- string printing logic

### ft_printf_helper.c

Contains helper functions for:

- character printing
- string length calculation
- signed integer printing
- number base conversion
- pointer printing

### ft_printf.h

Contains the required function prototypes and includes.

## Resources

- `man 3 printf`
- `man 3 stdarg`
- `man va_arg`
- 42 ft_printf subject
- C documentation about variadic functions
- C documentation about integer representation
- C documentation about pointers

## AI Usage

AI was used as a learning and review tool during the project.

It was mainly used to understand and review:

- variadic functions
- `va_list`
- `va_start`
- `va_arg`
- `va_end`
- default argument promotions
- pointer formatting
- recursive number printing
- decimal and hexadecimal base conversion
- return value counting
- Makefile structure
- edge cases

The implementation was written and adapted while working through these concepts step by step.

AI was used to explain concepts, review code, identify mistakes, and suggest possible improvements rather than simply providing the complete project implementation.