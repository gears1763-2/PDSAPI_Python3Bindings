/*
 *  Copyright 2023 - Anthony Truelove MASc, P.Eng.
 *
 *  Redistribution and use in source and binary forms, with or without modification, are
 *  permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice, this list of
 *  conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright notice, this list
 *  of conditions and the following disclaimer in the documentation and/or other materials
 *  provided with the distribution.
 *
 *  3. Neither the name of the copyright holder nor the names of its contributors may be
 *  used to endorse or promote products derived from this software without specific prior
 *  written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND ANY
 *  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
 *  THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 *  OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 *  TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

/*
 *  Anthony Truelove MASc, P.Eng.  
 *  email:   wtruelove@uvic.ca
 *  github:  gears1763-2 
 *
 *  Source file for generating Python3 bindings for the ProteusDS API.
 *
 *  ref: https://pybind11.readthedocs.io/en/stable/basics.html
 *  ref: https://pybind11.readthedocs.io/en/stable/classes.html
 *
 *  Note that this file is not position independent, but assumes that it has been placed in
 *  `...\ProteusDS\API\Bindings\Python3`. If you move it somewhere else, you will need to update the 
 *  `ProteusDSAPI.h` include accordingly.
 */


///
/// \file PYBIND11_ProteusDSAPI.cpp
///
/// \brief Implementation file for generating some wrapper functions and bindings, by
///        way of pybind11.
///
/// Implementation file for generating some wrapper functions and bindings, by way of
/// pybind11.
///


#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "../../include/ProteusDSAPI.h"


// ==== Get wrappers =================================================================================== //

/*
 *  This wrapping scheme is necessary because Python is neither pass by reference nor pass by 
 *  value, but is instead "pass by assignment" (ref: https://realpython.com/python-pass-by-reference/).
 *  So, to get the functionality intended by the apparent pass-by-reference and then update-in-place
 *  implementation of the API Get functions, one needs to write C++ wrappers to be bound instead of the 
 *  Get functions themselves. To work with Python, they need to return the get!
 */

// ----------------------------------------------------------------------------------------------------- //

///
/// \fn std::vector<double> GetDoubleArray(
///         std::string unique_simulation_label,
///         int command,
///         std::string dobject_name,
///         size_t n_elements
///     )
///
/// \brief Wrapper on ProteusDSAPI::GetDoubleArray that creates and returns the desired
///     std::vector<double>.
///
/// \param unique_simulation_label The API label for the target simulation.
///
/// \param command Defines the attribute of interest (resolved by the PDSAPI::PDSAPI 
///     enumeration).
///
/// \param dobject_name Defines the dobject of interest.
///
/// \param n_elements Defines the size of the std::vector<double> to be returned.
///
/// \return The desired std::vector<double>.
///

std::vector<double> GetDoubleArray(
    std::string unique_simulation_label,
    int command,
    std::string dobject_name,
    size_t n_elements
)
{
    std::vector<double> return_vector(n_elements, 0);
    ProteusDSAPI::GetDoubleArray(unique_simulation_label, command, dobject_name, return_vector);
    
    return return_vector;
}   /* GetDoubleArray() */

// ----------------------------------------------------------------------------------------------------- //



// ----------------------------------------------------------------------------------------------------- //

///
/// \fn double GetDouble(
///         std::string unique_simulation_label,
///         int command,
///         std::string dobject_name
///     )
///
/// \brief Wrapper on ProteusDSAPI::GetDouble that creates and returns the desired
///     double.
///
/// \param unique_simulation_label The API label for the target simulation.
///
/// \param command Defines the attribute of interest (resolved by the PDSAPI::PDSAPI 
///     enumeration).
///
/// \param dobject_name Defines the dobject of interest.
///
/// \return The desired double.
///

double GetDouble(
    std::string unique_simulation_label,
    int command,
    std::string dobject_name
)
{
    double return_double = 0;
    ProteusDSAPI::GetDouble(unique_simulation_label, command, dobject_name, return_double);
    
    return return_double;
}   /* GetDouble() */

// ----------------------------------------------------------------------------------------------------- //



// ----------------------------------------------------------------------------------------------------- //

