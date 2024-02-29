"""
    Anthony Truelove MASc, P.Eng.  
    email:   wtruelove@uvic.ca
    github:  gears1763-2 
    
    Testing the Python3 bindings for the ProteusDS API (it's the 3-Joint_damping C++ sample).
    
    ref: https://stackoverflow.com/questions/58612306/how-to-fix-importerror-dll-load-failed-while-importing-win32api
    ref: https://stackoverflow.com/questions/214852/python-module-dlls
    
    Note that this script is not position independent, but assumes that it has been placed in
    `.../ProteusDS/API/Bindings/Python3`. If you move it somewhere else, then you will need to 
    either (a) update the `import os` block to point to the .dll directory, or (b) copy the .dlls 
    into the working directory for this script.
"""

"""
    3 - Joint Damping Example
    -------------------------
    
    Based on the provided '.../APISamples/C++/3-Joint_damping'.
    
    In this example, we set up a simple WEC device that drives a hydraulic piston/cylinder. First, a normal
    ProteusDS set of init file were created from start to finish using PST.  The ABA joint connection 
    CJoint damping coefficients were purposefully left blank. The project init files can be opened and 
    modified using PST. 
    
    The idea for this example is to model the damping forces for the piston/cylinder externally to 
    ProteusDS. The system is set up using RigidBody ABA connections. The hydraulic piston joint actuation
    rate is extracted from the simulation and used in a resistive force model. The computed resistive force
    is then applied to the piston.  This allows a PDS API user to use an external damping model.
"""

import numpy as np  # <-- this is just to get a "std::vector<>-like" structure in Python

import os
API_lib_path = os.path.abspath(os.getcwd()).split(os.path.sep)[0:-2]
API_lib_path.append("lib")
API_lib_path = os.path.sep.join(API_lib_path)
print("API_lib_path: ", API_lib_path)
os.add_dll_directory(API_lib_path)  # <-- this tells Python where to find the API .dlls

import ProteusDSAPI # <-- this is importing the `ProteusDSAPI.<...>.pyd` extension (i.e., the bindings)


if __name__ == "__main__":
    # prep simulation variables
    dtime_s = 1/60          # time step [s] (i.e., 60 Hz "refresh rate")
    start_time_s = 0        # start time [s]
    time_s = start_time_s   # current time [s]
    end_time_s = 20         # end time [s]
    
    joint_damping_Nsm = 10000   # joint damping [N.s/m]
    joint_velocity_ms = 0       # joint velocity [m/s]
    joint_position_m = 0        # joint position [m]
    joint_force_N = 0           # joint force [N]
    
    joint_state_vec = np.zeros(2)    # need a size 2 vector to handle the joint velocity [m/s] and displacement [m]
    joint_force_vec = np.zeros(2)    # need a size 2 vector to handle the joint force [N] and dforce/dt [N/s]


    # init simulation
    assert(ProteusDSAPI.InitializeProteusDS("Sim1", "-i ./Inputs -o ./Results -overwrite on", False, True))
    ProteusDSAPI.AdvanceTime("Sim1", 0)
    print("Starting example case...\n")

    
    # retrieve and print DObject information (using Python wrappers on API Get functions)
    DObject_names_string = ProteusDSAPI.GetString("Sim1", ProteusDSAPI.PDSAPI.dObjectNames, "")
    DObject_types_string = ProteusDSAPI.GetString("Sim1", ProteusDSAPI.PDSAPI.dObjectTypes, "")
    
    DObject_names_list = DObject_names_string.split(",")[0:-1]
    DObject_types_list = DObject_types_string.split(",")[0:-1]
    n_objects = len(DObject_names_list)
    
    print("DObjects in the simulation are:")
    for i in range(0, n_objects):
        print("\t", DObject_types_list[i], "  ", DObject_names_list[i])
    
    print()
    
    
    # run simulation, print joint information
    while time_s < end_time_s:
        # get the joint state (infer from cylinder DObject state)
        # NOTE: The state vector for a prismatic joint ABA RigidBody consists of the joint velocity at index 0 followed by the joint position at index 1.
        joint_state_vec = ProteusDSAPI.GetDoubleArray(
            "Sim1",
            ProteusDSAPI.PDSAPI.state,
            "cylinder",
            2
        )
        
        joint_velocity_ms = joint_state_vec[0]
        joint_position_m = joint_state_vec[1]
        
        
        # compute joint force
        joint_force_N = -1 * joint_damping_Nsm * joint_velocity_ms
        joint_force_vec[0] = joint_force_N
        
        
        # apply joint force to cylinder DObject
        ProteusDSAPI.SetInt(
            "Sim1",
            ProteusDSAPI.PDSAPI.rigidBodyClearForcesMoments,
            "cylinder",
            1
        )   # clear the force accumulator (we can add multiple force components)
        
        ProteusDSAPI.SetDoubleArray(
            "Sim1",
            ProteusDSAPI.PDSAPI.rigidBodyJointForceAndDeriv,
            "cylinder",
            joint_force_vec
        )     # add joint damping to the force accumulator
        
        
        # print simulated joint information (rounded)
        print(
            "Time:",
            round(time_s, 3),
            " s\tJoint Position: ", 
            round(joint_position_m, 3),
            " m\tJoint Velocity: ",
            round(joint_velocity_ms, 3),
            " m/s\tJoint Reaction Force: ",
            round(joint_force_N),
            " N"
        )
        
        
        # advance simulation 
        ProteusDSAPI.AdvanceTime("Sim1", dtime_s);
        time_s += dtime_s


    # close simulation 
    ProteusDSAPI.Close("Sim1")
