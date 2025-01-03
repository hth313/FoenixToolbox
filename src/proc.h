/*
 * Routines to support processes
 *
 * NOTE: at the moment, FoenixMCP is single tasking only, so there is only
 *       one "process" besides the kernel.
 *
 */

#ifndef __PROC_H
#define __PROC_H

#include "sys_macros.h"

/*
 * Start a user mode process
 *
 * Inputs:
 * start = the address to start execution
 * stack = the location to start the user mode stack
 * argc = the number of parameters
 * argv = the array of parameters
 */
extern void proc_exec(long start, long stack, int argc, char * argv[]);

/*
 * Quit the current user process
 *
 * NOTE: at the moment, this relaunches the CLI. In the future, this
 *       may cause execution to return to the program that started
 *       the user process.
 *
 * Inputs:
 */
extern SYSTEMCALL void proc_exit(int result);

/**
 * @brief Set the address of the code that should handle a process exiting
 * 
 * By default, the address is 0, which means that the system should reboot when the process exits
 * If any other number is provided, the code at that location will be called as a far call using the
 * simplecall convention. The first argument will be the return result passed to proc_exit
 * 
 * @param address the address of the handler code for proc_exit
 */
extern SYSTEMCALL void proc_set_shell(uint32_t address);

/*
 * Return the result code of the previously running user process
 */
extern SYSTEMCALL int proc_get_result();

/*
 * Find an executable binary matching the path, load it, and execute it
 *
 * Inputs:
 * path = the path to try to load
 * argc = the number of parameters
 * argv = the array of parameters
 *
 * Returns:
 * returns an error code on failure, will not return on success
 */
extern SYSTEMCALL short proc_run(const char * path, int argc, char * argv[]);

#endif
