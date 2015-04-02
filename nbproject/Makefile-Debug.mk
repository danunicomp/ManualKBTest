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
	${OBJECTDIR}/_ext/356084796/CreateMenu.o \
	${OBJECTDIR}/_ext/356084796/GPIOClass.o \
	${OBJECTDIR}/_ext/356084796/clsBIOSTypeMenu.o \
	${OBJECTDIR}/_ext/356084796/clsConfig.o \
	${OBJECTDIR}/_ext/356084796/clsKeyboardDisplay.o \
	${OBJECTDIR}/_ext/356084796/clsKeyboardTUI.o \
	${OBJECTDIR}/_ext/356084796/clsKeyboardTest.o \
	${OBJECTDIR}/_ext/356084796/clsTUIKey.o \
	${OBJECTDIR}/_ext/356084796/cls_Menu.o \
	${OBJECTDIR}/_ext/356084796/cls_UniCodes.o \
	${OBJECTDIR}/_ext/356084796/getfd.o \
	${OBJECTDIR}/_ext/356084796/getscancodes.o \
	${OBJECTDIR}/_ext/356084796/showkey-modified.o \
	${OBJECTDIR}/clsNewKeyboard.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/sound.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-lusb -O2 -lncurses -lpanel
CXXFLAGS=-lusb -O2 -lncurses -lpanel

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

${OBJECTDIR}/_ext/356084796/CreateMenu.o: nbproject/Makefile-${CND_CONF}.mk /home/pi/ManualKBTest/CreateMenu.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/356084796
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/356084796/CreateMenu.o /home/pi/ManualKBTest/CreateMenu.cpp

${OBJECTDIR}/_ext/356084796/GPIOClass.o: nbproject/Makefile-${CND_CONF}.mk /home/pi/ManualKBTest/GPIOClass.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/356084796
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/356084796/GPIOClass.o /home/pi/ManualKBTest/GPIOClass.cpp

${OBJECTDIR}/_ext/356084796/clsBIOSTypeMenu.o: nbproject/Makefile-${CND_CONF}.mk /home/pi/ManualKBTest/clsBIOSTypeMenu.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/356084796
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/356084796/clsBIOSTypeMenu.o /home/pi/ManualKBTest/clsBIOSTypeMenu.cpp

${OBJECTDIR}/_ext/356084796/clsConfig.o: nbproject/Makefile-${CND_CONF}.mk /home/pi/ManualKBTest/clsConfig.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/356084796
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/356084796/clsConfig.o /home/pi/ManualKBTest/clsConfig.cpp

${OBJECTDIR}/_ext/356084796/clsKeyboardDisplay.o: nbproject/Makefile-${CND_CONF}.mk /home/pi/ManualKBTest/clsKeyboardDisplay.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/356084796
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/356084796/clsKeyboardDisplay.o /home/pi/ManualKBTest/clsKeyboardDisplay.cpp

${OBJECTDIR}/_ext/356084796/clsKeyboardTUI.o: nbproject/Makefile-${CND_CONF}.mk /home/pi/ManualKBTest/clsKeyboardTUI.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/356084796
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/356084796/clsKeyboardTUI.o /home/pi/ManualKBTest/clsKeyboardTUI.cpp

${OBJECTDIR}/_ext/356084796/clsKeyboardTest.o: nbproject/Makefile-${CND_CONF}.mk /home/pi/ManualKBTest/clsKeyboardTest.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/356084796
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/356084796/clsKeyboardTest.o /home/pi/ManualKBTest/clsKeyboardTest.cpp

${OBJECTDIR}/_ext/356084796/clsTUIKey.o: nbproject/Makefile-${CND_CONF}.mk /home/pi/ManualKBTest/clsTUIKey.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/356084796
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/356084796/clsTUIKey.o /home/pi/ManualKBTest/clsTUIKey.cpp

${OBJECTDIR}/_ext/356084796/cls_Menu.o: nbproject/Makefile-${CND_CONF}.mk /home/pi/ManualKBTest/cls_Menu.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/356084796
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/356084796/cls_Menu.o /home/pi/ManualKBTest/cls_Menu.cpp

${OBJECTDIR}/_ext/356084796/cls_UniCodes.o: nbproject/Makefile-${CND_CONF}.mk /home/pi/ManualKBTest/cls_UniCodes.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/356084796
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/356084796/cls_UniCodes.o /home/pi/ManualKBTest/cls_UniCodes.cpp

${OBJECTDIR}/_ext/356084796/getfd.o: nbproject/Makefile-${CND_CONF}.mk /home/pi/ManualKBTest/getfd.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/356084796
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/356084796/getfd.o /home/pi/ManualKBTest/getfd.c

${OBJECTDIR}/_ext/356084796/getscancodes.o: nbproject/Makefile-${CND_CONF}.mk /home/pi/ManualKBTest/getscancodes.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/356084796
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/356084796/getscancodes.o /home/pi/ManualKBTest/getscancodes.cpp

${OBJECTDIR}/_ext/356084796/showkey-modified.o: nbproject/Makefile-${CND_CONF}.mk /home/pi/ManualKBTest/showkey-modified.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/356084796
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/356084796/showkey-modified.o /home/pi/ManualKBTest/showkey-modified.c

${OBJECTDIR}/clsNewKeyboard.o: nbproject/Makefile-${CND_CONF}.mk clsNewKeyboard.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/clsNewKeyboard.o clsNewKeyboard.cpp

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++98 -lusb -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/sound.o: nbproject/Makefile-${CND_CONF}.mk sound.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sound.o sound.cpp

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
