# push_swap

`push_swap` is a 42 project where the goal is to sort integers using two stacks and a limited set of operations.

This repository includes:
- `push_swap` (mandatory): generates the sorting instruction list
- `checker` (bonus): validates an instruction list read from standard input

## Features

- Parses numbers from both split and quoted arguments (for example: `./push_swap 2 1 3` and `./push_swap "2 1 3"`).
- Validates input:
  - non-numeric tokens
  - integer overflow/underflow
  - duplicate values
- Handles small stack sizes with specialized routines:
  - 2 elements
  - 3 elements
  - up to 5 elements
- Uses a butterfly-style strategy for bigger inputs.

## Data structures

The project uses a custom doubly linked list for both stacks.

- `t_list` node:
  - `num`: original integer value
  - `index`: rank of `num` in sorted order
  - `next` / `prev`: links for bidirectional traversal
- `t_stack` container:
  - `start`: top of stack
  - `end`: bottom of stack
  - `size`: current number of elements

This layout makes stack operations (`sa/sb`, `pa/pb`, `ra/rb`, `rra/rrb`) efficient without array shifts.

## Sorting approach

Sorting behavior is selected by input size:

- **2 elements**: single conditional swap if needed.
- **3 elements**: small decision tree using `sa`, `ra`, `rra`.
- **4-5 elements**:
  1. push the smallest indexed values to stack B
  2. sort remaining 3 elements in stack A
  3. push values back from B to A
- **More than 5 elements**:
  1. assign each number a sorted `index`
  2. use a butterfly pass to push ranges from A to B
  3. rebuild A by always moving the current maximum index from B back to A

The large-input path combines a chunk-like push phase with a max-first retrieval phase to keep operation count lower.

## Build

From the project source directory:

```bash
cd push_swap
make
```

Build bonus checker:

```bash
make bonus
```

Clean objects and binaries:

```bash
make clean
make fclean
```

## Usage

### push_swap

```bash
./push_swap 3 2 1
./push_swap "3 2 1"
```

Output is a list of operations (`sa`, `pb`, `ra`, etc.) that sorts stack A in ascending order.

### checker (bonus)

Pipe operations into `checker`:

```bash
./push_swap 3 2 1 | ./checker 3 2 1
```

`checker` prints:
- `OK` if stack A is sorted and stack B is empty
- `KO` otherwise
- `Error` for invalid input or invalid operations

## Allowed operations

- Swap: `sa`, `sb`, `ss`
- Push: `pa`, `pb`
- Rotate: `ra`, `rb`, `rr`
- Reverse rotate: `rra`, `rrb`, `rrr`

## Testers

- https://github.com/gemartin99/Push-Swap-Tester
- https://github.com/LeoFu9487/push_swap_tester
- https://github.com/lmalki-h/push_swap_tester
