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

### Results
Comparison between the sum of Manna-Pnueli_OpenMP_Secao_Critica.c (with a critical section) and Manna-Pnueli_OpenMP_Sem_Secao_Critica.c (without a critical section), using 2 clients (threads) and 100 interactions per interaction

#### With Critical Section
| Col 1 | Col 2 | Col 3 | Col 4 | Col 5 | Col 6 | Col 7 | Col 8 | Col 9 | Col 10 |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
| 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 |
| 21 | 22 | 23 | 24 | 25 | 26 | 27 | 28 | 29 | 30 |
| 31 | 32 | 33 | 34 | 35 | 36 | 37 | 38 | 39 | 40 |
| 41 | 42 | 43 | 44 | 45 | 46 | 47 | 48 | 49 | 50 |
| 51 | 52 | 53 | 54 | 55 | 56 | 57 | 58 | 59 | 60 |
| 61 | 62 | 63 | 64 | 65 | 66 | 67 | 68 | 69 | 70 |
| 71 | 72 | 73 | 74 | 75 | 76 | 77 | 78 | 79 | 80 |
| 81 | 82 | 83 | 84 | 85 | 86 | 87 | 88 | 89 | 90 |
| 91 | 92 | 93 | 94 | 95 | 96 | 97 | 98 | 99 | 100 |
| 101 | 102 | 103 | 104 | 105 | 106 | 107 | 108 | 109 | 110 |
| 111 | 112 | 113 | 114 | 115 | 116 | 117 | 118 | 119 | 120 |
| 121 | 122 | 123 | 124 | 125 | 126 | 127 | 128 | 129 | 130 |
| 131 | 132 | 133 | 134 | 135 | 136 | 137 | 138 | 139 | 140 |
| 141 | 142 | 143 | 144 | 145 | 146 | 147 | 148 | 149 | 150 |
| 151 | 152 | 153 | 154 | 155 | 156 | 157 | 158 | 159 | 160 |
| 161 | 162 | 163 | 164 | 165 | 166 | 167 | 168 | 169 | 170 |
| 171 | 172 | 173 | 174 | 175 | 176 | 177 | 178 | 179 | 180 |
| 181 | 182 | 183 | 184 | 185 | 186 | 187 | 188 | 189 | 190 |
| 191 | 192 | 193 | 194 | 195 | 196 | 197 | 198 | 199 | 200 |

#### Without Critical Section
| Col 1 | Col 2 | Col 3 | Col 4 | Col 5 | Col 6 | Col 7 | Col 8 | Col 9 | Col 10 |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 1 | 1 | 2 | 2 | 3 | 4 | 5 | 3 | 6 | 7 |
| 4 | 5 | 8 | 6 | 7 | 9 | 8 | 10 | 9 | 11 |
| 12 | 10 | 13 | 14 | 15 | 16 | 11 | 17 | 12 | 18 |
| 19 | 20 | 21 | 13 | 22 | 14 | 15 | 23 | 24 | 16 |
| 25 | 17 | 26 | 27 | 18 | 19 | 20 | 28 | 29 | 21 |
| 22 | 30 | 31 | 32 | 23 | 24 | 25 | 26 | 33 | 27 |
| 34 | 35 | 28 | 29 | 36 | 37 | 30 | 38 | 31 | 32 |
| 39 | 40 | 33 | 34 | 41 | 42 | 43 | 35 | 36 | 44 |
| 45 | 46 | 47 | 48 | 49 | 37 | 50 | 51 | 38 | 39 |
| 40 | 41 | 42 | 52 | 53 | 54 | 55 | 56 | 43 | 57 |
| 58 | 59 | 60 | 44 | 61 | 45 | 46 | 62 | 63 | 64 |
| 65 | 47 | 48 | 49 | 66 | 50 | 67 | 68 | 51 | 52 |
| 69 | 53 | 70 | 54 | 71 | 55 | 72 | 56 | 73 | 57 |
| 58 | 74 | 59 | 60 | 75 | 76 | 61 | 77 | 78 | 79 |
| 62 | 63 | 80 | 64 | 81 | 82 | 83 | 84 | 65 | 66 |
| 85 | 86 | 67 | 68 | 87 | 88 | 69 | 89 | 70 | 90 |
| 91 | 92 | 93 | 71 | 72 | 94 | 95 | 96 | 97 | 98 |
| 99 | 73 | 74 | 100 | 75 | 76 | 77 | 78 | 79 | 80 |
| 81 | 82 | 83 | 84 | 85 | 86 | 87 | 88 | 89 | 90 |
| 91 | 92 | 93 | 94 | 95 | 96 | 97 | 98 | 99 | 100 |

