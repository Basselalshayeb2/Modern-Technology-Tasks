# Modern Technology Practices

![Build and Test](https://github.com/Basselalshayeb2/Modern-Technology-Tasks/actions/workflows/build-and-test.yml/badge.svg)

It's a repo to store everything related to this course.
## 01- Input output flush 

#### **Description**  
We test all scenarios for flush function in C language.<br>
We can see in the outputs files different cases and different outputs.

### How to Run the Program  

The program accepts several parameters to enable or disable specific options:

- `-d`: **Default scenario** - Uses `fflush` to ensure immediate output for both `STDOUT` and `STDERR`.
- `-n`: **Newline scenario** - Adds `\n` to the output, utilizing line-buffering for `STDOUT` and immediate output for `STDERR`.
- `-s`: **Without fflush** - Omits `fflush`, so `STDOUT` may delay until the program exits, while `STDERR` appears immediately.
- `-r`: **Redirect output** - Demonstrates behavior when output is redirected to a file without `\n` or `fflush`, causing potential delay in `STDOUT` while `STDERR` appears immediately.  

### Example Commands  

To compile and run each scenario, execute the following commands:  

```bash
# Compile the program
gcc -o program main.c

# Run default scenario with fflush
./program -d

# Run scenario with newline (\n) addition
./program -n

# Run scenario without fflush
./program -s

# Run scenario with redirected output
./program -r

# Run all scenarios with the script
./run_experiments.sh
```

#### <u>Comperison between cases</u>
- Original program:<br>
Here we used the the original code, and we can see that "STDOUT" and "STDERR" appear immediately due to explicit fflush.
- With `\n` added:<br> 
We see that both "STDOUT\n" and "STDERR\n" appear immediately due to line-buffering.
- Without fflush:<br> 
"STDOUT" delay and wait until the program ends, "STDERR" appears immediately.
- Redirecting output to a file without "/n" or flush: <br>
"STDOUT" may delay, "STDERR" apears immediately.


## 02- Overcommit

#### **Description**

This program demonstrates how memory allocation, reading, and writing operations impact system behavior. By simulating controlled memory access patterns, the program explores scenarios of paging, memory consumption, and system performance under varying conditions.

The program is parameterized to allow flexible configuration of memory size, access modes, pause frequency, and duration. It also enables monitoring of system behavior using external tools like ```free```.

### How to use

- Compilation

```bash
gcc main.c
```

### Usage
- You can check all configurations using:
```bash
./a.out -h
```
- Or use the following table:

| Option | Description | Default value |
| ---- | ---- | ---- |
| -m, --memory_size | Memory size to allocate (MB) | 128 |
| -a, --access_mode | Access mode: `read` or `write` | `read` ||  |  |  |
| -p, --pause_steps | Number of steps (4 KB blocks) befure pausing | 1000 ||  |  |  |
| -d, --pause_time | Pause duration in milliseconds | 100 ||  |  |  |
| -h, --help | Show help message and exit |  |
|  |  |  |

### Examples
1. Default

```bash
./a.out
```

2. Write mode

```bash
./a.out -m 256 -a write -p 500 -d 50
```


3. Stress test

```bash
./a.out -m 5120 -a write -p 10000 -d 0
```

3. Small allocaton with fast pauses

```bash
./a.out -m 500 -a read -p 100 -d 10
```

3. Help Message

```bash
./a.out -h
```

### Monitoring

Using free -m during the pauses to observe total system memory usage in MB.

### Results

1. Read vs Write
    - **Read Mode** : Memory usage remains stable.
    - **Write Mode** : Physical memory allocation grows as pages are dirtied. When exceeding the maximum system will crash.
2. Continuous Write with no pauses:
    - Causes rapid memory consumption and high system load.