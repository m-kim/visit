# Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
# Project developers.  See the top-level LICENSE file for dates and other
# details.  No copyright assignment is required to contribute to VisIt.

#****************************************************************************
# Modifications:
#
#****************************************************************************

PYTHON_ADD_DISTUTILS_SETUP(visit_flow_vpe_py_setup
                           site-packages
                           setup.py
                           src/__init__.py
                           src/visit_flow_exec.vpe
                           src/visit_flow_vpe.py)