---
Comparison between the sum of Manna-Pnueli_OpenMP_Secao_Critica.c (with a critical section) and Manna-Pnueli_OpenMP_Sem_Secao_Critica.c (without a critical section), using 4 clients (threads) and 100 interactions per interaction

#### With Critical Section
| Col 1 | Col 2 | Col 3 | Col 4 | Col 5 | Col 6 | Col 7 | Col 8 | Col 9 | Col 10 | Col 11 | Col 12 | Col 13 | Col 14 | Col 15 | Col 16 | Col 17 | Col 18 | Col 19 | Col 20 |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 |
| 21 | 22 | 23 | 24 | 25 | 26 | 27 | 28 | 29 | 30 | 31 | 32 | 33 | 34 | 35 | 36 | 37 | 38 | 39 | 40 |
| 41 | 42 | 43 | 44 | 45 | 46 | 47 | 48 | 49 | 50 | 51 | 52 | 53 | 54 | 55 | 56 | 57 | 58 | 59 | 60 |
| 61 | 62 | 63 | 64 | 65 | 66 | 67 | 68 | 69 | 70 | 71 | 72 | 73 | 74 | 75 | 76 | 77 | 78 | 79 | 80 |
| 81 | 82 | 83 | 84 | 85 | 86 | 87 | 88 | 89 | 90 | 91 | 92 | 93 | 94 | 95 | 96 | 97 | 98 | 99 | 100 |
| 101 | 102 | 103 | 104 | 105 | 106 | 107 | 108 | 109 | 110 | 111 | 112 | 113 | 114 | 115 | 116 | 117 | 118 | 119 | 120 |
| 121 | 122 | 123 | 124 | 125 | 126 | 127 | 128 | 129 | 130 | 131 | 132 | 133 | 134 | 135 | 136 | 137 | 138 | 139 | 140 |
| 141 | 142 | 143 | 144 | 145 | 146 | 147 | 148 | 149 | 150 | 151 | 152 | 153 | 154 | 155 | 156 | 157 | 158 | 159 | 160 |
| 161 | 162 | 163 | 164 | 165 | 166 | 167 | 168 | 169 | 170 | 171 | 172 | 173 | 174 | 175 | 176 | 177 | 178 | 179 | 180 |
| 181 | 182 | 183 | 184 | 185 | 186 | 187 | 188 | 189 | 190 | 191 | 192 | 193 | 194 | 195 | 196 | 197 | 198 | 199 | 200 |
| 201 | 202 | 203 | 204 | 205 | 206 | 207 | 208 | 209 | 210 | 211 | 212 | 213 | 214 | 215 | 216 | 217 | 218 | 219 | 220 |
| 221 | 222 | 223 | 224 | 225 | 226 | 227 | 228 | 229 | 230 | 231 | 232 | 233 | 234 | 235 | 236 | 237 | 238 | 239 | 240 |
| 241 | 242 | 243 | 244 | 245 | 246 | 247 | 248 | 249 | 250 | 251 | 252 | 253 | 254 | 255 | 256 | 257 | 258 | 259 | 260 |
| 261 | 262 | 263 | 264 | 265 | 266 | 267 | 268 | 269 | 270 | 271 | 272 | 273 | 274 | 275 | 276 | 277 | 278 | 279 | 280 |
| 281 | 282 | 283 | 284 | 285 | 286 | 287 | 288 | 289 | 290 | 291 | 292 | 293 | 294 | 295 | 296 | 297 | 298 | 299 | 300 |
| 301 | 302 | 303 | 304 | 305 | 306 | 307 | 308 | 309 | 310 | 311 | 312 | 313 | 314 | 315 | 316 | 317 | 318 | 319 | 320 |
| 321 | 322 | 323 | 324 | 325 | 326 | 327 | 328 | 329 | 330 | 331 | 332 | 333 | 334 | 335 | 336 | 337 | 338 | 339 | 340 |
| 341 | 342 | 343 | 344 | 345 | 346 | 347 | 348 | 349 | 350 | 351 | 352 | 353 | 354 | 355 | 356 | 357 | 358 | 359 | 360 |
| 361 | 362 | 363 | 364 | 365 | 366 | 367 | 368 | 369 | 370 | 371 | 372 | 373 | 374 | 375 | 376 | 377 | 378 | 379 | 380 |
| 381 | 382 | 383 | 384 | 385 | 386 | 387 | 388 | 389 | 390 | 391 | 392 | 393 | 394 | 395 | 396 | 397 | 398 | 399 | 400 |

