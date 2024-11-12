
#FILE(WRITE ${CMAKE_BINARY_DIR}/sympack.mak "TEST" )
#FILE(GENERATE OUTPUT ${CMAKE_BINARY_DIR}/sympack.mak INPUT ${CMAKE_BINARY_DIR}/sympack.mak_at_configured )
file(STRINGS /home/william/sympack/symPACK/sympack.mak_at_generated configfile)
string(REPLACE "-I/home/william/sympack/symPACK" "" newconfigfile "${configfile}")
string(REPLACE "/home/william/sympack/symPACK" "\${SYMPACK_DIR}" newconfigfile "${newconfigfile}")
string(REGEX REPLACE "[;]+" "\n" newconfigfile "${newconfigfile}")
file(WRITE /usr/local/include/sympack.mak "${newconfigfile}")
