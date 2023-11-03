# MagicCompare: Chained Comparisons in C++

## Table of Contents

- [Introduction](#introduction)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Build and test](#build and test)
- [Usage](#usage)
- [License](#license)

## Introduction

When working with mathematics, we often use chained comparisons, such as `a < b < c`. However, in most programming languages, including C++, this kind of comparison is not supported out of the box. You would typically write cumbersome expressions like `a < b && b < c` instead of the more intuitive `a < b < c`.

In C++, you might be tempted to use `a < b < c`, but it doesn't work as expected. Instead, it first evaluates `a < b`, which results in a bool value, and then converts it to 0 or 1. This leads to incorrect behavior, where `3 > 4 < 5` would be `false < 5`, resulting in `0 < 5`, which evaluates to `true`, rather than the expected `false`.

To address this issue, we've created a C++ solution called MagicCompare, which leverages operator overloading to enable correctly working chained comparisons.

Idea comes from: https://www.codewars.com/kata/59ad0147485a4d9d3f0000a9

## Getting Started

### Prerequisites

- A C++ compiler with C++11 support.

### Build and test

1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/holyhgrenade/MagicCompare.git
   
2. Navigate to the project directory:

   ```bash
   cd MagicCompare

3. Build the project

   ```bash
   mkdir build
   cd build
   cmake ..
   make

4. Execute tests

   ```bash
   make test

### Usage

To use MagicCompare, you'll need to include the MagicCompare.h header in your C++ code. The header-only class is located in the src folder. You can then create objects of your existing types and use the MagicCompare class to perform chained comparisons in a more intuitive manner.
For examples please check the tests.

### License

This project is licensed under the MIT License - see the LICENSE file for details.
