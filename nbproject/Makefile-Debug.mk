#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1543287360/getfd.o \
	${OBJECTDIR}/_ext/1543287360/showkey.o \
	${OBJECTDIR}/_ext/1543287360/showkeybuf.o \
	${OBJECTDIR}/beeptest.o \
	${OBJECTDIR}/clsNewKeyboard.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/readkeycodes.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/manualkbtest

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/manualkbtest: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/manualkbtest ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/1543287360/getfd.o: /root/NetBeansProjects/ManualKBTest/getfd.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1543287360
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1543287360/getfd.o /root/NetBeansProjects/ManualKBTest/getfd.c

${OBJECTDIR}/_ext/1543287360/showkey.o: /root/NetBeansProjects/ManualKBTest/showkey.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1543287360
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1543287360/showkey.o /root/NetBeansProjects/ManualKBTest/showkey.c

${OBJECTDIR}/_ext/1543287360/showkeybuf.o: /root/NetBeansProjects/ManualKBTest/showkeybuf.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1543287360
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1543287360/showkeybuf.o /root/NetBeansProjects/ManualKBTest/showkeybuf.c

${OBJECTDIR}/beeptest.o: beeptest.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/beeptest.o beeptest.cpp

${OBJECTDIR}/clsNewKeyboard.o: clsNewKeyboard.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/clsNewKeyboard.o clsNewKeyboard.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/readkeycodes.o: readkeycodes.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/readkeycodes.o readkeycodes.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/manualkbtest

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
