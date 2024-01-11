/*
 *  Anthony Truelove MASc, P.Eng.
 *  email:  wtruelove@uvic.ca
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
