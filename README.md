# Modern Technology Practices
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