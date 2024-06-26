//
// Created by thehepta on 2023/8/13.
//
#pragma once
#include <ostream>



enum ThreadState {
    //                                   Thread.State   JDWP state
    kTerminated = 66,                 // TERMINATED     TS_ZOMBIE    Thread.run has returned, but Thread* still around
    kRunnable,                        // RUNNABLE       TS_RUNNING   runnable
    kTimedWaiting,                    // TIMED_WAITING  TS_WAIT      in Object.wait() with a timeout
    kSleeping,                        // TIMED_WAITING  TS_SLEEPING  in Thread.sleep()
    kBlocked,                         // BLOCKED        TS_MONITOR   blocked on a monitor
    kWaiting,                         // WAITING        TS_WAIT      in Object.wait()
    kWaitingForGcToComplete,          // WAITING        TS_WAIT      blocked waiting for GC
    kWaitingForCheckPointsToRun,      // WAITING        TS_WAIT      GC waiting for checkpoints to run
    kWaitingPerformingGc,             // WAITING        TS_WAIT      performing GC
    kWaitingForDebuggerSend,          // WAITING        TS_WAIT      blocked waiting for events to be sent
    kWaitingForDebuggerToAttach,      // WAITING        TS_WAIT      blocked waiting for debugger to attach
    kWaitingInMainDebuggerLoop,       // WAITING        TS_WAIT      blocking/reading/processing debugger events
    kWaitingForDebuggerSuspension,    // WAITING        TS_WAIT      waiting for debugger suspend all
    kWaitingForJniOnLoad,             // WAITING        TS_WAIT      waiting for execution of dlopen and JNI on load code
    kWaitingForSignalCatcherOutput,   // WAITING        TS_WAIT      waiting for signal catcher IO to complete
    kWaitingInMainSignalCatcherLoop,  // WAITING        TS_WAIT      blocking/reading/processing signals
    kWaitingForDeoptimization,        // WAITING        TS_WAIT      waiting for deoptimization suspend all
    kWaitingForMethodTracingStart,    // WAITING        TS_WAIT      waiting for method tracing to start
    kWaitingForVisitObjects,          // WAITING        TS_WAIT      waiting for visiting objects
    kWaitingForGetObjectsAllocated,   // WAITING        TS_WAIT      waiting for getting the number of allocated objects
    kWaitingWeakGcRootRead,           // WAITING        TS_WAIT      waiting on the GC to read a weak root
    kWaitingForGcThreadFlip,          // WAITING        TS_WAIT      waiting on the GC thread flip (CC collector) to finish
    kStarting,                        // NEW            TS_WAIT      native thread started, not yet ready to run managed code
    kNative,                          // RUNNABLE       TS_RUNNING   running in a JNI native method
    kSuspended,                       // RUNNABLE       TS_RUNNING   suspended by GC or debugger
};
std::ostream& operator<<(std::ostream& os, const ThreadState& rhs);

