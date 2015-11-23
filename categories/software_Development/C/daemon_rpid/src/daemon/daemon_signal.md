/*
 	 LINUX SIGNALS - STUDY CASE

# See linux command 'man linux.h'

┌────────────┬───────────┬────┬────────────────────────────────────────────────────┬──────┐
│ Signal     │ Default   │ ID │          Description                               │ Used │
│            │ Action    │    │                                                    │      │
├────────────┼───────────┼────┼────────────────────────────────────────────────────┼──────┤
│SIGHUP      │  T        │  1 │ Hangup.                                            │  Y   │
│SIGINT      │  T        │  2 │ Terminal interrupt signal.                         │  Y   │
│SIGQUIT     │  A        │  3 │ Terminal quit signal.                              │  Y   │
│SIGILL      │  A        │  4 │ Illegal instruction.                               │  Y   │
│SIGTRAP     │  A        │  5 │ Trace/breakpoint trap.                             │  Y   │
│SIGABRT     │  A        │  6 │ Process abort signal.                              │  Y   │
│SIGBUS      │  A        │  7 │ Access to an undefined portion of a memory object. │  Y   │
│SIGFPE      │  A        │  8 │ Erroneous arithmetic operation.                    │  Y   │
│SIGKILL     │  T        │  9 │ Kill (cannot be caught or ignored).                │  N   │
│SIGUSR1     │  T        │ 10 │ User-defined signal 1.                             │  Y   │
│SIGSEGV     │  A        │ 11 │ Invalid memory reference.                          │  Y   │
│SIGUSR2     │  T        │ 12 │ User-defined signal 2.                             │  Y   │
│SIGPIPE     │  T        │ 13 │ Write on a pipe with no one to read it.            │  Y   │
│SIGALRM     │  T        │ 14 │ Alarm clock.                                       │  Y   │
│SIGTERM     │  T        │ 15 │ Termination signal.                                │  Y   │
│SIGSTKFLT   │           │ 16 │ <TODO: Check and fill out>                         │  -   │
│SIGCHLD     │  I        │ 17 │ Child process terminated, stopped,                 │  Y   │
│            │           │    │ or continued.                                      │      │
│SIGCONT     │  C        │ 18 │ Continue executing, if stopped.                    │  Y   │
│SIGSTOP     │  S        │ 19 │ Stop executing (cannot be caught or ignored).      │  Y   │
│SIGTSTP     │  S        │ 20 │ Terminal stop signal.                              │  Y   │
│SIGTTIN     │  S        │ 21 │ Background process attempting read.                │  Y   │
│SIGTTOU     │  S        │ 22 │ Background process attempting write.               │  Y   │
│SIGURG      │  I        │ 23 │ High bandwidth data is available at a socket.      │  Y   │
│SIGXCPU     │  A        │ 24 │ CPU time limit exceeded.                           │  Y   │
│SIGXFSZ     │  A        │ 25 │ File size limit exceeded.                          │  Y   │
│SIGVTALRM   │  T        │ 26 │ Virtual timer expired.                             │  -   │
│SIGPROF     │  T        │ 27 │ Profiling timer expired.                           │  N   │
│SIGWINCH    │           │ 28 │ <TODO: Check and fill out>                         │  -   │
│SIGIO       │           │ 29 │ <TODO: Check and fill out>                         │  -   │
│SIGPWR      │           │ 30 │ <TODO: Check and fill out>                         │  -   │
│SIGSYS      │  A        │ 31 │ Bad system call.                                   │  D   │
│SIGRTMIN    │           │ 34 │ <TODO: Check and fill out>                         │  -   │
│SIGRTMIN+15 │           │ 49 │ <TODO: Check and fill out>                         │  -   │
│SIGRTMAX-14 │           │ 50 │ <TODO: Check and fill out>                         │  -   │
│SIGRTMAX-2  │           │ 62 │ <TODO: Check and fill out>                         │  -   │
│SIGPOLL     │  T        │ -- │ Pollable event.                                    │      │
│            │           │    │                                                    │      │
└────────────┴───────────┴────┴────────────────────────────────────────────────────┴──────┘

The default actions are as follows:
* T     Abnormal termination of the process.
* A     Abnormal termination of the process with additional actions.
* I     Ignore the signal.
* S     Stop the process.
* C     Continue the process, if it is stopped; otherwise, ignore the signal.

$ kill -l
 1) SIGHUP
 2) SIGINT
 3) SIGQUIT
 4) SIGILL
 5) SIGTRAP
 6) SIGABRT
 7) SIGBUS
 8) SIGFPE
 9) SIGKILL
10) SIGUSR1
11) SIGSEGV
12) SIGUSR2
13) SIGPIPE
14) SIGALRM
15) SIGTERM
16) SIGSTKFLT
17) SIGCHLD
18) SIGCONT
19) SIGSTOP
20) SIGTSTP
21) SIGTTIN
22) SIGTTOU
23) SIGURG
24) SIGXCPU
25) SIGXFSZ
26) SIGVTALRM
27) SIGPROF
28) SIGWINCH
29) SIGIO
30) SIGPWR
31) SIGSYS
34) SIGRTMIN
35) SIGRTMIN+1
36) SIGRTMIN+2
37) SIGRTMIN+3
38) SIGRTMIN+4
39) SIGRTMIN+5
40) SIGRTMIN+6
41) SIGRTMIN+7
42) SIGRTMIN+8
43) SIGRTMIN+9
44) SIGRTMIN+10
45) SIGRTMIN+11
46) SIGRTMIN+12
47) SIGRTMIN+13
48) SIGRTMIN+14
49) SIGRTMIN+15
50) SIGRTMAX-14
51) SIGRTMAX-13
52) SIGRTMAX-12
53) SIGRTMAX-11
54) SIGRTMAX-10
55) SIGRTMAX-9
56) SIGRTMAX-8
57) SIGRTMAX-7
58) SIGRTMAX-6
59) SIGRTMAX-5
60) SIGRTMAX-4
61) SIGRTMAX-3
62) SIGRTMAX-2

*/