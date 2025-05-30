# ft_printf project

## Description 📖

The idea of the project is to mimic the functionality of the `printf` function from the `stdio` library.

## Useful notes 📝

* On macOS the NULL pointer is outputted by `printf` as `0x0`, when on campus linux as `(nil)`
* Potentially only on macOS list of arguments (`va_list`) should be passed as pointer, when on linux it can be passed without a pointer to it
