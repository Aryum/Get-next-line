# Get next line
A function that takes a file descriptor and returns the next line in that file, with an ajustable buffer size. It's meant as an introduction to file descriptors and static variables. 

## Main logic
The function read will store everything in the buffer array and append to the return string until it finds a new line, when it is found it performs a clean up to the buffer to remove any characters that were before the newline, perserving information that otherwise would be lost and avoiding repetion. 
The difference of the bonus part is that it can handle multiple file descriptors at the same time, by having an array of the buffers for each opened file descriptor.

