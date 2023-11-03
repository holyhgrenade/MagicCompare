# MagicCompare: Chained Comparisons in C++

## Table of Contents

- [Introduction](#introduction)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Example](#example)
- [Tests](#tests)
- [Contributing](#contributing)
- [License](#license)

## Introduction

When working with mathematics, we often use chained comparisons, such as `a < b < c`. However, in most programming languages, including C++, this kind of comparison is not supported out of the box. You would typically write cumbersome expressions like `a < b && b < c` instead of the more intuitive `a < b < c`.

In C++, you might be tempted to use `a < b < c`, but it doesn't work as expected. Instead, it first evaluates `a < b`, which results in a bool value, and then converts it to 0 or 1. This leads to incorrect behavior, where `3 > 4 < 5` would be `false < 5`, resulting in `0 < 5`, which evaluates to `true`, rather than the expected `false`.

To address this issue, we've created a C++ solution called MagicCompare, which leverages operator overloading to enable correctly working chained comparisons.

## Getting Started

### Prerequisites

- A C++ compiler with C++11 support.

### Installation

1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/holyhgrenade/your-repo.git