#### Without Critical Section
| Col 1 | Col 2 | Col 3 | Col 4 | Col 5 | Col 6 | Col 7 | Col 8 | Col 9 | Col 10 | Col 11 | Col 12 | Col 13 | Col 14 | Col 15 | Col 16 | Col 17 | Col 18 | Col 19 | Col 20 |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 1 | 1 | 1 | 1 | 2 | 2 | 2 | 3 | 2 | 3 | 3 | 3 | 4 | 5 | 4 | 5 | 5 | 6 | 7 | 4 |
| 4 | 5 | 6 | 6 | 7 | 8 | 5 | 7 | 8 | 8 | 9 | 9 | 9 | 6 | 7 | 10 | 10 | 11 | 10 | 8 |
| 12 | 12 | 11 | 13 | 12 | 14 | 15 | 9 | 10 | 12 | 13 | 13 | 16 | 14 | 17 | 15 | 18 | 11 | 17 | 18 |
| 19 | 16 | 20 | 21 | 12 | 17 | 19 | 20 | 22 | 23 | 13 | 14 | 20 | 21 | 22 | 21 | 24 | 22 | 23 | 24 |
| 25 | 26 | 27 | 15 | 22 | 25 | 23 | 24 | 25 | 26 | 27 | 28 | 29 | 30 | 31 | 32 | 16 | 26 | 27 | 28 |
| 29 | 28 | 33 | 17 | 18 | 30 | 31 | 32 | 29 | 33 | 34 | 35 | 34 | 19 | 30 | 31 | 36 | 37 | 35 | 20 |
| 32 | 38 | 36 | 21 | 33 | 39 | 37 | 22 | 23 | 34 | 40 | 41 | 38 | 39 | 24 | 35 | 36 | 42 | 37 | 38 |
| 40 | 25 | 43 | 39 | 44 | 40 | 45 | 46 | 41 | 42 | 26 | 27 | 41 | 42 | 47 | 43 | 28 | 43 | 48 | 44 |
| 49 | 45 | 44 | 46 | 47 | 48 | 49 | 50 | 51 | 29 | 30 | 50 | 45 | 52 | 31 | 51 | 46 | 52 | 47 | 53 |
| 54 | 32 | 53 | 48 | 54 | 55 | 55 | 33 | 49 | 56 | 56 | 57 | 58 | 34 | 50 | 51 | 57 | 58 | 59 | 59 |
| 35 | 52 | 53 | 60 | 54 | 55 | 55 | 56 | 56 | 57 | 60 | 36 | 37 | 38 | 57 | 58 | 58 | 61 | 59 | 60 |
| 39 | 40 | 41 | 59 | 62 | 63 | 61 | 64 | 65 | 66 | 67 | 42 | 60 | 62 | 63 | 64 | 68 | 69 | 70 | 43 |
| 61 | 62 | 63 | 64 | 65 | 65 | 66 | 71 | 44 | 66 | 67 | 67 | 68 | 72 | 69 | 70 | 73 | 74 | 74 | 75 |
| 76 | 77 | 78 | 79 | 45 | 46 | 47 | 48 | 49 | 50 | 68 | 75 | 76 | 77 | 80 | 51 | 69 | 78 | 79 | 81 |
| 82 | 83 | 52 | 70 | 80 | 84 | 85 | 53 | 71 | 81 | 82 | 83 | 86 | 87 | 88 | 89 | 90 | 91 | 92 | 93 |
| 94 | 95 | 54 | 72 | 73 | 84 | 85 | 96 | 97 | 98 | 99 | 55 | 74 | 86 | 87 | 88 | 89 | 56 | 57 | 75 |
| 90 | 91 | 58 | 76 | 92 | 59 | 77 | 78 | 93 | 60 | 61 | 79 | 94 | 95 | 62 | 63 | 64 | 65 | 66 | 67 |
| 68 | 80 | 81 | 96 | 97 | 98 | 69 | 70 | 71 | 72 | 73 | 82 | 74 | 75 | 83 | 84 | 85 | 86 | 76 | 77 |
| 78 | 79 | 80 | 87 | 81 | 88 | 89 | 90 | 82 | 83 | 84 | 91 | 85 | 92 | 93 | 94 | 86 | 87 | 88 | 95 |
| 96 | 89 | 97 | 90 | 98 | 99 | 91 | 100 | 101 | 102 | 92 | 93 | 94 | 95 | 96 | 97 | 103 | 98 | 99 | 100 |

