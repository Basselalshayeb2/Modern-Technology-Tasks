# Modern Technology Practices
It's a repo to store everything related to this course.
## 01- Input output flush 

#### <u>Description</u>
We test all scenarios for flush function in C language.<br>
We can see in the outputs files different cases and different outputs.

#### <u>Comperison between cases</u>
- Original program:<br>
Here we used the the original code, and we can see that "STDOUT" and "STDERR" appear immediately due to explicit fflush.
- With `\n` added:<br> 
We see that both "STDOUT\n" and "STDERR\n" appear immediately due to line-buffering.
- Without fflush:<br> 
"STDOUT" delay and wait until the program ends, "STDERR" appears immediately.
- Redirecting output to a file without "/n" or flush: <br>
"STDOUT" may delay, "STDERR" apears immediately.