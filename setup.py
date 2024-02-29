"""
    Copyright 2023 - Anthony Truelove MASc, P.Eng.
    
    Redistribution and use in source and binary forms, with or without modification, are
    permitted provided that the following conditions are met:
    
    1. Redistributions of source code must retain the above copyright notice, this list of
    conditions and the following disclaimer.
    
    2. Redistributions in binary form must reproduce the above copyright notice, this list
    of conditions and the following disclaimer in the documentation and/or other materials
    provided with the distribution.
    
    3. Neither the name of the copyright holder nor the names of its contributors may be
    used to endorse or promote products derived from this software without specific prior
    written permission.
    
    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
    MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
    THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
    OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
    HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
    TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
"""

"""
    Anthony Truelove MASc, P.Eng.  
    email:   wtruelove@uvic.ca
    github:  gears1763-2 

    A setup file for generating Python3 bindings for the ProteusDS API. To invoke, simply
    
    >  python(3) setup.py build_ext --inplace --compiler=msvc
    
    depending on your set up.
    
    ref: https://pybind11.readthedocs.io/en/stable/compiling.html
    ref: https://github.com/pybind/pybind11/
    ref: https://discuss.python.org/t/is-there-a-way-that-the-shared-libraries-needed-by-pybind11-can-be-found-at-runtime/41341
    
    Note that this file is not position independent, but assumes that it has been placed in
    `.../ProteusDS/API/Bindings/Python3`. If you move it somewhere else, you will need to update the
    `library_dirs` attribute of the `Pybind11Extension` accordingly. You may also need to update the 
    `source_list` accordingly.
"""


import os
import shutil

from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension


# generate list of source files
source_list = ["PYBIND11_ProteusDSAPI.cpp"]


# generate list of pybind11 extensions
ext_modules = [
    Pybind11Extension(
        "ProteusDSAPI",
        sources=source_list,
        libraries=["ProteusDSAPI-vc141-md-x64"],
        library_dirs=["../../lib"],
        language="c++",
        cxx_std=17
    )
]


# set up extensions
setup(
    name="ProteusDSAPI",
    ext_modules=ext_modules,
    zip_safe=False,
    python_requires=">=3.7",
    install_requires=["setuptools>=42", "pybind11>=2.6.1"]
)


# clean up
for root, dirs, files in os.walk(os.getcwd()):
    for name in dirs:
        if "build" in name:
            shutil.rmtree(name)
