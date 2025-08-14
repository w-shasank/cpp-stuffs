# _Virtualization_

The fundamental concept behind virtualization is to make a system's resources—such as the CPU, memory, or disk—appear as though they are exclusively dedicated to a single program. This illusion is supported by several key mechanisms:

**Context Switching:** This is the technique the operating system uses to save the state of one process and restore the state of another, enabling the CPU to switch between processes.

**Time Sharing:** A method that allows multiple processes to share the CPU by allocating each a small time slice. This creates the impression that all programs are running simultaneously.

**Scheduling Policies:** These are the strategies and algorithms the OS uses to determine which process runs next and how long it gets to execute.

---

# _How a Program Becomes a Process_

When a user launches a program—either through a graphical interface or a command-line terminal—the operating system takes charge of creating a corresponding process by following these steps:

**Initial Setup:** The OS assigns a unique process ID (PID), sets the initial process state (typically "new" or "ready"), and determines a priority level. This data is stored in a structure called the Process Control Block (PCB).

**Memory Allocation:** The OS’s memory management unit (MMU) creates a virtual address space specifically for the new process. Initially, this space is empty. The MMU then maps this virtual memory to physical memory.

**Loading Code and Data:** The static program code and required runtime structures, such as the stack and any heap memory, are loaded into the process’s virtual address space. At this stage, the process’s memory is fully configured.

**Register Initialization:** The OS sets the CPU’s registers, including the program counter (PC) to the entry point of the program and the stack pointer to the top of the stack.

**Scheduling and Execution:** The process is added to the scheduler’s queue and will be selected to run based on the OS’s scheduling policy. Once selected, the process begins execution on the CPU.

---

# _Process States_

A process can be in one of several states at any given time:

**Running**: The process is currently executing instructions on the CPU.

**Ready:** The process is prepared to run but is waiting for the OS to schedule it onto the CPU. This is a holding state before execution.

**Blocked**: The process is waiting for an external event (such as disk I/O or a network packet) and cannot proceed. Once the event is complete, the process returns to the ready state and waits to be scheduled again.

---

# _Key Data Structures_

To manage all active processes, the OS relies on critical data structures:

- It maintains a ready list containing all processes that are eligible to run.
- It keeps track of the currently running process.
- It also monitors blocked processes, ensuring that when the required event completes, the appropriate process is returned to the ready queue.

# Process API

The Process API is a set of operating system functions that allow a program to create, manage, and interact with processes.
The major system cals includes the likes `fork()`, `exec()`, and `wait()` system calls.

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

After a `fork()` system call , both the parent and child processes begin executing from the same point, but the order in which they run is not guaranteed. This behavior is called non-determinism. It arises because the operating system’s**CPU scheduler** decides which process runs first, and this decision can vary each time the program is executed. As a result, outputs from the same program can appear in different orders depending on the scheduling.This problem/abnormality are often solved using synchronization tools like `wait()` to manage execution order.

- After a process calls `fork()`, both the parent and child processes can access the same file descriptor.
- The file descriptor refers to the same open file description, so they share the same file offset and status flags.
- If both processes write to the file at the same time, the output may be interleaved or corrupted due to race conditions.
- A file descriptor is a non-negative integer used to represent an open file or I/O resource in Unix-like systems.

# Limited Direct Execution (LDE)

## What is Limited Direct Execution?

- LDE is a technique where user programs run **directly** on the CPU to maximize efficiency.
- The CPU runs user code **in a restricted mode**, limiting what the program can do without OS intervention.
- This approach balances **performance** (direct execution) and **safety/security** (limited privileges).

## Why is LDE needed?

- Running user programs directly is fast but risky.
- Without restrictions, user code could crash the system or access hardware illegally.
- The OS must regain control regularly to manage resources and maintain fairness.

## Challenges with LDE

1. **Restricted operations by user code:**  
   User programs might try to perform unsafe or privileged operations.
2. **Regaining OS control:**  
   After handing control to user code, the OS must have a way to take it back.

## Approaches to Regaining Control

- **Cooperative approach:**  
  User programs voluntarily give control back (e.g., via system calls).  
  _Risk:_ Malicious or buggy programs might never yield control.
- **Non-cooperative approach:**  
  The OS _forces_ control back using hardware mechanisms like **timer interrupts** and **traps**.  
  _This is the common and safer approach._

## How Non-Cooperative Control Regain Works

