:: ================================ ::
::
::  Anthony Truelove MASc, P.Eng.  
::  email:   wtruelove@uvic.ca
::  github:  gears1763-2 
::
::  Batch file to handle 
::      
::      1. The set up of an MSVC v141 (v14.16) - VS 2017 C++ x64/x86 (Windows SDK 10.0.20348.0) environment.
::         This is important as MSVC v141 is specifically required to work with the API.
::
::      2. The building of Python3 bindings for the ProteusDS API (by way of the corresponding setup.py).
::
::  For this to work under your specific Visual Studio install, adjust the PATH_2_VCVARSALL variable as
::  necessary. There must be a better way to make this more portable? Perhaps there's already an 
::  environment variable for what I'm calling PATH_2_VCVARSALL here (or at lease for part of that
::  path)??
::
::  ref: https://stackoverflow.com/questions/50830609/run-cl-exe-from-cmd
::
:: ================================ ::


set PATH_2_VCVARSALL="C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall"

%PATH_2_VCVARSALL% x64 10.0.20348.0 -vcvars_ver=14.16 && python setup.py build_ext --inplace --compiler=msvc
