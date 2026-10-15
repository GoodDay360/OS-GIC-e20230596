# OS Lab 1 Submission

Copy this template to `os-lab-YOUR_ID/lab1/README.md` in your own repository. Follow [the instructions](lab1-instruction.md). Your prediction and checkpoint answers are already saved by `oslab`; do not copy them here.

- **Student Name:** CHHEM SOPHEA
- **Student ID:** e20230596
- **Ubuntu username on the server:** gic-chhem-sophea
- **My values** (`oslab values lab1`): file1 = ocean, file2 = candle, count = 2

---

## Task 1: Operating System Identification

Briefly describe what you observed about your OS and kernel. Which number is the kernel version, and which is the distribution version?

The system is running a 64-bit linux kernel
The hostname is i4gic-os.

Kernel version: 7.0.0-38-generic
Distribution version: Ubuntu 26.04.1 LTS

---

## Task 2: Essential Linux File and Directory Commands

Briefly describe your experience creating, copying, renaming and deleting files. What did the last `ls` show?

- Creating file use command "touch" follow by file name example "test.txt"
- Copying file use command "cp" with first params is source filename and second params is destination filename.
- rename follow the same params as copy but we use command "mv"
- Delete file use command "rm" follow by filename as first params.

<!-- You may show the contents of task2_file_commands.txt here; no screenshot needed. -->
/home/gic-chhem-sophea/oslab-work/lab1/task2_files
candle.txt
ocean.txt
This is file ocean
This is file candle
candle.txt
ocean.txt
ocean_copy.txt
candle_renamed.txt
ocean.txt
ocean_copy.txt
candle_renamed.txt
ocean.txt


---

## Task 3: Package Management Using APT

Explain the difference you observed between `remove` and `purge`.

<!-- SCREENSHOT REQUIREMENT: your terminal after the purge, showing `ls -ld /etc/mc` and your prompt. -->
![Task 3](images/task3.png)

---

## Task 4: Programs vs Processes

Briefly describe how you ran a background process and found it in the process list. What is the difference between a program and a process? What did you see before, during and after?

- Currently to run a background process we learn to use it with sleep command.
Example: sleep 30 & echo "Hello"
- To check running process I use command "ps" which list all running process.
- Program is an app or instruction that store on syste.
- Process is an active running program on the system.

---

## Task 5: Multitasking

Briefly describe the multitasking you saw. How many `sleep` lines did `ps` show? What does that show about the system, and what does it **not** show about how the processor is shared?

<!-- SCREENSHOT REQUIREMENT: your terminal with the `ps` result and your prompt. -->
![Task 5](images/task5.png)

---

## Task 6: Virtualization and Hypervisor Detection

State whether your system is running on a virtual machine or physical hardware, based on the command outputs.

<!-- SCREENSHOT REQUIREMENT: your terminal with the output of the four commands and your prompt. -->
![Task 6](images/task6.png)

---

## My Prediction: Confirmed or Corrected

For each prediction answer (`oslab predict lab1`), write **confirmed** or **corrected** and what you saw that shows it. You test the third answer (`apt-get remove`) in Task 3.

---

## Plus / Challenge (only if you did them)

Your answers.

## AI Note (optional)

One suggestion an AI tool gave you and how you checked it.
