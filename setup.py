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