- The OS sets a timer interrupt for each process’s CPU time slice.
- When the timer fires, the CPU interrupts the user process and switches to kernel mode.
- The OS saves the current process state.
- The scheduler decides which process to run next.
- The OS restores the chosen process’s state and resumes execution.

## Handling Concurrency

- Timer interrupts enable **concurrent execution** by switching between multiple processes.
- The OS uses synchronization tools like **locks**, **semaphores**, and **atomic operations** to avoid race conditions and ensure safe access to shared resources.

## Summary

- LDE provides a way to run user programs efficiently while enforcing restrictions.
- OS uses hardware support (restricted mode, traps, interrupts) to maintain control.
- Scheduler manages which process runs at any time.

---
# Context Switch

## What is a Context Switch?
- A context switch is the process where the CPU switches from running one process to another.
- It involves saving the state of the currently running process and loading the state of the next process to run.

## Why is it needed?
- Enables multitasking by allowing multiple processes to share the CPU.
- Ensures the OS can regain control and switch between processes efficiently.

## Steps in a Context Switch
1. **Save the current process state:**  
   - CPU registers, program counter, stack pointer, and other CPU state information are saved to the process control block (PCB).
2. **Update process state:**  
   - Mark the current process as ready, waiting, or another appropriate state.
3. **Select the next process:**  
   - The scheduler chooses the next process to run.
4. **Load the next process state:**  
   - CPU registers and other state information for the next process are loaded from its PCB.
5. **Resume execution:**  
   - CPU begins executing the new process from where it left off.

## Note
- Context switches have overhead because saving and loading states takes time.
- Efficient scheduling aims to minimize unnecessary context switches.


# OS Scheduling Algorithms Notes

## 1. Key Concepts
- **Arrival Time**: The time when a process is created, not when it starts execution.
- **Turnaround Time**: `T_turnaround = T_completion - T_arrival`. Measures total time a job spends in the system.
- **Response Time**: Time from submission to the first execution.
- **Fairness**: How evenly CPU resources are distributed among processes.

---

## 2. First-Come, First-Served (FCFS / FIFO)
- Jobs are executed in order of arrival.
- **Non-preemptive**.
- **Pros**: Simple to implement.
- **Cons**: Poor fairness; long jobs can block short jobs (convoy effect).

---

## 3. Shortest Job First (SJF) / Shortest Time to Completion First (STCF)
- **SJF**: Selects the job with the shortest total execution time.
- **STCF**: Preemptive version of SJF; the currently running job can be preempted if a shorter job arrives.
- **Pros**: Minimizes average turnaround time.
- **Cons**: Requires prior knowledge of job lengths; may starve long jobs.
- **Response Time**: May not be optimal.

---

## 4. Round Robin (RR)
- Each process gets a **time slice (quantum)**.
- **Preemptive**: process is moved to the end of the queue after its time slice expires.
- **Pros**: Fairer than FIFO for CPU-bound jobs.
- **Cons**: Larger context switching overhead; time slice choice affects performance.

---

## 5. Multi-Level Feedback Queue (MLFQ)
- Multiple priority queues; jobs move between queues based on behavior.
- **Rules**:
  1. Higher priority jobs run first.
  2. Equal priority: round-robin.
  3. New job enters topmost queue.
  4. If job uses up allotment → priority reduced.
  5. After some period, all jobs moved back to topmost queue.
- **Pros**: Approximates SJF for short jobs; fair to long CPU-bound jobs.
- **Cons**: More complex; requires tuning of time slices and queue parameters.

---

## 6. Proportional Share Scheduling
- CPU is divided among processes **proportional to their allocated shares**.
- **Lottery Scheduling**:
  - Processes have tickets; randomly pick a ticket to choose next process.
  - Probabilistic; starvation possible if one process holds most tickets.

---

## 7. Linux Completely Fair Scheduler (CFS)
- Implements **fair-share scheduling** efficiently.
- Uses **virtual runtime (vruntime)**:
  - Each process accumulates vruntime while running.
  - Scheduler picks process with **lowest vruntime** next.
- **Time slice**:
  - Calculated as `sched_latency / n_processes`.
  - Minimum granularity prevents too small slices.
- **Red-Black Tree**:
  - Processes organized by vruntime.
  - Efficient insert, delete, and finding process with lowest vruntime.

---

## 8. General Observations
- **Trade-offs** exist between metrics: performance, fairness, and response time.
- **Preemption** improves responsiveness but may increase context switching.
- **Workload assumptions** (like job length or I/O behavior) heavily influence the optimal scheduler choice.


