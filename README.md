# push_swap ✅ 125/100

> Sort a stack of integers using a restricted instruction set — with the fewest moves possible.

---

## What it does

`push_swap` takes a list of integers as arguments, and prints the shortest sequence of instructions to sort them in ascending order using two stacks (`a` and `b`) and 11 allowed operations.

```bash
$ ./push_swap 4 67 3 87 23
pb
pb
ra
pb
rra
sa
pa
pa
pa
```

Verify with the checker:
```bash
$ ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
OK
```

## Available operations

| Instruction | Effect |
|-------------|--------|
| `sa` / `sb` | Swap top 2 elements of stack a / b |
| `ss` | `sa` + `sb` simultaneously |
| `pa` / `pb` | Push top of b → a / top of a → b |
| `ra` / `rb` | Rotate stack a / b upward |
| `rr` | `ra` + `rb` simultaneously |
| `rra` / `rrb` | Reverse rotate stack a / b |
| `rrr` | `rra` + `rrb` simultaneously |

## Algorithm — Turkish Sort

push_swap uses the **Turkish Algorithm** (also called greedy insertion sort with cost optimization), which works in three phases:

**1. Push to b with partial pre-sort**
All elements except 3 are pushed to stack `b`. During this phase, elements are pushed in two "chunks" to keep `b` roughly pre-sorted (larger values at the top, smaller at the bottom), reducing the cost of reinserting them later.

**2. Greedy insertion back into a**
For each element in `b`, the algorithm calculates the **total cost** to bring that element to the top of `b` AND rotate `a` so its correct position is at the top. It then picks the element with the **lowest combined cost**, using `rr`/`rrr` when both stacks need to rotate in the same direction to save moves.

**3. Final rotation of a**
Once all elements are back in `a`, a single rotation (cheapest direction) aligns the smallest element to the top.

**Why Turkish?**
- Simpler to implement than Radix sort while achieving comparable performance
- Naturally exploits `rr`/`rrr` double rotations to cut move count
- Scales well: stays under **700 ops for 100 numbers** and **5500 ops for 500 numbers** (100% benchmark)

## Performance

| Input size | Max operations | Result |
|------------|---------------|--------|
| 3 numbers  | 3             | ✅ |
| 5 numbers  | 12            | ✅ |
| 100 numbers | < 700        | ✅ |
| 500 numbers | < 5500       | ✅ |

## Compilation

```bash
make        # builds push_swap
make bonus  # builds checker
make clean  # removes objects
make fclean # removes objects + binaries
make re     # fclean + make
```

## What I learned

- **Algorithm complexity**: why O(n²) greedy can beat O(n log n) in practice when move cost matters more than comparisons
- **Cost functions**: modelling a multi-variable optimization problem (rotation cost on two stacks simultaneously)
- **Stack data structures**: implementing push, pop, rotate, and reverse rotate efficiently in C
- **Edge cases**: duplicates, INT_MIN/INT_MAX overflow, single element, already-sorted input

## Resources

- [Turkish Algorithm explained — medium.com](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Sorting algorithm complexity — bigocheatsheet.com](https://www.bigocheatsheet.com/)
- [Visualizer for push_swap](https://github.com/o-reo/push_swap_visualizer)

### AI usage

Claude (claude.ai) was used to generate this README. No implementation code was written or requested from AI — the algorithm, cost function, and all source files were designed and coded independently.
