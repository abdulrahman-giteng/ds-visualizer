# Data Structures Visualizer

This project implements core data structures in C, paired with a small
Python-based visualization layer to help reason about structure and behavior.

The primary focus is on building **clean, correct, and well-tested**
data structure implementations with explicit ownership and memory rules.

## Overview

At the core of this project is a generic singly linked list written in C.
That list is reused to build higher-level data structures such as stacks,
queues, and a hash table.

The emphasis is not just on “making it work”, but on:

- predictable memory management
- simple, readable APIs
- behavior that is easy to reason about and test

This repository is intended as both a learning project and a
portfolio-quality codebase demonstrating solid systems fundamentals.

## Design Philosophy

All containers store generic `void *` pointers and manage **only their own
internal structure**.

In practice, this means:

- containers allocate and free their own nodes and metadata
- containers **do not** allocate or free user data
- the caller is always responsible for the lifetime of stored values

This keeps ownership rules explicit and avoids hidden behavior, which is
especially important in C.

## Implemented Data Structures

- **Generic linked list**
  - Singly linked
  - Stores `void *` payloads
  - Serves as the base for all other structures

- **Stack**
  - Built on top of the linked list
  - O(1) push and pop
  - LIFO behavior

- **Queue**
  - Built on top of the linked list
  - O(1) enqueue and dequeue
  - FIFO behavior

- **Hash table**
  - Integer keys with `void *` values
  - Separate chaining using linked lists
  - Handles collisions correctly
  - The table owns its entries, but not the stored values

## Visualization

A small Python-based visualizer is included to illustrate linked list
structure and pointer relationships.

The visualizer:
- renders nodes as boxes and pointers as arrows
- explicitly labels `HEAD` and `NULL`
- operates on snapshots of structure state (read-only)

The visualization layer is intentionally kept simple and separate from
the C implementations to maintain a clear separation of concerns.

## Testing

Each data structure has a small, focused test file written in C:

- `test_list.c`
- `test_stack.c`
- `test_queue.c`
- `test_hashtable.c`

The tests verify:
- correct behavior
- edge cases
- memory safety

All tests are run under **Valgrind** to ensure there are no memory leaks
or invalid memory accesses.


## Project Structure

```
c_src/
├── ds.c / ds.h # Generic linked list
├── stack.c / stack.h # Stack implementation
├── queue.c / queue.h # Queue implementation
├── hashtable.c / hashtable.h# Hash table implementation
├── test_list.c
├── test_stack.c
├── test_queue.c
├── test_hashtable.c

py_visualizer/
└── list_visualizer.py # Linked list visualization
```




## Future Work

Possible extensions (not required for correctness):

- additional data structures
- optional hash table resizing
- more generic key support