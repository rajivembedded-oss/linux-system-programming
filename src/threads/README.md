# Project 2: POSIX Threads Programming

## Overview

Implemented multithreading concepts in C using POSIX pthread APIs on Linux.

## Topics Covered

- Thread creation using pthread_create()
- Thread synchronization using pthread_join()
- Passing arguments to threads
- Multiple thread execution
- Race condition demonstration
- Mutex synchronization
- Condition variables
- Producer-consumer communication
- Thread-safe logging system

## Programs

| Program | Description |
|---|---|
| thread_create.c | Basic thread creation |
| thread_argument.c | Passing data to threads |
| multiple_threads.c | Running multiple threads |
| race_condition.c | Demonstrating shared data problems |
| mutex_example.c | Protecting shared resources |
| producer_consumer.c | Thread synchronization |
| thread_logger.c | Multithreaded logging system |

## Build Example

```bash
gcc thread_logger.c -o thread_logger -pthread
./thread_logger