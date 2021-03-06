# Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
# Project developers.  See the top-level LICENSE file for dates and other
# details.  No copyright assignment is required to contribute to VisIt.

#****************************************************************************
# Modifications:
#   Kathleen Biagas, Thu March 7, 2019
#   Added sphinx_launcher (python executable) for Windows.
#
#****************************************************************************

INCLUDE(${VISIT_SOURCE_DIR}/CMake/FindSphinx.cmake)

if(NOT DEFINED SPHINX_THEME)
    set(SPHINX_THEME sphinx_rtd_theme)
endif()
 
if(NOT DEFINED SPHINX_THEME_DIR)
    set(SPHINX_THEME_DIR _themes)
endif()
 
# configured documentation tools and intermediate build results
#set(BINARY_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/_build")
 
# Sphinx cache with pickled ReST documents
#set(SPHINX_CACHE_DIR "${CMAKE_CURRENT_BINARY_DIR}/_doctrees")
 
# HTML output directory
set(SPHINX_HTML_DIR "${CMAKE_CURRENT_BINARY_DIR}/html")

if(WIN32)
    set(sphinx_launcher ${PYTHON_EXECUTABLE})
endif()

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/conf.py"
    "${CMAKE_CURRENT_BINARY_DIR}/conf.py"
    @ONLY)
 
add_custom_target(user_manuals ALL
    ${sphinx_launcher}
    ${SPHINX_EXECUTABLE}
        -a -q -b html
        "${CMAKE_CURRENT_SOURCE_DIR}"
        "${SPHINX_HTML_DIR}"
    COMMENT "Building Sphinx-HTML documentation for GUI and CLI")

if(WIN32)
    unset(sphinx_launcher)
endif()