///
/// \fn std::vector<double> GetIntArray(
///         std::string unique_simulation_label,
///         int command,
///         std::string dobject_name,
///         size_t n_elements
///     )
///
/// \brief Wrapper on ProteusDSAPI::GetIntArray that creates and returns the desired
///     std::vector<int>.
///
/// \param unique_simulation_label The API label for the target simulation.
///
/// \param command Defines the attribute of interest (resolved by the PDSAPI::PDSAPI 
///     enumeration).
///
/// \param dobject_name Defines the dobject of interest.
///
/// \param n_elements Defines the size of the std::vector<int> to be returned.
///
/// \return The desired std::vector<int>.
///

std::vector<int> GetIntArray(
    std::string unique_simulation_label,
    int command,
    std::string dobject_name,
    size_t n_elements
)
{
    std::vector<int> return_vector(n_elements, 0);
    ProteusDSAPI::GetIntArray(unique_simulation_label, command, dobject_name, return_vector);
    
    return return_vector;
}   /* GetIntArray() */

// ----------------------------------------------------------------------------------------------------- //



// ----------------------------------------------------------------------------------------------------- //

///
/// \fn double GetInt(
///         std::string unique_simulation_label,
///         int command,
///         std::string dobject_name
///     )
///
/// \brief Wrapper on ProteusDSAPI::GetInt that creates and returns the desired
///     int.
///
/// \param unique_simulation_label The API label for the target simulation.
///
/// \param command Defines the attribute of interest (resolved by the PDSAPI::PDSAPI 
///     enumeration).
///
/// \param dobject_name Defines the dobject of interest.
///
/// \return The desired int.
///

double GetInt(
    std::string unique_simulation_label,
    int command,
    std::string dobject_name
)
{
    int return_int = 0;
    ProteusDSAPI::GetInt(unique_simulation_label, command, dobject_name, return_int);
    
    return return_int;
}   /* GetInt() */

// ----------------------------------------------------------------------------------------------------- //



// ----------------------------------------------------------------------------------------------------- //

///
/// \fn double GetString(
///         std::string unique_simulation_label,
///         int command,
///         std::string dobject_name
///     )
///
/// \brief Wrapper on ProteusDSAPI::GetString that creates and returns the desired
///     std::string.
///
/// \param unique_simulation_label The API label for the target simulation.
///
/// \param command Defines the attribute of interest (resolved by the PDSAPI::PDSAPI 
///     enumeration).
///
/// \param dobject_name Defines the dobject of interest.
///
/// \return The desired std::string.
///

std::string GetString(
    std::string unique_simulation_label,
    int command,
    std::string dobject_name
) 
{
    std::string return_string = "";
    ProteusDSAPI::GetString(unique_simulation_label, command, dobject_name, return_string);
    
    return return_string;
}   /* GetString() */

// ----------------------------------------------------------------------------------------------------- //



// ----------------------------------------------------------------------------------------------------- //

///
/// \fn std::string GetErrorMessage(std::string unique_simulation_label)
///
/// \brief Wrapper on ProteusDSAPI::GetErrorMessage that creates and returns the desired
///     std::string (i.e., the error message).
///
/// \param unique_simulation_label The API label for the target simulation.
///
/// \return The desired error message (std::string).
///

std::string GetErrorMessage(std::string unique_simulation_label)
{
    std::string error_message = "";
    ProteusDSAPI::GetErrorMessage(unique_simulation_label, error_message);
    
    return error_message;
}   /* GetErrorMessage() */

// ----------------------------------------------------------------------------------------------------- //

// ==== END Get wrappers =============================================================================== //



// ==== Bindings ======================================================================================= //

