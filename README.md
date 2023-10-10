# Critical Section and Summation using OpenMP
## Authors
- Caio Bonani Carvalho
- Davi Kawai Seiji
- Enzo Reis de Oliveira

## Introduction
This project explores the implementation of critical sections and summation tasks using OpenMP in C. The focus is on understanding the performance implications and correctness when parallelizing these types of problems.

---

## Table of Contents
1. [Critical Section using Manna-Pnueli Algorithm](#item-1---critical-section-using-manna-pnueli-algorithm)
2. [Summations, Critical Sections, and Reductions in OpenMP](#item-2---summations-critical-sections-and-reductions-in-openmp)

---

## Item 1 - Critical Section using Manna-Pnueli Algorithm

### Objective
The objective of this item is to implement the Manna-Pnueli algorithm that provides a mechanism for threads to safely enter a critical section. Two versions of the code are provided: one without proper control for entering the critical section and another with the correct implementation. The effectiveness of the critical section is demonstrated through both versions.

### Conclusions
After implementing and running both versions of the code, we observed critical differences in the behavior of the shared variable `SUM` during increment operations.

In the version with a proper critical section (`Manna-Pnueli_OpenMP_Secao_Critica.c`), the incrementation of the variable `SUM` was executed correctly, adhering to a consistent pattern of increasing the value one-by-one. This demonstrates that the critical section, facilitated by the Manna-Pnueli algorithm, effectively provides mutual exclusion, allowing only one thread at a time to execute the increment operation. Importantly, this correct behavior persists even when the number of client threads is increased to 2 or 4, further validating the effectiveness of the critical section implementation.

On the other hand, when the pre-protocol is commented out in the version without proper control for the critical section (`Manna-Pnueli_OpenMP_Sem_Secao_Critica.c`), the incrementation of `SUM` becomes inconsistent. The variable increments in an erratic manner, lacking any apparent pattern and ultimately leading to an incorrect final sum. This underscores the importance of correctly implementing critical sections when dealing with shared resources in a multi-threaded environment.



### Code Files
- `Manna-Pnueli_OpenMP_Secao_Critica.c` (with critical section)
- `Manna-Pnueli_OpenMP_Sem_Secao_Critica.c` (without critical section)

### Compilation and Execution
To compile and execute the code, use the following commands:
```bash
gcc -o Secao_Critica Manna-Pnueli_OpenMP_Secao_Critica.c -fopenmp
gcc -o Sem_Secao_Critica Manna-Pnueli_OpenMP_Sem_Secao_Critica.c -fopenmp

./Secao_Critica
./Sem_Secao_Critica
```

---

## Item 2 - Summations, Critical Sections, and Reductions in OpenMP

### Objective
This section focuses on the implementation of summation tasks in OpenMP. Two approaches are provided: one using the `#pragma omp critical` directive and another using OpenMP's reduction clause. Performance metrics such as processing time and speedup for 1, 2, 4, and 8 threads are evaluated.

### Code Files
- `openMP_version1.c` (using `#pragma omp critical`)
- `openMP_version2.c` (using `#pragma omp for reduction`)

### Compilation and Execution
To compile and execute the code, use the following commands:
```bash
gcc -o version1 openMP_version1.c -fopenmp
gcc -o version2 openMP_version2.c -fopenmp

./version1
./version2
