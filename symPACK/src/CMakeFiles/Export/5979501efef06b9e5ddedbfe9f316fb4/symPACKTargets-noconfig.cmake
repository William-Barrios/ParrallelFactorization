#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "symPACK::symPACK" for configuration ""
set_property(TARGET symPACK::symPACK APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(symPACK::symPACK PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX;Fortran"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libsympack.a"
  )

list(APPEND _cmake_import_check_targets symPACK::symPACK )
list(APPEND _cmake_import_check_files_for_symPACK::symPACK "${_IMPORT_PREFIX}/lib/libsympack.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
