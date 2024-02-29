:: ================================ ::
::
:: Copyright 2023 - Anthony Truelove MASc, P.Eng.
::
:: Redistribution and use in source and binary forms, with or without modification, are
:: permitted provided that the following conditions are met:
::
:: 1. Redistributions of source code must retain the above copyright notice, this list of
:: conditions and the following disclaimer.
::
:: 2. Redistributions in binary form must reproduce the above copyright notice, this list
:: of conditions and the following disclaimer in the documentation and/or other materials
:: provided with the distribution.
::
:: 3. Neither the name of the copyright holder nor the names of its contributors may be
:: used to endorse or promote products derived from this software without specific prior
:: written permission.
::
:: THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND ANY
:: EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
:: MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
:: THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
:: SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
:: OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
:: HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
:: TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
:: SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
::
:: ================================ ::

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
