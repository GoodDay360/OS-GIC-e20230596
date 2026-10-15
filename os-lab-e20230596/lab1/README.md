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

- `remove` command removes the package but keeps its config files.
- `purge` command removes the packages and also everything related to the packages.

<!-- SCREENSHOT REQUIREMENT: your terminal after the purge, showing `ls -ld /etc/mc` and your prompt. -->
![Task 3](https://github.com/GoodDay360/OS-GIC-e20230596/blob/main/os-lab-e20230596/images/task3.jpg?raw=true)

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
![Task 5](https://github.com/GoodDay360/OS-GIC-e20230596/blob/main/os-lab-e20230596/images/task5.jpg?raw=true)

---

## Task 6: Virtualization and Hypervisor Detection

State whether your system is running on a virtual machine or physical hardware, based on the command outputs.

Currently system Hypervisor vender is KVM which state that it's a virtual machine.

<!-- SCREENSHOT REQUIREMENT: your terminal with the output of the four commands and your prompt. -->
![Task 6](https://github.com/GoodDay360/OS-GIC-e20230596/blob/main/os-lab-e20230596/images/task6.jpg?raw=true)

---

## My Prediction: Confirmed or Corrected

For each prediction answer (`oslab predict lab1`), write **confirmed** or **corrected** and what you saw that shows it. You test the third answer (`apt-get remove`) in Task 3.

---

## Plus / Challenge (only if you did them)
1. Run lscpu without grep and find the lines about the hypervisor. Run systemd-detect-virt on your own Ubuntu and on the server. Do they give the same answer? Why?
- They don't give the same answer.
- When I run `systemd-detect-virt` on my own ubuntu it show none, because I'm using a real physical hardware. I don't use wsl or any virtual machine.
- Meanwhile on the it show different from mine because it running on KVM which is a virtual machine.

2. A virtual machine can run inside another one. Look at hostname and uname -r on both machines. Which values are the same, and which are different?

* All values are different.
* My own ubuntu
  * hostname: goodday-katana15b12vfk
  * uname -r: 6.18.43-1-lts
* On server
  * hostname: i4gic-os
  * uname -r: 7.0.0-38-generic

## AI Note (optional)

One suggestion an AI tool gave you and how you checked it.
