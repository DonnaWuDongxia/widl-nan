[![Build Status](https://travis-ci.org/01org/widl-nan.svg?branch=master)](https://travis-ci.org/01org/widl-nan)

# Purpose

This toolchain transcompiles [W3C Web IDL](https://heycam.github.io/webidl/) to the [NAN](https://github.com/nodejs/nan) C++ code. This tool improve efficiency of [Node.js Addon](https://nodejs.org/api/addons.html) developing, allows developers focus on spec definition and actual implementation codes.

This bindings code is highly repetitive, primarily passing values (arguments and return values) between V8 and native and doing various conversions and checks (e.g., type checking), hence it is mostly machine-generated.

# Quick Start
### Init workspace
```
npm init
```
### Install widl-nan
```
npm install --save ssh://git@github.com/01org/widl-nan.git
```
### Getting inputs ready
Before using WIDL-NAN, you need to get the inputs ready. Designed addon interfaces need to be defined into [WIDL](https://heycam.github.io/webidl/) format. We leveraged [webidl2](https://www.npmjs.com/package/webidl2) tool to parse Web IDL files to Abstract Syntax Tree(AST). So all supported WIDL features by WIDL-NAN are compliant with [webidl2](https://www.npmjs.com/package/webidl2/).
Refer to [Getting inputs ready](https://github.com/DonnaWuDongxia/widl-nan/blob/sdl/Inputs%20and%20outputs.md#getting-inputs-ready) for more details.

### Compile WIDL files using widl-nan
All supported command-line options of widl-nan can be listed in the help information by ```-h``` argument.

```
./node_modules/.bin/widl-nan -h
  Usage: widl-nan [optinos] [widl] [widl...]

  Options:

    -h, --help        output usage information
    -V, --version     output the version number
    -c, --clean       Cleanup generated codes
    -d, --dest [dir]  Destination directory of generated C++ code
    -i, --init        Init workspace with impl and project files
    -o, --override    Allow override impl files unconditionally
```

You can generate the initial NAN interfaces and C++ implementation for these interfaces by the instruction below.

```
./node_modules/.bin/widl-nan <widl_file_1> <widl_file_2> ...
```

### Leverage the C++ implementaion
All generated files lay in a new folder called ```gen``` in current directory. NAN wrappers locate directly in the ```gen``` folder, while the C++ implementations locate in a subfolder called ```dont-build```.

You can of cause work on native implementations from scratch, but these C++ implementations are good basis of counterpart classes' and members' definition to the NAN interfaces. They can help you a lot, and we recommend to start work based on them.

What's more, we have a command-line option ```-i``` helping to put all C++ implementations, the entry file ```addon.cpp``` and the build file ```binding.gyp``` to the right place to make it a template Node.js addon project. 

```
./node_modules/.bin/widl-nan -i
```

### Build the addon
Given WIDL files, after running two commands mentioned above, you can got a buildable Node.js addon project. The project can be build by following instruction.

```
node-gyp rebuild
```
Now with the excutable addon, you can test it and all the defined interfaces should show up. With this basic project, you can modify files to add your own logics.

[Note] The tool can generate WIDL files to NAN wrappers and C++ implementations, but it has no ability to identify the code you have modified or added. So if WIDL files changed, and you ran steps above again in the same directory, all the files with same path and name will be replaced.

# Contribution

## Coding style guideline

We're following [Chromium coding style](https://chromium.googlesource.com/chromium/src/+/master/styleguide/styleguide.md) for different languages: [C++](https://chromium.googlesource.com/chromium/src/+/master/styleguide/c++/c++.md), [Python](https://google.github.io/styleguide/pyguide.html) and [JavaScript](https://google.github.io/styleguide/javascriptguide.xml). Please run style checker `python ./tools/lint.py` before submitting your code. [depot_tools](https://www.chromium.org/developers/how-tos/install-depot-tools) need to be installed and added to `PATH` env.

## Commit message guideline
A comprehensive commit message will help reviewer to understand what your PR is trying to resolve. There are lots of article to share experience how to write a good commit message, please Google them or check any commit message on mature projects. For eg: https://cs.chromium.org/

To close a related issue, we highly suggest to use [Closing issues via commit messages](https://help.github.com/articles/closing-issues-via-commit-messages/) format, for eg: Fixes.

# Security
If you would like to report a security issue, or have other security related questions, please email [the team](mailto:otc.prc.web.runtime.and.technology.team@intel.com).

# License

The MIT License (MIT)

Copyright (c) 2016 Intel Corporation. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
