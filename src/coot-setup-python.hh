
#if defined (USE_PYTHON)
#include "Python.h"  // before system includes to stop "POSIX_C_SOURCE" redefined problems
#endif

#include <string>

#if defined (USE_PYTHON)
// #include "Python.h" // for Py_Initialize(); 20100813 included above now.
#define SWIG_init    init_coot
#if defined(_WIN32) || defined(__WIN32__)
#       if defined(_MSC_VER)
#               if defined(STATIC_LINKED)
#                       define SWIGEXPORT(a) a
#                       define SWIGIMPORT(a) extern a
#               else
#                       define SWIGEXPORT(a) __declspec(dllexport) a
#                       define SWIGIMPORT(a) extern a
#               endif
#       else
#               if defined(__BORLANDC__)
#                       define SWIGEXPORT(a) a _export
#                       define SWIGIMPORT(a) a _export
#               else
#                       define SWIGEXPORT(a) a
#                       define SWIGIMPORT(a) a
#               endif
#       endif
#else
#       define SWIGEXPORT(a) a
#       define SWIGIMPORT(a) a
#endif
extern "C" {
SWIGEXPORT(void) SWIG_init(void);
}
#endif

// 20220807-PE old style where both python and coot modules were loaded
// void setup_python(int argc, char **argv);

// 20220807-PE split python basic from cootenized python
void setup_python_basic(int argc, char **argv);

void setup_python_with_coot_modules(int argc, char **argv);

void setup_python_coot_module();

// which calls:
void try_load_dot_coot_py_and_python_scripts(const std::string &home_directory);
