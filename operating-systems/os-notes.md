# *Virtualization*

The fundamental concept behind virtualization is to make a system's resources—such as the CPU, memory, or disk—appear as though they are exclusively dedicated to a single program. This illusion is supported by several key mechanisms:

**Context Switching:** This is the technique the operating system uses to save the state of one process and restore the state of another, enabling the CPU to switch between processes.

**Time Sharing:** A method that allows multiple processes to share the CPU by allocating each a small time slice. This creates the impression that all programs are running simultaneously.

**Scheduling Policies:** These are the strategies and algorithms the OS uses to determine which process runs next and how long it gets to execute.

---

# *How a Program Becomes a Process*

When a user launches a program—either through a graphical interface or a command-line terminal—the operating system takes charge of creating a corresponding process by following these steps:

**Initial Setup:** The OS assigns a unique process ID (PID), sets the initial process state (typically "new" or "ready"), and determines a priority level. This data is stored in a structure called the Process Control Block (PCB).

**Memory Allocation:** The OS’s memory management unit (MMU) creates a virtual address space specifically for the new process. Initially, this space is empty. The MMU then maps this virtual memory to physical memory.

**Loading Code and Data:** The static program code and required runtime structures, such as the stack and any heap memory, are loaded into the process’s virtual address space. At this stage, the process’s memory is fully configured.

**Register Initialization:** The OS sets the CPU’s registers, including the program counter (PC) to the entry point of the program and the stack pointer to the top of the stack.

**Scheduling and Execution:** The process is added to the scheduler’s queue and will be selected to run based on the OS’s scheduling policy. Once selected, the process begins execution on the CPU.

---

# *Process States*

A process can be in one of several states at any given time:

**Running**: The process is currently executing instructions on the CPU.

**Ready:** The process is prepared to run but is waiting for the OS to schedule it onto the CPU. This is a holding state before execution.

**Blocked**: The process is waiting for an external event (such as disk I/O or a network packet) and cannot proceed. Once the event is complete, the process returns to the ready state and waits to be scheduled again.

---

# *Key Data Structures*

To manage all active processes, the OS relies on critical data structures:

- It maintains a ready list containing all processes that are eligible to run.
- It keeps track of the currently running process.
- It also monitors blocked processes, ensuring that when the required event completes, the appropriate process is returned to the ready queue.

#  Process API

The Process API is a set of operating system functions that allow a program to create, manage, and interact with processes.
The major system cals includes the likes  `fork()`, `exec()`, and `wait()` system calls.

---

- These system calls are **crucial** for creating and managing processes.
- They help understand how operating systems support **multiprogramming**.
- Used widely in real applications and interviews.


They are the API's that ,Operating systems offer **simple yet powerful** interfaces for:
- Creating a new process
- Replacing a process with a new program
- Waiting for a process to finish

# Process API Functions

## 1. `fork()` – Create a New Process

**Definition:**  
fork() creates a new process by duplicating the current one.

**Behavior:**
- The process that calls fork() is the **parent**.
- It creates a **child** process — an almost identical copy.
- Both continue from the point where fork() routine iss called.

**Return Value:**
- **Parent gets:** PID of the child
- **Child gets:** 0
- **On error:** -1 is returned

