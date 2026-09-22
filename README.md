# Get Next Line

A function that reads a file descriptor and returns its content one line at a time, with a configurable buffer size (`BUFFER_SIZE`). It's an introduction to file descriptors, static variables, and reading files in fixed-size chunks.

## About

`get_next_line` reads from a given file descriptor and returns exactly one line per call — including the trailing `\n` when present — picking up right where the previous call left off, until the end of the file is reached.

## How it works

Each call to `get_next_line` reads from the file descriptor in chunks of `BUFFER_SIZE` bytes, appending what it reads to a growing line buffer, until a newline character is found or there's nothing left to read.

Once a newline is found:
1. Everything up to and including the `\n` is returned as the line.
2. Any leftover characters *after* the newline are preserved in a `static` variable, so they aren't lost.
3. The next call to `get_next_line` picks up from that leftover before reading more from the file descriptor.

This static variable is what allows the function to "remember" guaranteeing that nothing is lost between calls.

## Bonus: multiple file descriptors

The bonus version extends this to handle several file descriptors at once. Instead of a single static variable, it keeps an array of leftover buffers — one per file descriptor — so calls to `get_next_line` on different file descriptors don't interfere with each other and each one keeps its own reading progress.

*This project was done as part of the 42 curriculum.*
