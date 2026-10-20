# Class Activity 1: System Calls

Student name: [Your name]  
Student ID: e20230596

## Task 1: File Creator and Reader

### Part A: File Creator

1. What flags did you pass to `open()`? What does each flag mean?

   `O_WRONLY` opens the file for writing, `O_CREAT` creates it if it is
   missing, and `O_TRUNC` clears its old contents.

2. What is `0644` in the permission argument? What does each digit represent?

   It is an octal permission mode. The owner can read and write the file.
   The group and other users can read it.

3. What does `fopen("output.txt", "w")` do internally that you had to do manually with `open()`?

   It creates the file if it is missing and clears it if it already exists.
   With `open()`, the flags and permissions have to be set directly.

### Part B: File Reader and Display

1. What does `read()` return? How is this different from `fgets()`?

   `read()` returns the number of bytes read, `0` at end of file, or `-1` on
   error. `fgets()` reads up to a newline or its buffer limit and adds a null
   character.

2. Why do you need a loop when using `read()`? When does it stop?

   A `read()` call may return fewer bytes than requested. The loop stops when
   `read()` returns `0`, which means the file has ended.

## Task 2: Directory Listing and File Info

1. What struct does `readdir()` return? What fields does it contain?

   It returns a pointer to a `struct dirent`, or `NULL` when there are no
   more entries. `d_name` contains the entry name. On Linux, `d_ino` contains
   its inode number.

2. What information does `stat()` provide beyond file size?

   It provides the file type, permissions, owner and group IDs, timestamps,
   inode number, and link count.

3. Why can't you just `write(1, some_number, ...)` directly — why do you need `snprintf()` first?

   `write()` writes bytes. `snprintf()` turns the number into printable
   decimal text and formats it with the filename.

## Task 3: Tracing System Calls

1. How many system calls does the library version of Task 1 make compared to the system call version? (Use `strace -c` output)

   The creator made 39 calls with the library version and 34 with the system
   call version. The reader made 40 and 35. These totals include startup
   calls.

2. What extra system calls do you see in the library version that are not in the system call version? What do they do? (e.g., `brk`, `mmap`, `access`, `fstat`)

   In both Task 1 programs, the library version made two more `fstat()` calls
   and two more `brk()` calls. `fstat()` gets information about an open file.
   `brk()` changes the program's heap. The creator also had one failed
   `ioctl()` call. Both versions made the same number of `mmap()` and
   `access()` calls.

3. When the library version calls `fprintf()`, how many actual `write()` system calls does `strace` show? Does it match what you expected? Why or why not?

   There is one `write()` for the text from `fprintf()` and one for the
   confirmation from `printf()`. The file text is buffered and written when
   the file is closed.

4. Based on the `strace` output, explain in your own words: What is the real difference between a library function and a system call?

   A library function runs in the program and may do extra work before
   requesting a service from the kernel. A system call is the request to the
   kernel itself. For example, `fopen()` uses file system calls underneath,
   while `open()` requests the file operation directly.

## Task 4: Exploring OS Structure

1. What is `/proc`? Is it a real filesystem on disk? Where does its content come from?

   `/proc` is a virtual filesystem, not stored on disk. The kernel supplies
   its contents when they are read.

2. What is the difference between a monolithic kernel and a microkernel? Based on the `lsmod` output, which type does Linux use?

   A monolithic kernel runs most operating system services in kernel space. A
   microkernel keeps fewer services in kernel space and runs more in user
   space. Linux is monolithic, though it also supports loadable modules.

3. Look at the output of `cat /proc/self/maps`. What different memory regions do you see? (e.g., heap, stack, shared libraries)

   The maps show the program, heap, stack, shared libraries such as `libc`,
   and kernel-provided regions such as `[vdso]` and `[vvar]`.

4. What does the kernel version string (from `uname -a`) tell you? Break down each part.

   `Linux` is the kernel name, followed by the hostname. `6.18.57-1-lts` is
   the kernel release. `#1` is the build number, and `SMP PREEMPT_DYNAMIC`
   describes the build. The next part is the build date. `x86_64` is the
   machine architecture, and `GNU/Linux` is the operating system.

5. How does `/proc` demonstrate that the OS acts as an intermediary between user programs and hardware?

   Programs get system and hardware information through files provided by the
   kernel in `/proc`, rather than reading hardware directly.
