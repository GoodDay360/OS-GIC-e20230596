/* winprocess.c — Process creation on Windows using CreateProcess() */
#include <stdio.h>
#include <windows.h>

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    const char *applicationPaths[] = {
        "C:\\Windows\\System32\\mspaint.exe",
        "C:\\Windows\\mspaint.exe"
    };
    BOOL childCreated = FALSE;
    DWORD createProcessError = ERROR_SUCCESS;

    /* Zero out the structures */
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    printf("Parent process (PID: %lu) — creating child...\n", GetCurrentProcessId());

    /*
     * CreateProcess() parameters:
     *   lpApplicationName  — Full path to the executable
     *   lpCommandLine      — Command line string (NULL if using lpApplicationName)
     *   ... other parameters set to defaults ...
     *   lpStartupInfo      — Pointer to STARTUPINFO
     *   lpProcessInformation — Receives the new process info
     *
     * Windows typically uses System32; Wine may install it at
     * "C:\\Windows\\mspaint.exe", so try that location as a fallback.
     *
     * If mspaint.exe is not at this path on your system, open Task Manager,
     * run mspaint manually, right-click the process, and select
     * "Open file location" to find the correct path.
     */
    for (size_t i = 0; i < sizeof(applicationPaths) / sizeof(applicationPaths[0]); i++) {
        childCreated = CreateProcess(
            applicationPaths[i], /* Application path */
            NULL,                 /* Command line */
            NULL,                 /* Process security attributes */
            NULL,                 /* Thread security attributes */
            FALSE,                /* Inherit handles */
            0,                    /* Creation flags */
            NULL,                 /* Environment */
            NULL,                 /* Current directory */
            &si,                  /* Startup info */
            &pi                   /* Process information */
        );
        if (childCreated) {
            break;
        }

        createProcessError = GetLastError();
        if (createProcessError != ERROR_FILE_NOT_FOUND &&
            createProcessError != ERROR_PATH_NOT_FOUND) {
            break;
        }
    }

    if (!childCreated) {
        fprintf(stderr, "CreateProcess failed for mspaint.exe (error %lu).\n",
                createProcessError);
        return 1;
    }

    printf("Child process created!\n");
    printf("  Child PID:       %lu\n", pi.dwProcessId);
    printf("  Child Thread ID: %lu\n", pi.dwThreadId);

    /*
     * Wait for the child process to finish.
     * mspaint will stay open — close it manually when you're done observing.
     * WaitForSingleObject blocks until the child terminates.
     */
    printf("Parent: waiting for child (mspaint) to exit...\n");
    printf(">>> Open Task Manager now and take a screenshot! <<<\n");
    printf(">>> Then close mspaint to let this program finish. <<<\n");

    WaitForSingleObject(pi.hProcess, INFINITE);

    printf("Parent: child has exited. Cleaning up.\n");

    /* Close process and thread handles */
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}