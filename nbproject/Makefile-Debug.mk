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
CND_PLATFORM=GNU-Linux
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
	${OBJECTDIR}/_ext/eac693c4/CreateMenu.o \
	${OBJECTDIR}/_ext/eac693c4/clsConfig.o \
	${OBJECTDIR}/_ext/eac693c4/clsKeyboardTest.o \
	${OBJECTDIR}/_ext/eac693c4/cls_UniCodes.o \
	${OBJECTDIR}/_ext/eac693c4/getfd.o \
	${OBJECTDIR}/_ext/eac693c4/showkey-modified.o \
	${OBJECTDIR}/clsNewKeyboard.o \
	${OBJECTDIR}/getscancodes.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-lusb -g
CXXFLAGS=-lusb -g

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
	g++ -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/manualkbtest ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/eac693c4/CreateMenu.o: nbproject/Makefile-${CND_CONF}.mk /home/pi/ManualKBTest/CreateMenu.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/eac693c4
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/arm-linux-gnueabihf/ -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/eac693c4/CreateMenu.o /home/pi/ManualKBTest/CreateMenu.cpp

${OBJECTDIR}/_ext/eac693c4/clsConfig.o: nbproject/Makefile-${CND_CONF}.mk /home/pi/ManualKBTest/clsConfig.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/eac693c4
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/arm-linux-gnueabihf/ -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/eac693c4/clsConfig.o /home/pi/ManualKBTest/clsConfig.cpp

${OBJECTDIR}/_ext/eac693c4/clsKeyboardTest.o: nbproject/Makefile-${CND_CONF}.mk /home/pi/ManualKBTest/clsKeyboardTest.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/eac693c4
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/arm-linux-gnueabihf/ -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/eac693c4/clsKeyboardTest.o /home/pi/ManualKBTest/clsKeyboardTest.cpp

${OBJECTDIR}/_ext/eac693c4/cls_UniCodes.o: nbproject/Makefile-${CND_CONF}.mk /home/pi/ManualKBTest/cls_UniCodes.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/eac693c4
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/arm-linux-gnueabihf/ -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/eac693c4/cls_UniCodes.o /home/pi/ManualKBTest/cls_UniCodes.cpp

${OBJECTDIR}/_ext/eac693c4/getfd.o: nbproject/Makefile-${CND_CONF}.mk /home/pi/ManualKBTest/getfd.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/eac693c4
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/eac693c4/getfd.o /home/pi/ManualKBTest/getfd.c

${OBJECTDIR}/_ext/eac693c4/showkey-modified.o: nbproject/Makefile-${CND_CONF}.mk /home/pi/ManualKBTest/showkey-modified.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/eac693c4
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/eac693c4/showkey-modified.o /home/pi/ManualKBTest/showkey-modified.c

${OBJECTDIR}/clsNewKeyboard.o: nbproject/Makefile-${CND_CONF}.mk clsNewKeyboard.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/arm-linux-gnueabihf/ -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/clsNewKeyboard.o clsNewKeyboard.cpp

${OBJECTDIR}/getscancodes.o: nbproject/Makefile-${CND_CONF}.mk getscancodes.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/arm-linux-gnueabihf/ -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/getscancodes.o getscancodes.cpp

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/arm-linux-gnueabihf/ -lusb -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

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
