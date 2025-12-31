# Data Structures Visualizer

This project implements core data structures in C, with the long-term goal
of adding a Python-based visualization layer for learning and debugging.

Right now, the focus is on building **clean, correct, and well-tested**
data structure implementations with clear ownership and memory rules.

## Overview

The core of this project is a generic linked list written in C. That list
is then reused to build higher-level data structures like stacks, queues,
and a hash table.

The emphasis is not just on “making it work”, but on:
- predictable memory management
- simple, readable APIs
- behavior that is easy to reason about and test

This is intended as both a learning project and a portfolio-quality codebase.

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

## Testing

Each data structure has a small, focused test file written in C:

- `test_list.c`
- `test_stack.c`
- `test_queue.c`
- `test_hashtable.c`

The tests check:
- correct behavior
- edge cases
- memory safety

All tests are run under **Valgrind** to ensure there are no memory leaks
or invalid memory accesses.

## Project Structure

c_src/
├── ds.c / ds.h # Generic linked list
├── stack.c / stack.h # Stack implementation
├── queue.c / queue.h # Queue implementation
├── hashtable.c / hashtable.h # Hash table implementation
├── test_list.c
├── test_stack.c
├── test_queue.c
├── test_hashtable.c


## Future Work

- Python-based visualization layer
- Additional data structures
- Optional improvements (e.g. hash table resizing, more generic keys)