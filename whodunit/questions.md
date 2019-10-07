# Questions

## What's `stdint.h`?
`stdint.h` is a header file developed in 1999 and implemented in 2000 as part of C99 C programing standard.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

The point of using these variations of signed and unsigned `int` data types is to specfy to the compiler how much memory each data type uses. These data types defined in the header file `stdint.h` specify the size, signedeness and dynamic range of your variables so the code runs exactly the same every time.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

Data Types    Size
`BYTE`        1-byte
`DWORD`       4-byte
`LONG`        4-byte
`WORD`        2-byte

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

`0x42 0x4D`

## What's the difference between `bfSize` and `biSize`?

`biSize` is the file size in bytes of the BITMAPINFOHEADER part of the BMP header. Constant at 40 bytes.
`biSize` is the file size in bytes of the entire BMP file including the header and the image itself.

## What does it mean if `biHeight` is negative?

If `biHeight` is negative the BMP file is a top-down DIB.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

`biBitCount`

## Why might `fopen` return `NULL` in `copy.c`?

No file exists, insufficient permissions

## Why is the third argument to `fread` always `1` in our code?

There is only one file to read from

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

TO skip over padding if any.

## What is `SEEK_CUR`?

The new file position will be the current position plus offset (in bytes). (current position)