---

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
- `openMP_version1.c` (using `#pragma omp for reduction`)
- `openMP_version2.c` (using `#pragma omp critical`)

### Methods used

#### #pragma omp for reduction
The reduction clause in OpenMP allows multiple threads to contribute to a reduction operation on a variable. This operation is thread-safe and generally performs well.

#### #pragma omp critical
The #pragma omp critical directive ensures that the block of code that follows will be executed by only one thread at a time. This is useful for protecting accesses to shared resources but can result in a bottleneck if the code block is large or if many threads try to access it.

### Results
| Type              | Number of Threads | Time (Seconds) | Iterations | Speedup |
|-------------------|-------------------|----------------|------------|---------|
| openMP - reduction| 1                 | 287.907        | 2000       | 1       |
| openMP - reduction| 2                 | 153.085        | 2000       | 1.8807  |
| openMP - reduction| 4                 | 87.616         | 2000       | 3.2860  |
| openMP - reduction| 8                 | 89.707         | 2000       | 3.2094  |
| openMP - critical | 1                 | 315.217        | 2000       | 1       |
| openMP - critical | 2                 | 176.787        | 2000       | 1.7830  |
| openMP - critical | 4                 | 98.677         | 2000       | 3.1944  |
| openMP - critical | 8                 | 93.936         | 2000       | 3.3556  |

### Conclusions
Based on the results, it's evident that the method using #pragma omp for reduction is more efficient in terms of processing time and speedup, especially as the number of threads increases. On the other hand, the method using #pragma omp critical shows lesser efficiency and may result in a bottleneck when used with a higher number of threads.

### Compilation and Execution
To compile and execute the code, use the following commands:
```
gcc -o version1 openMP_version1.c -fopenmp
gcc -o version2 openMP_version2.c -fopenmp

./version1
./version2
```

---

## Item 3 - Critical Sections in Java

### Objective
This section aims in the implementation of a critical section for an existing Java program. The program consists in a GUI, with buttons to spawn cars in the left or rigth side os the screen. In the original, the cars can crash -  represented by them passing through - into each other. Here we implemented a critical section code to avoid the crash, making cars wait for others to pass until their time comes.

### Code Files
All code files (.java) are inside the `code` directory.

### Compilation and Execution
Compile all the .java files with `javac <file_name.java>` them,

Execute with `java Main`

## Result
A GIF with the actual critical section working can be found in the root directory `Item_3/`.

## Demonstrative Video

A 6-minute video with a detailed explanation and demonstration of the results can be found [here](https://www.youtube.com/watch?si=IU7t632dPzkyN9jp&v=uEAlfSUMUMM&feature=youtu.be).
