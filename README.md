# Programming Task 2 |  Interior-Point Algorithm
**Introduction to Optimization - Fall 2024**

## Team
- **Elina Kuzmicheva**  
- **Maxim Fomin**   
- **Sergei Melnikov**   

## Programming Language
- **C++**
- **Python** (Auto-Tester)

## Input Format
The input contains:
- A vector of coefficients of the objective function `C`.
- A matrix of coefficients of the constraint function `A`.
- A vector of initial interior point `x`.
- The approximation accuracy `ε`.
- The parameter alpha `α`.

## Auto-Tester
### How to run
**Linux:** `python3 -m tester`

**Windows:** `python -m tester`

### Output format
After running tester you can see results for all 5 tests using three configurated solvers:

- Interior-Point Algorithm (alpha=0.5)
- Interior-Point Algorithm (alpha=0.9)
- Simplex Method

**For each test you will get output in format:**
```shell
Test #(N/M)
Test# N | Interior Point Algo (alpha = 0.5)
-- Input --
{TEST INPUT}

-- Output --
{PROGRAM OUTPUT}
 
Test# N | Interior Point Algo (alpha = 0.9)
-- Input --
{TEST INPUT}

-- Output --
{PROGRAM OUTPUT}

Test# N | Simplex method
-- Input --
{TEST INPUT}

-- Output --
{PROGRAM OUTPUT}

Press Enter to display next test...
```
> Results for each test you can see without running tester : [Achieved results](#achieved-results)

## Tests Statements

### Test 1: Two-Dimensional Maximization Problem
Maximize:
`z = x₁ + x₂`

Subject to:

- `2x₁ + 4x₂ ≤ 16`
- `x₁ + 3x₂ ≤ 9`
- `x₁, x₂ ≥ 0`

Initial point: `x = [2, 1, 1, -4]`


### Test 2: Three-Dimensional Minimization Problem
Minimize:
`z = 9x₁ - 2x₂ + 4x₃`

Subject to:

- `2x₁ + 4x₂ + x₃ ≤ 6`
- `3x₁ - 3x₂ + 4x₃ ≤ 3`
- `5x₁ + 2x₂ - x₃ ≤ 7`
- `x₁, x₂, x₃ ≥ 0`

Initial point: `x = [1, 3, 2, 4, 5, 2]`


### Test 3: Two-Dimensional Maximization Problem
Maximize:
`z = 3x₁ + x₂`

Subject to:

- `2x₁ + x₂ ≤ 6`
- `x₁ + 2x₂ ≤ 4`
- `x₁, x₂ ≥ 0`

Initial point: `x = [1, 1, 1, 1]`


### Test 4: Three-Dimensional Maximization Problem
Maximize:
`z = 9x₁ - 10x₂ + 16x₃`

Subject to:

- `18x₁ + 15x₂ + 12x₃ ≤ 360`
- `6x₁ + 4x₂ + 8x₃ ≤ 192`
- `5x₁ + 3x₂ + 3x₃ ≤ 180`
- `x₁, x₂, x₃ ≥ 0`

Initial point: `x = [3, 2, 4, 1, 0.5, 4]`


### Test 5: Two-Dimensional Minimization Problem
Minimize:
`z = x₁ + x₂`

Subject to:

- `x₁ + 2x₂ ≤ 20`
- `2x₁ + x₂ ≤ 20`
- `x₁, x₂ ≥ 0`

Initial point: `x = [0.1, 0.1, 0.1, 0.1]`

## Achieved results

### Test 1
```
Test #(1/5)
Test# 1 | Interior Point Algo (alpha = 0.5)
-- Input --
1 1 0 0

2 4 1 0
1 3 0 1

2 1 1 -4

0.1
0.5

-- Output --
 Run Interior Point Algorithm with parameters (eps= 0.100 alpha= 0.500):
 Iteratoin 1, x= 3.210 0.500 0.581 -3.710 
 Iteratoin 2, x= 3.801 0.250 0.399 -3.551 
 Iteratoin 3, x= 4.131 0.125 0.237 -3.506 
 Iteratoin 4, x= 4.313 0.062 0.124 -3.500 
 4.313 0.062 0.124 -3.500 
 4.375 
 

Test# 1 | Interior Point Algo (alpha = 0.9)
-- Input --
1 1 0 0

2 4 1 0
1 3 0 1

2 1 1 -4

0.1
0.9

-- Output --
 Run Interior Point Algorithm with parameters (eps= 0.100 alpha= 0.900):
 Iteratoin 1, x= 4.177 0.100 0.245 -3.477 
 Iteratoin 2, x= 4.434 0.027 0.025 -3.514 
 Iteratoin 3, x= 4.487 0.003 0.014 -3.495 
 4.487 0.003 0.014 -3.495 
 4.490 
 

Test# 1 | Simplex method
-- Input --
1 1

2 4
1 3

16 9

0.1

-- Output --
 Normal finish
 z = 8.000000
 Solution: 8.000000 0
```
### Test 2
```
Test #(2/5)
Test# 2 | Interior Point Algo (alpha = 0.5)
-- Input --
-9 2 -4 0 0 0

2 4 1 1 0 0
3 -3 4 0 1 0
5 2 -1 0 0 1

1 3 2 4 5 2

0.1
0.5

-- Output --
 Run Interior Point Algorithm with parameters (eps= 0.100 alpha= 0.500):
 Iteratoin 1, x= 0.500 3.505 1.256 3.726 10.992 2.746 
 Iteratoin 2, x= 0.250 3.856 0.698 3.378 15.026 2.736 
 Iteratoin 3, x= 0.125 4.167 0.350 2.731 17.727 2.390 
 Iteratoin 4, x= 0.065 4.474 0.175 1.798 19.528 1.901 
 Iteratoin 5, x= 0.034 4.732 0.087 0.917 20.743 1.453 
 Iteratoin 6, x= 0.020 4.864 0.047 0.458 21.343 1.222 
 Iteratoin 7, x= 0.011 4.931 0.025 0.229 21.662 1.109 
 Iteratoin 8, x= 0.006 4.965 0.013 0.115 21.829 1.054 
 0.006 4.965 0.013 0.115 21.829 1.054 
 9.829 
 

Test# 2 | Interior Point Algo (alpha = 0.9)
-- Input --
-9 2 -4 0 0 0

2 4 1 1 0 0
3 -3 4 0 1 0
5 2 -1 0 0 1

1 3 2 4 5 2

0.1
0.9

-- Output --
 Run Interior Point Algorithm with parameters (eps= 0.100 alpha= 0.900):
 Iteratoin 1, x= 0.100 3.908 0.660 3.506 15.785 3.343 
 Iteratoin 2, x= 0.060 4.387 0.066 2.267 19.717 1.993 
 Iteratoin 3, x= 0.020 4.922 0.047 0.227 21.517 1.106 
 Iteratoin 4, x= 0.003 4.968 0.005 0.119 21.874 1.054 
 Iteratoin 5, x= 0.002 4.995 0.003 0.012 21.969 1.004 
 0.002 4.995 0.003 0.012 21.969 1.004 
 9.963 
 

Test# 2 | Simplex method
-- Input --
-9 2 -4

2 4 1
3 -3 4
5 2 -1

6 3 7

0.1

-- Output --
 Normal finish
 z = 3.000000
 Solution: 0 1.500000 0 
```
### Test 3
```
Test #(3/5)
Test# 3 | Interior Point Algo (alpha = 0.5)
-- Input --
3 1 0 0

2 1 1 0
1 2 0 1

1 1 1 1

0.1
0.5

-- Output --
 Run Interior Point Algorithm with parameters (eps= 0.100 alpha= 0.500):
 Iteratoin 1, x= 1.318 0.864 0.500 0.955 
 Iteratoin 2, x= 1.508 0.735 0.250 1.023 
 Iteratoin 3, x= 1.658 0.559 0.125 1.223 
 Iteratoin 4, x= 1.827 0.283 0.062 1.607 
 Iteratoin 5, x= 1.909 0.141 0.040 1.808 
 1.909 0.141 0.040 1.808 
 5.869 
 

Test# 3 | Interior Point Algo (alpha = 0.9)
-- Input --
3 1 0 0

2 1 1 0
1 2 0 1

1 1 1 1

0.1
0.9

-- Output --
 Run Interior Point Algorithm with parameters (eps= 0.100 alpha= 0.900):
 Iteratoin 1, x= 1.573 0.755 0.100 0.918 
 Iteratoin 2, x= 1.940 0.111 0.010 1.839 
 Iteratoin 3, x= 1.991 0.011 0.008 1.987 
 1.991 0.011 0.008 1.987 
 5.983 
 

Test# 3 | Simplex method
-- Input --
3 1

2 1
1 2

6 4

0.1

-- Output --
 Normal finish
 z = 9.000000
 Solution: 3.000000 0 
```
### Test 4
```
Test #(4/5)
Test# 4 | Interior Point Algo (alpha = 0.5)
-- Input --
9 10 16 0 0 0

18 15 12 1 0 0
6 4 8 0 1 0
5 3 3 0 0 1

3 2 4 1 0.5 4

0.1
0.5

-- Output --
 Run Interior Point Algorithm with parameters (eps= 0.100 alpha= 0.500):
 Iteratoin 1, x= 1.500 3.489 4.390 0.990 0.425 5.864 
 Iteratoin 2, x= 0.750 4.236 4.583 0.973 0.397 6.795 
 Iteratoin 3, x= 0.375 4.608 4.682 0.944 0.359 7.254 
 Iteratoin 4, x= 0.188 4.792 4.738 0.890 0.301 7.473 
 Iteratoin 5, x= 0.094 4.882 4.774 0.796 0.220 7.564 
 0.094 4.882 4.774 0.796 0.220 7.564 
 126.043 
 

Test# 4 | Interior Point Algo (alpha = 0.9)
-- Input --
9 10 16 0 0 0

18 15 12 1 0 0
6 4 8 0 1 0
5 3 3 0 0 1

3 2 4 1 0.5 4

0.1
0.9

-- Output --
 Run Interior Point Algorithm with parameters (eps= 0.100 alpha= 0.900):
 Iteratoin 1, x= 0.300 4.679 4.702 0.982 0.364 7.355 
 Iteratoin 2, x= 0.030 4.941 4.790 0.853 0.230 7.654 
 Iteratoin 3, x= 0.019 4.959 4.815 0.474 0.023 7.578 
 Iteratoin 4, x= 0.003 5.022 4.797 0.047 0.015 7.527 
 Iteratoin 5, x= 0.001 5.023 4.800 0.030 0.002 7.524 
 0.001 5.023 4.800 0.030 0.002 7.524 
 127.039 
 

Test# 4 | Simplex method
-- Input --
9 10 16

18 15 12
6 4 8
5 3 3

360 192 180

0.1

-- Output --
 Normal finish
 z = 400.000000
 Solution: 0 8.000000 20.000000
```
### Test 5
```
Test #(5/5)
Test# 5 | Interior Point Algo (alpha = 0.5)
-- Input --
-1 1 0 0

1 2 1 0
2 1 0 0

0.1 0.1 0.1 0.1

0.1
0.5

-- Output --
 Run Interior Point Algorithm with parameters (eps= 0.100 alpha= 0.500):
 Iteratoin 1, x= 0.083 0.133 0.050 0.100 
 0.083 0.133 0.050 0.100 
 0.050 
 

Test# 5 | Interior Point Algo (alpha = 0.9)
-- Input --
-1 1 0 0

1 2 1 0
2 1 0 0

0.1 0.1 0.1 0.1

0.1
0.9

-- Output --
 Run Interior Point Algorithm with parameters (eps= 0.100 alpha= 0.900):
 Iteratoin 1, x= 0.070 0.160 0.010 0.100 
 0.070 0.160 0.010 0.100 
 0.090 
 

Test# 5 | Simplex method
-- Input --
-1 1

1 2
2 1

20 20

0.1

-- Output --
 Normal finish
 z = 10.000000
 Solution: 0 10.000000
```