PYBIND11_MODULE(ProteusDSAPI, m) {
    
    // ---- Bindings for PDSAPI.h ---------------------------------------------------------------------- //
    
    pybind11::enum_<PDSAPI::PDSAPI>(m, "PDSAPI")
        // general parameters
        .value("state", PDSAPI::PDSAPI::state)
        .value("stateSize", PDSAPI::PDSAPI::stateSize)
        .value("time", PDSAPI::PDSAPI::time)
        .value("simulationRunning", PDSAPI::PDSAPI::simulationRunning)
        .value("licenseInfo", PDSAPI::PDSAPI::licenseInfo)
        .value("fileOutputOn", PDSAPI::PDSAPI::fileOutputOn)
        .value("fileOutputOff", PDSAPI::PDSAPI::fileOutputOff)
        
        // simulation parameters 
        .value("numberOfDObjects", PDSAPI::PDSAPI::numberOfDObjects)
        .value("dObjectNames", PDSAPI::PDSAPI::dObjectNames)
        .value("dObjectTypes", PDSAPI::PDSAPI::dObjectTypes)
        .value("version", PDSAPI::PDSAPI::version)
        .value("outputRestartPath", PDSAPI::PDSAPI::outputRestartPath)
    
        // environment parameters
        .value("environmentWaveReferenceHeight", PDSAPI::PDSAPI::environmentWaveReferenceHeight)
        .value("environmentWaveReferencePeriod", PDSAPI::PDSAPI::environmentWaveReferencePeriod)
        .value("environmentWaveReferenceHeading", PDSAPI::PDSAPI::environmentWaveReferenceHeading)
        .value("environmentWaveType", PDSAPI::PDSAPI::environmentWaveType)
        .value("environmentWaveSegments", PDSAPI::PDSAPI::environmentWaveSegments)
        .value("environmentWaveSeed", PDSAPI::PDSAPI::environmentWaveSeed)
        .value("environmentTransitionTime", PDSAPI::PDSAPI::environmentTransitionTime)
        .value("environmentTransitionRampTime", PDSAPI::PDSAPI::environmentTransitionRampTime)
        .value("environmentCurrentProfileDepth", PDSAPI::PDSAPI::environmentCurrentProfileDepth)
        .value("environmentCurrentProfileSpeed", PDSAPI::PDSAPI::environmentCurrentProfileSpeed)
        .value("environmentCurrentProfileHeading", PDSAPI::PDSAPI::environmentCurrentProfileHeading)
        .value("environmentSeaHeight", PDSAPI::PDSAPI::environmentSeaHeight)
        
        // cable parameters
        .value("cableTensions", PDSAPI::PDSAPI::cableTensions)
        .value("cableTensionNumberOfSamplePoints", PDSAPI::PDSAPI::cableTensionNumberOfSamplePoints)
        .value("cableNumberOfElements", PDSAPI::PDSAPI::cableNumberOfElements)
        .value("cableNumberOfNodes", PDSAPI::PDSAPI::cableNumberOfNodes)
        .value("cableBendingRadiusNumberOfSamplePoints", PDSAPI::PDSAPI::cableBendingRadiusNumberOfSamplePoints)
        .value("cableBendingRadius", PDSAPI::PDSAPI::cableBendingRadius)
        .value("cablePayoutSpeedNodeN", PDSAPI::PDSAPI::cablePayoutSpeedNodeN)
        .value("cablePayoutSpeedNode0", PDSAPI::PDSAPI::cablePayoutSpeedNode0)
        .value("cablePositionNodeN", PDSAPI::PDSAPI::cablePositionNodeN)
        .value("cablePositionNode0", PDSAPI::PDSAPI::cablePositionNode0)
        .value("cableVelocityNodeN", PDSAPI::PDSAPI::cableVelocityNodeN)
        .value("cableVelocityNode0", PDSAPI::PDSAPI::cableVelocityNode0)
        .value("cableNodeNClamped", PDSAPI::PDSAPI::cableNodeNClamped)
        .value("cableP1NodeN", PDSAPI::PDSAPI::cableP1NodeN)
        .value("cableP2NodeN", PDSAPI::PDSAPI::cableP2NodeN)
        .value("cableNode0Clamped", PDSAPI::PDSAPI::cableNode0Clamped)
        .value("cableP1Node0", PDSAPI::PDSAPI::cableP1Node0)
        .value("cableP2Node0", PDSAPI::PDSAPI::cableP2Node0)
        .value("cableTanNode0", PDSAPI::PDSAPI::cableTanNode0)
        .value("cableTanNodeN", PDSAPI::PDSAPI::cableTanNodeN)
        .value("cableVonMisesNumberOfSamplePoints", PDSAPI::PDSAPI::cableVonMisesNumberOfSamplePoints)
        .value("cableTemperaturesNumberOfSamplePoints", PDSAPI::PDSAPI::cableTemperaturesNumberOfSamplePoints)
        .value("cableVonMisesStress", PDSAPI::PDSAPI::cableVonMisesStress)
        .value("cableVonMisesRGB", PDSAPI::PDSAPI::cableVonMisesRGB)
        .value("cableVonMisesRGBMinStress", PDSAPI::PDSAPI::cableVonMisesRGBMinStress)
        .value("cableVonMisesRGBMaxStress", PDSAPI::PDSAPI::cableVonMisesRGBMaxStress)
        .value("cableVonMisesNumberOfRadialSamplePoints", PDSAPI::PDSAPI::cableVonMisesNumberOfRadialSamplePoints)
        .value("cableTemperatures", PDSAPI::PDSAPI::cableTemperatures)
        .value("cableTemperaturesRGB", PDSAPI::PDSAPI::cableTemperaturesRGB)
        .value("cableTemperaturesRGBMinTemp", PDSAPI::PDSAPI::cableTemperaturesRGBMinTemp)
        .value("cableTemperaturesRGBMaxTemp", PDSAPI::PDSAPI::cableTemperaturesRGBMaxTemp)
        .value("cablePositionsNumberOfSamplePoints", PDSAPI::PDSAPI::cablePositionsNumberOfSamplePoints)
        .value("cablePositions", PDSAPI::PDSAPI::cablePositions)
        .value("cableNode0ReactionLoad", PDSAPI::PDSAPI::cableNode0ReactionLoad)
        .value("cableNodeNReactionLoad", PDSAPI::PDSAPI::cableNodeNReactionLoad)
        .value("cableNode0AverageReactionLoad", PDSAPI::PDSAPI::cableNode0AverageReactionLoad)
        .value("cableNodeNAverageReactionLoad", PDSAPI::PDSAPI::cableNodeNAverageReactionLoad)
        .value("cableFlexuralStressNumberOfSamplePoints", PDSAPI::PDSAPI::cableFlexuralStressNumberOfSamplePoints)
        .value("cableFlexuralStress", PDSAPI::PDSAPI::cableFlexuralStress)
        .value("cableLength", PDSAPI::PDSAPI::cableLength)
        
        // rigid body parameters
        .value("rigidBodyPosition", PDSAPI::PDSAPI::rigidBodyPosition)
        .value("rigidBodyVelocityGlobal", PDSAPI::PDSAPI::rigidBodyVelocityGlobal)
        .value("rigidBodyVelocityBody", PDSAPI::PDSAPI::rigidBodyVelocityBody)
        .value("rigidBodyAccelerationGlobal", PDSAPI::PDSAPI::rigidBodyAccelerationGlobal)
        .value("rigidBodyAccelerationBody", PDSAPI::PDSAPI::rigidBodyAccelerationBody)
        .value("rigidBodyAngularAccelerationBody", PDSAPI::PDSAPI::rigidBodyAngularAccelerationBody)
        .value("rigidBodyOrientation", PDSAPI::PDSAPI::rigidBodyOrientation)
        .value("rigidBodyAngularVelocityBody", PDSAPI::PDSAPI::rigidBodyAngularVelocityBody)
        .value("rigidBodyMooringLoads", PDSAPI::PDSAPI::rigidBodyMooringLoads)
        .value("rigidBodyForceKinControl", PDSAPI::PDSAPI::rigidBodyForceKinControl)
        .value("rigidBodyState", PDSAPI::PDSAPI::rigidBodyState)
        .value("rigidBodyForceAndDerivGlobal", PDSAPI::PDSAPI::rigidBodyForceAndDerivGlobal)
        .value("rigidBodyForceAndDerivBody", PDSAPI::PDSAPI::rigidBodyForceAndDerivBody)
        .value("rigidBodyMomentAndDerivGlobal", PDSAPI::PDSAPI::rigidBodyMomentAndDerivGlobal)
        .value("rigidBodyMomentAndDerivBody", PDSAPI::PDSAPI::rigidBodyMomentAndDerivBody)
        .value("rigidBodyJointForceAndDeriv", PDSAPI::PDSAPI::rigidBodyJointForceAndDeriv)
        .value("rigidBodyClearForcesMoments", PDSAPI::PDSAPI::rigidBodyClearForcesMoments)
        .value("rigidBodyThrusterRPMSetpoint", PDSAPI::PDSAPI::rigidBodyThrusterRPMSetpoint)
        .value("rigidBodyThrusterAzimuthSetpoint", PDSAPI::PDSAPI::rigidBodyThrusterAzimuthSetpoint)
        
        // set functions for RAO mode
        .value("rigidBodyRAOHeading", PDSAPI::PDSAPI::rigidBodyRAOHeading)
        .value("rigidBodyRAOHeadingSpeedDegreesPerSecond", PDSAPI::PDSAPI::rigidBodyRAOHeadingSpeedDegreesPerSecond)
        .value("rigidBodyRAOPositionNorth", PDSAPI::PDSAPI::rigidBodyRAOPositionNorth)
        .value("rigidBodyRAOPositionEast", PDSAPI::PDSAPI::rigidBodyRAOPositionEast)
        .value("rigidBodyRAOSpeedNorth", PDSAPI::PDSAPI::rigidBodyRAOSpeedNorth)
        .value("rigidBodyRAOSpeedEast", PDSAPI::PDSAPI::rigidBodyRAOSpeedEast)
        .value("rigidBodyRAOForwardSpeed", PDSAPI::PDSAPI::rigidBodyRAOForwardSpeed)
        .value("rigidBodyRelativeFluidVelocityProbes", PDSAPI::PDSAPI::rigidBodyRelativeFluidVelocityProbes)
        .value("rigidBodyAbsFluidVelocityProbes", PDSAPI::PDSAPI::rigidBodyAbsFluidVelocityProbes)
        
        // DCable parameters
        .value("dCableMovementControllerSetPoint", PDSAPI::PDSAPI::dCableMovementControllerSetPoint)
        .value("dCableMovementControllerMaxControlForce", PDSAPI::PDSAPI::dCableMovementControllerMaxControlForce)
        .value("dCableMovementControllerOn", PDSAPI::PDSAPI::dCableMovementControllerOn)
        .value("dCableMovementControllerArclength", PDSAPI::PDSAPI::dCableMovementControllerArclength)
        .value("dCableMovementControllerTargetVelocity", PDSAPI::PDSAPI::dCableMovementControllerTargetVelocity)
        .value("dCableMovementControllerSetPointRelative", PDSAPI::PDSAPI::dCableMovementControllerSetPointRelative)
        .value("dCableMovementControllerDCablePosition", PDSAPI::PDSAPI::dCableMovementControllerDCablePosition)
        .value("dCableMovementControllerVelocityControlOn", PDSAPI::PDSAPI::dCableMovementControllerVelocityControlOn);
    
    // ---- END Bindings for PDSAPI.h ------------------------------------------------------------------ //
    
    
    
    // ---- Bindings for ProteusDSAPI.h (C++) ---------------------------------------------------------- //
    
    // this initializes ProteusDS using command line parameters
    m.def("InitializeProteusDS", &(ProteusDSAPI::InitializeProteusDS));
    
    // this terminates the ProteusDS simulation
    m.def("Close", &(ProteusDSAPI::Close));
    
    // this moves the ProteusDS simulation ahead by dt (finite) seconds
    m.def("AdvanceTime", &(ProteusDSAPI::AdvanceTime));
    
    // this provides an interface for DObject interaction
    m.def("GetDoubleArray", &(GetDoubleArray));
    m.def("GetDouble", &(GetDouble));
    m.def("GetIntArray", &(GetIntArray));
    m.def("GetInt", &(GetInt));
    m.def("GetString", &(GetString));
    m.def("GetErrorMessage", &(GetErrorMessage));
    
    m.def("SetDoubleArray", &(ProteusDSAPI::SetDoubleArray));
    m.def("SetDouble", &(ProteusDSAPI::SetDouble));
    m.def("SetIntArray", &(ProteusDSAPI::SetIntArray));
    m.def("SetInt", &(ProteusDSAPI::SetInt));
    m.def("SetString", &(ProteusDSAPI::SetString));
    
    // this provides an interface to the experimental custom cable commands
    m.def("DisconnectCable", &(ProteusDSAPI::DisconnectCable));
    m.def("MakeDCableDCablePointConnection", &(ProteusDSAPI::MakeDCableDCablePointConnection));
    m.def("SetCableEndNodeKinematicMode", &(ProteusDSAPI::SetCableEndNodeKinematicMode));
    
    // ---- END Bindings for ProteusDSAPI.h (C++) ------------------------------------------------------ //

}   /* PYBIND11_MODULE() */

// ==== END Bindings =================================================================================== //
