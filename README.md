# Python3 Bindings for the ProteusDS API

    Anthony Truelove MASc, P.Eng.  
    email:   wtruelove@uvic.ca
    github:  gears1763-2 
    
This project provides the infrastructure for building Python3 bindings for the ProteusDS API, given only
the `.h`, `.dll`, `.lib` files that ship with the latest version of ProteusDS. In addition, a minimal
working example is provided (namely, the `3-Joint_damping` example, as laid out in the API C++ samples).

--------


## Contents

In the directory for this project, you should find this `README.md`, a `LICENSE.md`, a `build_python_bindings.bat`, 
a `JointDampingExample.py`, a `PYBIND11_ProteusDSAPI.cpp`, a `setup.py`, and the following sub-directories

    Inputs/     For holding the ProteusDS input files for the joint damping example

--------


## Setup

This project makes use of `pybind11` (see <https://pybind11.readthedocs.io/en/stable/basics.html>) and
`setuptools` (see <https://pybind11.readthedocs.io/en/stable/basics.html>) to build the bindings. This 
is achieved through the interaction of three key files; namely 

  * `build_python_bindings.bat` 
  
  * `PYBIND11_ProteusDSAPI.cpp`
  
  * `setup.py`

To actually build the bindings, all you should need to do is open a command prompt in the project 
directory, and then invoke the batch file; that is

    C:\...\ProteusDS\API\Bindings\Python3>build_python_bindings.bat
    
The result should be a `ProteusDSAPI.cp3XX-win_amd64.pyd` file (or similar). Note that the generated
bindings are Python version specific! (That's the `cp3XX` part of the file name.) For example, bindings
built for Python 3.7 will not work under Python 3.12 and vice versa. The most portable solution
would be to provide the user with the infrastructure to build bindings for their specific Python version,
rather than pre-building for a specific version and just providing that.

Of course, for this to work, you need to

  * Have a licensed copy of ProteusDS + API installed on your system (as available from <https://proteusds.com/proteusds-api-toolset/>).

  * Have Python for Windows installed (as available from <https://www.python.org/downloads/>; Python3.7+ should suffice).
  
  * Have Visual Studio 2017 installed (as available from <https://visualstudio.microsoft.com/downloads/>; the community edition is fine). Specifically, you need MSVC v141 and SDK 10.0.20348.0.
  
  * Have `pybind11` installed (just `pip install pybind11`).
  
  * Have `setuptools` installed (just `pip install setuptools`).

Some file-specific notes follow.


### `build_python_bindings.bat`

This is a batch file which handles the following

  * Sets up an MSVC environment which uses a compiler/linker/SDK version compatible with the ProteusDS API (namely MSVC v141, SDK 10.0.20348.0).
  
  * Invokes setuptools to build the bindings.

You may need to adjust the `PATH_2_VCVARSALL` variable to reflect where Visual Studio is installed on your
system. In any case, *you should be installing Visual Studio to the default location*; this is necessary
for `setuptools` to find it!


### `PYBIND11_ProteusDSAPI.cpp`

This is a source file which tells `pybind11` how to build the bindings. Specifically, it defines the 
desired interface on the Python side and relates that to the interface provided by the ProteusDS API
(as defined in the corresponding header files).

Note that the API Get functions required wrapping in order to work with Python (see
`PYBIND11_ProteusDSAPI.cpp` for a brief explanation).  

Note that this file is not position independent, but assumes that it has been placed in
`...\ProteusDS\API\Bindings\Python3`. If you move it somewhere else, you will need to update the 
`ProteusDSAPI.h` include accordingly.


### `setup.py`

This is a Python script which instructs `setuptools` in compiling and linking the bindings.

Note that this file is not position independent, but assumes that it has been placed in
`...\ProteusDS\API\Bindings\Python3`. If you move it somewhere else, you will need to update the
`library_dirs` attribute of the `Pybind11Extension` accordingly. You may also need to update the 
`source_list` accordingly.

--------


## Testing

Once the bindings have been successfully built, you can run the minimal working example (found in 
`JointDamingExample.py`) simply by invoking

    C:\...\ProteusDS\API\Bindings\Python3>python JointDampingExample.py
    
A running print should appear in the command prompt, and a `Results/` folder should be created and
populated with simulation outputs.


This project was successfully tested on the following OS and architecture:

    Operating System: Windows 11 Pro
             Version: Build 22621.ni_release.220506-1250
        Architecture: 64-bit OS, x64-based processor

The following compiler/linker/SDK was used in testing

    Microsoft (R) C/C++ Optimizing Compiler Version 19.16.27051 for x64
    Microsoft (R) Incremental Linker Version 14.16.27051.0
    SDK 10.0.20348.0

The Python version used was 3.12.0.

    
