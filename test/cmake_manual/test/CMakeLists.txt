add_executable( test.out test.c )

set_target_properties( test.out
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/test/bin"
)